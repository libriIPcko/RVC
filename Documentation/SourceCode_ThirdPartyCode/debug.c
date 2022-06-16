/* 
	debug.c
	This program is distributed under the GPL, version 2
*/

#include <stdio.h>
//#include <ftdi.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>
#include <time.h>

#include "debug.h"


int debug_level = 2;


void mon_msg ( int lvl, const char* dir, int len, void * buf )
{
    int i;
    unsigned char c;
    unsigned char *p;
	if ( debug_level >= lvl )
	{
		struct timeval t;
		//struct time_t tm;
		gettimeofday(&t, NULL);
		
		printf ( "%li.%06li | %s | %02d | ", t.tv_sec, t.tv_usec, dir, len );
		p = buf;
		for ( i = len; i; i-- )
		{
			c = *p++;
			printf ( "%02x ", c );
		}
		printf ( "\n" );
	}
}


void dbg_msg ( int lvl, const char * fmt, ... )
{

    if ( debug_level >= lvl )
    {
        va_list argptr;
        int cnt;
        va_start ( argptr, fmt );
        cnt = vprintf ( fmt, argptr );
        va_end ( argptr );
    }
}
