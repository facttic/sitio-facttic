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
# Author: Suma Byrappa, Amarnath Chitumalla
#
#

__version__ = '1.0'
__title__ = 'AutoConfig Utility for Plug-in Installation'
__mod__ = 'hp-check-plugin'
__doc__ = "Auto config utility for HPLIP supported multifunction Devices for installing proprietary plug-ins."

# Std Lib
import sys
import os
import os.path
import getopt
import signal
import operator
import time

# Local
from base.g import *
from base import utils, device, tui, module, pkit
from installer import core_install


# Temp values for testing; May not be needed
username = ""
device_uri = ""
printer_name = ""
LOG_FILE = "/var/log/hp/hplip_ac.log" 
DBUS_SERVICE='com.hplip.StatusService'

##### METHODS #####

# Send dbus event to hpssd on dbus system bus
def send_message(device_uri, printer_name, event_code, username, job_id, title, pipe_name=''):
    log.debug("send_message() entered")
    args = [device_uri, printer_name, event_code, username, job_id, title, pipe_name]
    msg = lowlevel.SignalMessage('/', DBUS_SERVICE, 'Event')
    msg.append(signature='ssisiss', *args)

    SystemBus().send_message(msg)
    log.debug("send_message() returning")

# plugin installation
def install_Plugin(systray_running_status, run_directly=False):
    if run_directly:
        plugin = PLUGIN_REQUIRED 
        plugin_reason = PLUGIN_REASON_NONE
        ok, sudo_ok = pkit.run_plugin_command(plugin == PLUGIN_REQUIRED, plugin_reason)
        if not ok or not sudo_ok:
            log.error("Failed to install plug-in.")
    elif systray_running_status:
        send_message( device_uri,  printer_name, EVENT_AUTO_CONFIGURE, username, 0, "AutoConfig")
        log.debug("Event EVENT_AUTO_CONFIGURE sent to hp-systray to invoke hp-plugin")
    else:
        log.error("Run hp-systray manually and re-plugin printer")
        #TBD: needs to run hp-plugin in silent mode. or needs to show error UI to user.

     
#install Firmware after plugin installation completion.
def install_firmware(Plugin_Installation_Completed):

    #timeout check for plugin installation
    sleep_timeout = 6000	# 10 mins time out
    while Plugin_Installation_Completed is False and sleep_timeout != 0:
	time.sleep(0.3)	#0.3 sec delay
	sleep_timeout = sleep_timeout -3
	
	ps_plugin,output = utils.Is_Process_Running('hp-plugin')
	ps_diagnose_plugin,output = utils.Is_Process_Running('hp-diagnose_plugin')
 
        if ps_plugin is False and ps_diagnose_plugin is False:            
            Plugin_Installation_Completed = True
            if core.check_for_plugin() == PLUGIN_INSTALLED:
                break
            else:
                log.error("Failed to download firmware required files. manually run hp-plugin command in terminal fisrt")
                sys.exit(1)
    
    execmd="hp-firmware"
    options=""
    if usb_bus_id is not None and usb_device_id is not None:
	options += " -y3 %s:%s"%(usb_bus_id, usb_device_id)

    if log_level is 'debug':
        options += " -g"

    cmd= execmd + options
    log.info("Starting Firmware installation.")
    log.debug("Running command : %s " %cmd)
    Status, out=utils.run(cmd)

#    if Status == 0:
#        log.info("Installed firmware ")
#    else:
#        log.error("Failed to install firmware = %s" %Status)


#Usage details
USAGE = [(__doc__, "", "name", True),
         ("Usage: %s [MODE] [OPTIONS]" % __mod__, "", "summary", True),
         utils.USAGE_MODE,
         utils.USAGE_GUI_MODE,
         ("Run in interactive mode:", "-i or --interactive (For future use)", "option", False),
         utils.USAGE_OPTIONS,
         ("Install Plug-in through HP System Tray:", "-m (Default)", "option", False),
         ("Install Plug-in through hp-plugin:", "-p", "option", False),
         ("Download firmware into the device:", "-F", "option", False),
         ("Download firmware into the known device:", "-f bbb:ddd, where bbb is the USB bus ID and ddd is the USB device ID. The ':' and all leading zeroes must be present", "option", False),
         utils.USAGE_HELP,
         utils.USAGE_LOGGING1, utils.USAGE_LOGGING2, utils.USAGE_LOGGING3,
         utils.USAGE_NOTES,
         ("-m and -p options can't be used together. ","","note",False),
         ("-f and -F options can't be used together. ","","note",False)
        ]


def usage(typ='text'):
    if typ == 'text':
        utils.log_title(__title__, __version__)

    utils.format_text(USAGE, typ, __title__, __mod__, __version__)
    sys.exit(0)

##### MAIN #####


try:
    import dbus
    from dbus import SystemBus, lowlevel
except ImportError:
        log.error("hp-check-plugin Tool requires dBus and python-dbus")
        sys.exit(1)
try:
    opts, args = getopt.getopt(sys.argv[1:],'l:hHuUmMf:FpPgG',['gui','help', 'help-rest', 'help-man', 'help-desc','logging='])

except getopt.GetoptError, e:
        log.error(e.msg)
        usage()
        sys.exit(1)

if os.getenv("HPLIP_DEBUG"):
        log.set_level('debug')

log_level = 'info'
Systray_Msg_Enabled = False
Plugin_option_Enabled = False
Firmware_Option_Enabled = False
Firmware_GUI_Option_Enabled = False
GUI_Mode = True
Is_Plugin_Already_Installed = False
usb_bus_id=None
usb_device_id=None

for o, a in opts:
    if o in ('-h','-H', '--help'):
        usage()

    elif o == '--help-rest':
        usage('rest')

    elif o == '--help-man':
        usage('man')

    elif o in ('-u', '-U','--gui'):
        # currenlty only GUI mode is supported. hence not reading this option
        GUI_Mode = True

#    elif o in ('-i', '-I', '--interactive'):
#        #this is future use
#        GUI_Mode = False 

    elif o == '--help-desc':
        print __doc__,
        sys.exit(0)

    elif o in ('-l', '--logging'):
        log_level = a.lower().strip()

    elif o in('-g', '-G'):
        log_level = 'debug'

    elif o in ('-m', '-M'):
        Systray_Msg_Enabled = True
    
    elif o in ('-p', '-P'):
        Plugin_option_Enabled = True
 
    elif o== '-F':
        Firmware_GUI_Option_Enabled = True

    elif o =='-f':
	usb_bus_id, usb_device_id = a.split(":", 1)
        Firmware_Option_Enabled = True

if not log.set_level (log_level):
    usage()

LOG_FILE = os.path.normpath(LOG_FILE)
log.info(log.bold("Saving output in log file: %s" % LOG_FILE))
if os.path.exists(LOG_FILE):
    os.remove(LOG_FILE)

log.set_logfile(LOG_FILE)
log.set_where(log.LOG_TO_CONSOLE_AND_FILE)
cmd="chmod 774 "+LOG_FILE
sts,output = utils.run(cmd)
if sts != 0:
    log.warn("Failed to change log file permissions: %s" %output)

cmd="chgrp lp "+LOG_FILE
sts,output = utils.run(cmd)
if sts != 0:
    log.warn("Failed to change log file group permissions: %s" %output)

log.debug(" hp-check-plugin started")

if Plugin_option_Enabled and Systray_Msg_Enabled:
    log.error("Both -m and -p options can't be used together.")
    usage()
    sys.exit(1)

if Firmware_GUI_Option_Enabled and Firmware_Option_Enabled:
    log.error("Both -f and -F options can't be used together.")
    usage()
    sys.exit(1)

if Firmware_GUI_Option_Enabled:
    Firmware_Option_Enabled =True	# Firmware_GUI_Option_Enabled is just to check both -f: and -F enabled or not

if not Plugin_option_Enabled:
    Systray_Msg_Enabled = True

# checking whether HP-systray is running or not. Invokes, if systray is not running
status,output = utils.Is_Process_Running('hp-systray')
if status is False:
    Systray_Is_Running=False
    log.info("hp-systray is not running.")
    if os.getuid() == 0:
        log.error(" hp-systray must be running.\n Run \'hp-systray &\' in a terminal. ")
    else:
        log.info("Starting hp-systray service")
        child_pid = os.fork()
        if child_pid == 0:
            Systray_Is_Running=True
            status,output =utils.run('hp-systray &', True, None, 1, False)
            if status is not 0:
                log.error("Failed to start \'hp-systray\' service. Manually run \'hp-sysray &\' from terminal as non-root user.")
                Systray_Is_Running=False
	    
            sys.exit()
        else:
            Systray_Is_Running=True
            time.sleep(2)
else:
    Systray_Is_Running=True
    log.info("hp-systray service is running\n")

core = core_install.CoreInstall()
core.set_plugin_version()
plugin_sts = core.check_for_plugin()
if plugin_sts == PLUGIN_INSTALLED:
    log.info("Device Plugin is already installed")
    Is_Plugin_Already_Installed = True
elif plugin_sts == PLUGIN_VERSION_MISMATCH:
    log.info("HP Device Plug-in version mismatch or some files are corrupted")
else:
    log.info("HP Device Plug-in is not found.")

if Systray_Msg_Enabled:
    if not Is_Plugin_Already_Installed:
        install_Plugin( Systray_Is_Running)

elif Plugin_option_Enabled:
    if not Is_Plugin_Already_Installed:
        install_Plugin (Systray_Is_Running, True)		# needs to run hp-plugin without usig systray

if Firmware_Option_Enabled:
    if Is_Plugin_Already_Installed is False:
        Plugin_Installation_Completed = False
    else:
        Plugin_Installation_Completed = True

    install_firmware(Plugin_Installation_Completed)  

log.info()
log.info("Done.")
