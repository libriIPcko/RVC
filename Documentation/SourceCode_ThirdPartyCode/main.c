/* 
	main.c
	This program is distributed under the GPL, version 2
*/

#include <stdio.h>
#include <stdlib.h>
//#include <ftdi.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "debug.h"
#include "driver.h"



int main ( void )
{
    int ret;
    char cmd;

    unsigned char mm[64];

    memset ( mm, 0, sizeof ( mm ) );

    if ( init_adapter ( "/dev/ttyUSB0", 500000, 0, 0 ) != 0 )
    {
        //fprintf ( stderr, "unable to open device\n" );
		return EXIT_FAILURE;
    }
#if 0

    if ( ( ret = write_raw_data ( 1, 0x06, mm ) ) < 0 )
    {
        fprintf ( stderr, "unable to write device: %d\n", ret );
        return -1;
    }

    if ( ( ret = read_raw_data ( 16, &cmd, mm ) ) < 0 )
    {
        fprintf ( stderr, "unable to read device: %d\n", ret );
        return -1;
    }

    //mon("rx", ret, mm);
#endif
	debug_level=0;
	while(1)
	{
		int len;
		len = read_raw_data(64, &cmd, mm);
		if (len >0)
			mon_msg(0, "RD", len, mm);
	}
    if ( ( ret = close_adapter() ) < 0 )
    {
        fprintf ( stderr, "unable to close device: %d\n", ret );
        return -1;
    }


    return 0;
}
