/*****************************************************************************\
    hppsfilter.c : HP PS filter for PostScript printers

    Copyright (c) 2011, Hewlett-Packard Co.
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the Hewlett-Packard nor the names of its
       contributors may be used to endorse or promote products derived
       from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
    OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
    IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
    NOT LIMITED TO, PATENT INFRINGEMENT; PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
    IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
 
   Author: Yashwant Kumar Sahu
\*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <cups/cups.h>
#include <cups/ppd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PJL_HEADER "\x1B%-12345X@PJL\x0A"
#define BOD_PJL_FIXED "0400040101020D10100115"
#define BOD_PPD_ATR "HPBOD"
#define BOD_PJL "@PJL DMINFO ASCIIHEX=\"%s%s\"\012"
#define BOD_DATETIME_FORMAT "%04d%02d%02d%02d%02d%02d"
#define DBG_PSFILE "/tmp/hpps_job%d.out"

#define LINE_SIZE  258
#define FILE_NAME_SIZE 128

#define SAVE_PS_FILE      2

/*  save final output ps file: in cupsd.conf file  value #hpLogLevel 15  */
static int g_savepsfile = 0;

/*  final ps outfile file handle */
static FILE *g_fp_outdbgps = NULL;

/* get log level from the cups config file */
void get_LogLevel ()
{
    FILE    *fp;
    char    str[258];
    char    *p;
    fp = fopen ("/etc/cups/cupsd.conf", "r");
    if (fp == NULL)
        return;
    while (!feof (fp))
    {
        if (!fgets (str, 256, fp))
        {
            break;
        }
        if ((p = strstr (str, "hpLogLevel")))
        {
            p += strlen ("hpLogLevel") + 1;
            g_savepsfile = atoi (p);
            break;
        }
    }
    fclose (fp);
}

 
/* create ps file for debugging purpose using job id */
void open_dbg_outfile(char* szjob_id)
{
    g_fp_outdbgps = NULL;
    if (g_savepsfile & SAVE_PS_FILE)
    {
        char    sfile_name[FILE_NAME_SIZE] = {0};
        sprintf(sfile_name, DBG_PSFILE, szjob_id);
        g_fp_outdbgps= fopen(sfile_name, "w");
        chmod(sfile_name, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    }
}

/* Writting into out file and debug file if debug level is set to 15 */
int hpwrite (void *pBuffer, size_t size)
{
	int ndata_written = 0;
	if(g_fp_outdbgps)
	{
		ndata_written = fwrite (pBuffer, 1, size, g_fp_outdbgps);
	}
	
	ndata_written = write (STDOUT_FILENO, pBuffer, size);
	return ndata_written;
}

/* Read HPBOD attribute from PPD 
 return 1 if set as 1 */
int require_bod()
{
    int bodRequire = 0;
    ppd_attr_t  *pattr = NULL;
    ppd_file_t  *pppd = NULL;	
    pppd = ppdOpenFile(getenv("PPD"));
    if (pppd == NULL) {
        fprintf (stderr, "HP PS : ppdOpenFile failed for %s\n", getenv("PPD"));		
        return 0;
    }
	
    if (((pattr = ppdFindAttr(pppd, BOD_PPD_ATR, NULL)) != NULL) &&
        (pattr && pattr->value != NULL)) {
        bodRequire = atoi(pattr->value);
    }
    return bodRequire;
}

/* Write BOD PJL command DMINFO */
void emmit_bod_command()
{
	struct    tm   *tgmt = NULL;
	time_t    long_time;
	char sBOD[100] = {0};
    char sBOD_Var[29] = {0};
    char sDateTime[15] = {0};
	int index = 0;
	
	time(&long_time);
	tgmt = gmtime(&long_time);
			
    sprintf(sDateTime, BOD_DATETIME_FORMAT, (tgmt->tm_year + 1900),
         (tgmt->tm_mon + 1), tgmt->tm_mday, tgmt->tm_hour, tgmt->tm_min, tgmt->tm_sec);
	
    for (index = 0; index < (sizeof(sDateTime) -1); index++)
    {
        sprintf( sBOD_Var + (index*2), "%2X", sDateTime[index ]);
    }
		
	sprintf(sBOD, BOD_PJL, BOD_PJL_FIXED, sBOD_Var);
	fprintf (stderr, "HP PS filter sending BOD PJL:  - %s\n", sBOD);
	hpwrite (sBOD, strlen (sBOD));
}

int main (int argc, char **argv)
{
	cups_file_t	*fp_input =  NULL;			/* input file: stdin or physical file */	
    char   line[LINE_SIZE] = {0};
	
	get_LogLevel();
	setbuf (stderr, NULL);
	fprintf (stderr, "HP PS filter starting : %s \n", *argv);
	
	int i =  0;
	/* Logging cups filter arguments */
	for (   i = 0; i < argc; i++)
	{
		fprintf (stderr, "DEBUG: hppsfilter: argv[%d] = %s\n", i, argv[i]);
	}
	
	/* Logging debug information and creating outfile for debug */
	if (g_savepsfile & SAVE_PS_FILE)
	{
		/* opening ps debug file */
		open_dbg_outfile(argv[1]);
	}
	
	/* Check command-line...  */
	if (argc < 6 || argc > 7)
	{
		fputs("ERROR: hppsfilter job-id user title copies options [file]\n", stderr);
		return (1);
	}

	/* If we have 7 arguments, print the file named on the command-line.
	* Otherwise, send stdin instead...  */
	if (argc == 6)
		fp_input = cupsFileStdin();
	else
	{
		/* Try to open the print file...    */
		if ((fp_input = cupsFileOpen(argv[6], "r")) == NULL)
		{
  			fprintf(stderr, "ERROR: Unable to open print file \"%s\" - %s\n",
              argv[6], strerror);
  			return (1);
		}
	}

	int len  =  0;
	int ibodwritten = 0;
	int ireqire_bod = require_bod();
    while ( ( len = cupsFileGetLine(fp_input, line, sizeof(line) )) > 0)
    {
		hpwrite (line, len);
		/* if BOD is reqire, writting BOD command */
		if ( !ibodwritten && (!strncmp(line, "@PJL JOB NAME", 13)) && ireqire_bod)
		{
			fprintf (stderr, "HP PS filter: Matched start PJL\n");				
			ibodwritten = 1;
			emmit_bod_command();
		}
    }

    if ( (argc == 7) && (fp_input != NULL) )
        cupsFileClose (fp_input);
	
	if(g_fp_outdbgps != NULL)
	{
	    fclose (g_fp_outdbgps);		
	}
			   
	fprintf (stderr, "HP PS filter Ends\n");	
    return 0;
}
