#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# (c) Copyright 2011-2014 Hewlett-Packard Development Company, L.P.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# Author: Amarnath Chitumalla
#

__version__ = '1.0'
__title__ = 'AutoConfig Utility to check queues configuration'
__mod__ = 'hp-daignose-queues'
__doc__ = """Auto config utility for HPLIP supported multifunction Devices to diagnose queues configuration."""

# Std Lib
import sys
import os
import getopt
import commands
import re

# Local
from base.g import *
from base import utils, tui, models
from prnt import cups
from installer import core_install

# ppd type
HPCUPS = 1
HPIJS = 2
HPPS = 3
HPOTHER = 4

DEVICE_URI_PATTERN = re.compile(r"""(.*):/(.*?)/(\S*?)\?(?:serial=(\S*)|device=(\S*)|ip=(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}[^&]*)|zc=(\S+))(?:&port=(\d))?""", re.I)
NICKNAME_PATTERN = re.compile(r'''\*NickName:\s*\"(.*)"''', re.MULTILINE)
NET_PATTERN = re.compile(r"""(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})""")
NET_ZC_PATTERN = re.compile(r'''zc=(.*)''',re.IGNORECASE)
NET_OTHER_PATTERN = re.compile(r'''(.*)://(.*)''',re.IGNORECASE)
USB_PATTERN = re.compile(r'''serial=(.*)''',re.IGNORECASE)
LPSTAT_PATTERN = re.compile(r"""(\S*): (.*)""", re.IGNORECASE)
#BACK_END_PATTERN = re.compile(r'''(.*):(.*)''',re.IGNORECASE)

##### METHODS #####

def usage(typ='text'):
    if typ == 'text':
        utils.log_title(__title__, __version__)
    utils.format_text(USAGE, typ, __title__, __mod__, __version__)
    sys.exit(0)


# Checks 'lp' group is added o not
def check_user_groups():
    result = False
    sts,output = utils.run('groups')
    if sts != 0:
        log.error("Failed to get groups")
    else:
        output = output.rstrip('\r\n')
        log.debug("groups =%s "%output)
        grp_list= output.split(' ')
        cnt = 0
        while cnt < len(grp_list) :
            if grp_list[cnt] == 'lp':
                result = True
                break
            cnt += 1
            
    return result

# This function adds the groups ('lp') to user 
def add_group(core):
    result = False
    add_user_to_group = core.get_distro_ver_data('add_user_to_group', '')
    if add_user_to_group:
        usermod = os.path.join(utils.which("usermod"), "usermod") + " %s %s" % (add_user_to_group, prop.username)
    else:
        usermod = os.path.join(utils.which("usermod"), "usermod") + " %s %s" % ("-Glp", prop.username)

    su_sudo = utils.su_sudo()
    password_f = None
    if su_sudo is "su":
        name,version,is_su = utils.os_release()
        log.debug("name = %s version = %s is_su = %s" %(name,version,is_su))
        if ( name == 'Fedora' and version >= '14' and is_su == True):
           #using su opening GUI apps fail in Fedora 14. 
           #To run GUI apps as root, you need a root login shell (su -) in Fedora 14   
           su_sudo = 'su - -c "%s"'
        else:
           su_sudo = 'su -c "%s"'

        password_f = "get_password_ui"
#        password_f = utils.get_password
    cmd =su_sudo % usermod
    log.info("cmd = %s" %cmd)
#    sts, output = utils.run(cmd, True, password_f, -1,True,cmd)  
    sts, output = utils.run(cmd, True, password_f, 1, True, "Please enter root/superuser password to add 'lp' group")
    if sts == 0:
        result = True
        
    return result


# This parse the given Device URI. and provides the details.
def parseDeviceURI(device_uri):
    m = DEVICE_URI_PATTERN.match(device_uri)
    if m is None:
        raise Error(ERROR_INVALID_DEVICE_URI)

    back_end = m.group(1).lower() or ''
    is_hp = (back_end in ('hp', 'hpfax', 'hpaio'))
    bus = m.group(2).lower() or ''

    if bus not in ('usb', 'net', 'bt', 'fw', 'par'):
        raise Error(ERROR_INVALID_DEVICE_URI)

    model =m.group(3) or ''
    serial = m.group(4) or ''
    dev_file = m.group(5) or ''
    host = m.group(6) or ''
    zc = ''
    if not host:
        zc = host = m.group(7) or ''
    port = m.group(8) or 1

    if bus == 'net':
        try:
            port = int(port)
        except (ValueError, TypeError):
            port = 1

        if port == 0:
            port = 1

#    log.warning("++++: back_end '%s' is_hp '%s' bus '%s' model '%s' serial '%s' dev_file '%s' host '%s' zc '%s' port '%s' " %
#       ( back_end, is_hp, bus, model, serial, dev_file, host, zc, port))

    return back_end, is_hp, bus, model, serial, dev_file, host, zc, port


####### Device class ########
class DetectedDevice:
    def __init__(self, Printer_Name,Device_URI,Device_Type, ppdType, PPDFileError = False, IsEnabled=True ):
        self.PrinterName =Printer_Name
        self.DeviceURI = Device_URI
        self.DeviceType = Device_Type
        self.PPDFileType = ppdType
        self.PPDFileError = PPDFileError
        self.IsEnabled = IsEnabled




#########Main##########
USAGE = [(__doc__, "", "name", True),
         ("Usage: %s [OPTIONS]" % __mod__, "", "summary", True),
         utils.USAGE_OPTIONS,
         utils.USAGE_LOGGING1, utils.USAGE_LOGGING2, utils.USAGE_LOGGING3,
         utils.USAGE_HELP,
        ]

try:
    log.set_module(__mod__)

    try:
        opts, args = getopt.getopt(sys.argv[1:],  'hl:gsr',  ['help', 'help-rest', 'help-man', 'help-desc', 'logging='])

    except getopt.GetoptError, e:
        log.error(e.msg)
        usage()
        sys.exit(1)

    if os.getenv("HPLIP_DEBUG"):
        log.set_level('debug')

    log_level = 'info'
    Show_result=False
    quiet_mode = False
    for o, a in opts:
        if o in ('-h', '--help'):
            usage()

        elif o == '--help-rest':
            usage('rest')

        elif o == '--help-man':
            usage('man')

        elif o == '--help-desc':
            print __doc__,
            sys.exit(0)

        elif o in ('-l', '--logging'):
            log_level = a.lower().strip()

        elif o == '-g':
            log_level = 'debug'

        elif o == '-r':
            Show_result = True

        elif o == '-s':
            quiet_mode = True

    if not log.set_level(log_level):
        usage()
    if not quiet_mode:
        utils.log_title(__title__, __version__)

    log_file = os.path.normpath('/var/loh/hp/hplip_queues.log')
    log.debug(log.bold("Saving output in log file: %s" % log_file))
    if os.path.exists(log_file):
        os.remove(log_file)
    log.set_logfile(log_file)
    log.set_where(log.LOG_TO_CONSOLE_AND_FILE)
    
    try:
        from base import device, pml
        # This can fail due to hpmudext not being present
    except ImportError:
        log.error("Device library is not avail.")
        sys.exit(1)

    # Only Qt4 is supported.
    try:
        from PyQt4.QtGui import QApplication, QMessageBox
        from ui4.queuesconf import QueuesDiagnose
    except ImportError:
        log.error("Unable to load Qt4 support. Is it installed?")
        sys.exit(1)

    app = QApplication(sys.argv)
    Error_Found = False
    if check_user_groups() is False:
        dialog = QueuesDiagnose(None, "","",QUEUES_MSG_SENDING)
        core = core_install.CoreInstall()
        core.init()
        if add_group(core) is False:
            Error_Found = True
            #log.error("Failed to add lp group to user[%s]. Manually add 'lp' group to usergroups"%prop.username)
            dialog.showMessage("User must be part of 'lp' group.\nManually add 'lp' group to '%s' user. " %prop.username)
        else:
            dialog.showSuccessMessage("Groups added successfully and reboot is required. Please reboot system to take effect.")


    is_hpcups_installed = to_bool(sys_conf.get('configure', 'hpcups-install', '0'))
    is_hpijs_installed = to_bool(sys_conf.get('configure', 'hpijs-install', '0'))
#    tui.header("INSTALLED CUPS PRINTER QUEUES")

    
    status, output = utils.run('lpstat -v')

    cups_printers = []
    for p in output.splitlines():
        try:
            match = LPSTAT_PATTERN.search(p)
            printer_name = match.group(1)
            device_uri = match.group(2)
            cups_printers.append((printer_name, device_uri))
        except AttributeError:
            pass

    log.debug(cups_printers)
    log.debug("HPCups installation=%d  HPIJS installation =%d" %(is_hpcups_installed, is_hpijs_installed))
    if cups_printers:
        mapofDevices={}

        for p in cups_printers:
            printer_name, device_uri = p

            if device_uri.startswith("cups-pdf:/"):
                continue

            log.debug(log.bold(printer_name))
            log.debug(log.bold('-'*len(printer_name)))

            try:
                back_end, is_hp, bus, model, serial, dev_file, host, zc, port = parseDeviceURI(device_uri)
            except Error:
                back_end, is_hp, bus, model, serial, dev_file, host, zc, port = '', False, '', '', '', '', '', '', 1
                if 'HP' in device_uri:
                    is_hp = True

            log.debug("Device URI: %s" % device_uri)
            ppd_file = os.path.join('/etc/cups/ppd', printer_name + '.ppd')
            if os.path.exists(ppd_file):
                log.debug("PPD: %s" % ppd_file)

                fileptr = file(ppd_file, 'r').read(4096)
                try:
                    desc = NICKNAME_PATTERN.search(fileptr).group(1)
                except AttributeError:
                    desc = ''

                log.debug("PPD Description: %s" % desc)
                status, output = utils.run('lpstat -p%s' % printer_name)
                log.debug("Printer status: %s" % output.replace("\n", ""))

                #### checking for USb devices ####
                if USB_PATTERN.search(device_uri):                   
                    Key =USB_PATTERN.search(device_uri).group(1)
                #### checking for network devices ####
                elif NET_PATTERN.search(device_uri):
                    Key = NET_PATTERN.search(device_uri).group(1)
                elif NET_ZC_PATTERN.search(device_uri):
                    Key = NET_ZC_PATTERN.search(device_uri).group(1)
                elif NET_OTHER_PATTERN.search(device_uri):
                    part_1 = NET_OTHER_PATTERN.search(device_uri).group(1)
                    part_2 = NET_OTHER_PATTERN.search(device_uri).group(2)
                    if 'HP' in part_2:
                        Key = part_2
                    else:
                        log.info("unknown protocol device_uri=%s" %device_uri)
                        Key=None
                else:
                    log.info("unknown protocol device_uri=%s" %device_uri)
                    Key=None

                if Key is not None:
                    Is_Print_Q_Enabled= True
                    if output.find('Paused') !=  -1:
                        Is_Print_Q_Enabled= False
                    Key=Key+"_"+back_end
                    log.debug("Key'%s': deviceType '%s' is_hp '%s' bus '%s' model '%s' serial '%s' dev_file '%s' host '%s' zc '%s' port '%s' Enabled'%d'"\
                                               %( Key,back_end, is_hp, bus, model, serial, dev_file, host, zc, port,Is_Print_Q_Enabled))

                    PPDFileError = False
                    if back_end == 'hpfax' and not 'HP Fax' in desc:
                        log.error("Incorrect PPD file for fax queue '%s'. Fax queue must use 'HP-Fax-hplip.ppd'." % printer_name)
                        PPDFileError = True
                    elif back_end == 'hp' and 'HP Fax' in desc:
                        log.error("Incorrect PPD file for print queue '%s'. Print queue must not use 'HP-Fax-hplip.ppd'." % printer_name)
                        PPDFileError = True
                    elif back_end not in ('hp', 'hpfax'):
                        log.warn("Device %s is not HPLIP installed. Device must use the hp: or hpfax: to function in HPLIP."% printer_name)

                    ppd_fileType = None
                    if 'hpcups' in desc:
                        ppd_fileType = HPCUPS
                        if not is_hpcups_installed:
                            PPDFileError = True
                    elif 'hpijs' in desc:
                        ppd_fileType = HPIJS
                        if not is_hpijs_installed:
                            PPDFileError = True
                    elif 'Postscript' in desc:
                        ppd_fileType =HPPS
                    elif is_hp:
                        ppd_fileType =HPOTHER
                        PPDFileError = True

                    if ppd_fileType != None:
                        device1 =DetectedDevice(printer_name, device_uri,back_end, ppd_fileType,PPDFileError, Is_Print_Q_Enabled)
                        if Key in mapofDevices:
                            mapofDevices[Key].append(device1)
                        else:
                            deviceList=[device1]
                            mapofDevices[Key]=deviceList
                    else:
                        log.warn("%s is not HP Device." %(printer_name))

        for key,val in mapofDevices.items():
            if len(val) >1:
                log.debug("")
                log.warn('%d queues of same device %s is configured.  Remove unwanted queues.' %(len(val),val[0].PrinterName))
                if Show_result:
                    Error_Found = True
                    dialog = QueuesDiagnose(None, "","",QUEUES_MSG_SENDING)
                    dialog.showMessage("%d queues of same device %s is configured.\nRemove unwanted queues."%(len(val),val[0].PrinterName))
                 
                for que in val:
                    Error_msg =None
                    if 'hp' in que.DeviceType or 'hpfax' in que.DeviceType:
                        if que.PPDFileError ==  False:
                            log.debug("'%s' is configured correctly." %(que.PrinterName))
                        else:
                            log.error("PPD file for '%s' is not correct. Need to choose correct PPD file." %(que.PrinterName))
                            Error_msg = QUEUES_INCORRECT_PPD
                    else:
                        log.error("'%s' is not configured using HPLIP. Need to remove and re-cofigure from hp-setup." %(que.PrinterName))
                        Error_msg =QUEUES_CONFIG_ERROR

                    if Error_msg ==None and que.IsEnabled == False:
                        Error_msg = QUEUES_PAUSED

                    if Error_msg != None:
                        Error_Found = True
                        dialog = QueuesDiagnose(None, que.PrinterName,que.DeviceURI,Error_msg)
                        dialog.show()
                        log.debug("Starting GUI loop...")
                        app.exec_()
            else:
                Error_msg =None
                log.debug("")
                log.debug("Single print queue is configured for '%s'. " %val[0].PrinterName)
                if 'hp' in val[0].DeviceType or 'hpfax' in val[0].DeviceType:
                    if val[0].PPDFileError == False:
                        log.debug("'%s' is configured correctly." %(val[0].PrinterName))
                    else:
                        log.error("PPD file for '%s' is not correct. Need to choose correct PPD file." %(val[0].PrinterName))
                        Error_msg = QUEUES_INCORRECT_PPD
                else:
                    log.error("'%s' is not configured using HPLIP. Need to remove and re-configure using hp-setup." %(val[0].PrinterName))
                    Error_msg = QUEUES_CONFIG_ERROR

                if Error_msg ==None and val[0].IsEnabled == False:
                    Error_msg = QUEUES_PAUSED

                if Error_msg != None:
                    Error_Found = True
                    name = val[0].PrinterName
                    dialog = QueuesDiagnose(None, name, val[0].DeviceURI, Error_msg)
                    dialog.show()
                    log.debug("Starting GUI loop...")
                    app.exec_()
    else:
        log.debug("No queues found.")
   
    if Show_result and (Error_Found is False):
        dialog = QueuesDiagnose(None, "","",QUEUES_MSG_SENDING)
        dialog.showSuccessMessage("Queue(s) configured correctly using HPLIP.")
       

except KeyboardInterrupt:
    log.error("User exit")

log.debug("Done.")
