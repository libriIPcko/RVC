/* 
	driver.c
	
	Simple libftdi usage example
	
	This program is distributed under the GPL, version 2
*/
#include "debug.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ftdi.h>
#include "driver.h"

int usb_dev = 0;

#define USE_FTDI	1

#ifdef USE_FTDI
struct ftdi_context ftdic;
#endif


int init_adapter ( char * dev, int baud, unsigned long adr, unsigned long mask )
{
    unsigned char data[64];
    char cmd;
    int ret;

#ifndef USE_FTDI
    struct stat f;

    if ( ! dev )
    {
        printf ( "wrong dev!\n" );
        return -1;
    }
    dbg_msg(2, " -- open\n");
    if ( ( usb_dev = open ( dev,  O_RDWR) ) < 0 )
    {
        fprintf ( stderr, "unable to open device: %d\n", usb_dev );
        return -1;
    }
    memset(data, 0 , 64);
    cmd = 2;
    dbg_msg(2, " -- write\n");
    write_raw_data(1, 2, data);
    dbg_msg(2, " -- fstat\n");

    if ( ( usb_dev = fstat(usb_dev, &f) ) < 0 )
    {
        fprintf ( stderr, "unable to stat device: %d\n", usb_dev );
        return -1;
    }
    printf ("file info:\nuid %d\ngid %d\ndev_id %d\nsize %d\n",
            f.st_uid,     /* user ID of owner */
            f.st_gid,     /* group ID of owner */
            f.st_rdev,    /* device ID (if special file) */
            f.st_size);    /* total size, in bytes */



// prazdny cteni
    read_raw_data(64,&cmd,data);
    write_raw_data(1, 2, data);

    cmd = 2;
    write_raw_data(1, 2, data);



    //mon ( "rx", ret, mm );

    return 0;
#else

    if (ftdi_init(&ftdic) < 0)
    {
        fprintf(stderr, "ftdi_init failed\n");
        return EXIT_FAILURE;
    }

    if ((ret = ftdi_usb_open(&ftdic, 0x0403, 0x6001)) < 0)
    {
        fprintf(stderr, "unable to open ftdi device: %d (%s)\n", ret, ftdi_get_error_string(&ftdic));
        return EXIT_FAILURE;
    }
    if ((ret = ftdi_usb_reset(&ftdic)) < 0)
	{
		fprintf(stderr, "unable to reset ftdi rx buffers: %d (%s)\n", ret, ftdi_get_error_string(&ftdic));
		return EXIT_FAILURE;
	}
	
	if ((ret = ftdi_usb_purge_buffers(&ftdic)) < 0)
	{
		fprintf(stderr, "unable to purge ftdi rx buffers: %d (%s)\n", ret, ftdi_get_error_string(&ftdic));
		return EXIT_FAILURE;
	}
//	if ((ret = ftdi_usb_purge_tx_buffer(&ftdic)) < 0)
//	{
//		fprintf(stderr, "unable to purge ftdi tx buffers: %d (%s)\n", ret, ftdi_get_error_string(&ftdic));
//		return EXIT_FAILURE;
//	}

/*

-- Inicializace adaptéru --

Inicializace adaptéru USB2CAN dopracovního režimu vyžaduje tyto kroky:
1) Nastavit konfigura ní mód zasláním p íkazu CONFIG_MODE.
2) Nastavit Reset mód obvodu SJA1000 zápisem hodnoty 0x01 do registru Mode
(adresa 0). Použít p íkaz WRITE_REG.
3) Nastavit registr Clock divider na hodnotu 0xC0. Použít p íkaz WRITE_REG.
4) Nastavit filtry zpráv. Pokud nechceme filtrovat, je t eba nastavit registry
Acceptance code na 0x00 a Acceptance mask na 0xFF. Použít p íkaz WRITE_REG.
5) Nastavit registr Output control na hodnotu 0xDA. Použít p íkaz WRITE_REG.
6) Nastavit registr Interrupt enable na hodnotu 0x03. Použít p íkaz
WRITE_REG.
7) Nastavit registry Bus timing 0 a 1. Obvod SJA1000 má p ipojen krystal na
frekvenci 16MHz. Použít p íkaz WRITE_REG.
8) P íkazem COMMAND nastavit parametry
CMD_TRANSMIT_CRITICAL_LIMIT a CMD_TRANSMIT_READY_LIMIT.
9) Nastavit normal (opera ní) mód zasláním p íkazu NORMAL_MODE.
10) Nastavit registr Mode (adresa 0). Podle použití filtr zpráv, nastavit hodnotu
0x00 nebo 0x08. Použít p íkaz WRITE_REG.
Od tohoto okamžiku adaptér akceptuje zprávy s požadavkem na odeslání CAN
zprávy a zasílá zp t p ijaté CAN zprávy.
P i ukon ení práce s adaptérem doporu ujeme zaslat tuto sekvenci p íkaz :
1) Nastavit konfigura ní mód zasláním p íkazu CONFIG_MODE.
2) Nastavit Reset mód obvodu SJA1000 zápisem hodnoty 0x01 do registru Mode
(adresa 0). Použít p íkaz WRITE_REG.

*/

	memset(data, 0 , 64);
    write_raw_data(1, CONFIG_MODE, data);
// prazdny cteni, pac se tam po vetknuti motaj naky zmatky
    read_raw_data(64,&cmd, data);

	memset(data, 0 , 64);
	write_raw_data(1, CONFIG_MODE, data);
	read_raw_data(64,&cmd, data);
	
		
	memset(data, 0 , 64);
	write_raw_data(1, GET_MODE, data);
	read_raw_data(64,&cmd, data);
	
	if ((cmd != GET_MODE) && (data[0] != 0x01))
	{
		fprintf(stderr, "unable to initialize USB2CAN adapter\n");
		return EXIT_FAILURE;
	}
	memset(data, 0 , 64);
	write_raw_data(1, FW_VERSION, data);
	read_raw_data(64,&cmd, data);
	printf("adapter firmware revision: %s\n", data);
	
	write_reg(0, 1); // reset
	write_reg(31, 0xC0); // clock divider
	write_reg(16, 0); // acceptance code
	write_reg(17, 0);
	write_reg(18, 0);
	write_reg(19, 0);
	write_reg(20, 0xFF); //acceptance mask
	write_reg(21, 0xFF);
	write_reg(22, 0xFF);
	write_reg(23, 0xFF);
	write_reg(8, 0xDA); // output control
	write_reg(4, 0x03); // interupt enable
	
	/* 
	6.5.1
	BUS TIMING REGISTER 0 (BTR0)
	The contents of the bus timing register 0 defines the values of the Baud Rate Prescaler (BRP) and the Synchronization
	Jump Width (SJW). This register can be accessed (read/write) if the reset mode is active.
	In operating mode this register is read only, if the PeliCAN mode is selected. In BasicCAN mode a ‘FFH’ is reflected.
	Bit interpretation of bus timing register 0 (BTR0); CAN address 6
	
	BIT 7 	BIT 6	BIT 5	BIT 4	BIT 3	BIT 2	BIT 1	BIT 0
	SJW.1	SJW.0	BRP.5	BRP.4	BRP.3	BRP.2	BRP.1	BRP.0
	
	6.5.1.1
	Baud Rate Prescaler (BRP)
	The period of the CAN system clock tscl is programmable and determines the individual bit timing. The CAN system clock
	is calculated using the following equation:
	
	tscl = 2 × tCLK × (32 × BRP.5 + 16 × BRP.4 + 8 × BRP.3 + 4 × BRP.2 + 2 × BRP.1 + BRP.0 + 1)
	
	TODO : doplnit prepocet z baudrate na obsahy jednotlivych registru !!!
	
	dnes natvrdo 500kb/s
	
	*/
	
	
	write_reg(6, 0x40); // bus timing 0 (swj 0x01, prescaler 0x00)
	write_reg(7, 0x1C); // bud timing 1 (TSEG2 0x01, TSEG1=0x0C)
	
	/*
	nasledujici dva registry ovlivnuji lihnuti chyb 9
	soucasne hodnoty jich produkuji nejmene...
	*/
	
	// command CMD_TRANSMIT_CRITICAL_LIMIT
	data[0] = 0;
	data[1] = 15;
	write_raw_data(2, COMMAND, data);
	read_raw_data(64,&cmd, data);
	
	// command CMD_TRANSMIT_READY_LIMIT
	data[0] = 1;
	data[1] = 7;
	write_raw_data(2, COMMAND, data);
	read_raw_data(64,&cmd, data);
	
	memset(data, 0 , 64);
	// prepneme do normalniho modu
	write_raw_data(1, NORMAL_MODE, data);
	write_reg(0, 0x08); // uvolnime reset
	
	write_raw_data(1, GET_MODE, data);
	read_raw_data(64,&cmd, data);	
	
		
    return 0;
#endif

}

int close_adapter()
{
	int ret;
#ifndef USE_FTDI
    
    if ( usb_dev > 0 )
    {
        if ( ( ret = close ( usb_dev ) ) < 0 )
        {
            fprintf ( stderr, "unable to close device: %d\n", ret );
            return -1;
        }
    }
#else
	if ((ret = ftdi_usb_close(&ftdic)) < 0)
	{
		fprintf(stderr, "unable to close ftdi device: %d (%s)\n", ret, ftdi_get_error_string(&ftdic));
		return EXIT_FAILURE;
	}

	ftdi_deinit(&ftdic);
#endif
    return 0;
}


int write_raw_data ( int len, char cmd, unsigned char* data )
{
    int i, ret;
    unsigned char buff[64];

    if (len <= 0)
        return -1;
    memset(buff, 0, sizeof(buff));
    // doplnime uvodni informace
    buff[0]=0x0f;
    buff[1]=cmd;
	buff[2]=len & 0x1f;

    if (len > (sizeof(buff) - 3) )
        len = (sizeof(buff) - 3);

    for (i = 3; i<(len+3); i++)
        buff[i]=*data++;

#ifndef USE_FTDI
    if ( usb_dev > 0 )
    {
        if ( ( ret = write ( usb_dev, buff, len+3 ) ) < 0 )
        {
            fprintf ( stderr, "unable to write device: %d\n", ret );
            return -1;
        }
        mon_msg(2, "TX", ret, buff);
        return ret;
    }
    return -1;
#else
    if ((ret = ftdi_write_data(&ftdic, buff, len+3)) < 0)
    {
        fprintf(stderr, "unable to open ftdi device: %d (%s)\n", ret, ftdi_get_error_string(&ftdic));
        return EXIT_FAILURE;
    }
    mon_msg(2, "TX", ret, buff);
    return ret;
#endif
}

int read_raw_data ( int len, char *cmd, unsigned char* data )
{
    int ret;
    unsigned char buff[64];

    if (len <= 0)
        return -1;
    memset(buff, 0, sizeof(buff));

    if (len > (sizeof(buff) - 2) )
        len = (sizeof(buff) - 2);


#ifndef USE_FTDI
    if ( usb_dev > 0 )
    {

        if ( ( ret = read ( usb_dev, buff, len ) ) < 0 )
        {
            fprintf ( stderr, "unable to read device: %d\n", ret );
            return -1;
        }
        mon_msg(2, "RX", ret, buff);
        // mame validni odpoved
        if (buff[0] == 0x0f)
        {
            int i, rlen;
            *cmd = buff[1];
			rlen = buff[2];
            for (i = 3; i < (ret+3); i++)
                *data++ = buff[i];
            return ret;
        }
    }
    return -1;
#else
    if ((ret = ftdi_read_data(&ftdic, buff, len+2)) < 0)
    {
        fprintf(stderr, "unable to open ftdi device: %d (%s)\n", ret, ftdi_get_error_string(&ftdic));
        return EXIT_FAILURE;
    }
    mon_msg(2, "RX", ret, buff);
    // mame validni odpoved
    if (buff[0] == 0x0f)
    {
        int i;
        *cmd = buff[1]; // vratime prikaz, na ktery se reagovalo
        if  (ret - 3 != buff[2]) 	// zkontrolujeme delky vraceneho paketu
		{
			fprintf(stderr, "invalid packet length: real %d -> expected %d\n", ret, buff[2]);
			return EXIT_FAILURE;
		}
        for (i = 3; i < (ret+2); i++)
            *data++ = buff[i];
        return ret - 3;
    }
    return -1;

#endif
}

int write_reg(int adr, char data)
{
	int ret;
	char cmd;
	unsigned char wr_data[2];
	unsigned char rd_data[64];
	
	wr_data[0]=adr&0x7f;
	wr_data[1]=data;
	
	if ((ret = write_raw_data(2, WRITE_READ_REG, (unsigned char*)wr_data)) < 0)
	{
		fprintf(stderr, "write register failed: addr %d, data %d\n", adr, data);
		return EXIT_FAILURE;
	}
	usleep(50000); //pockame 50ms, aby se stihlo vse vyridit
	if ((ret = read_raw_data(64, &cmd, (unsigned char*)rd_data)) < 0)
	{
		fprintf(stderr, "read register failed: addr %d, data %d\n", adr, data);
		return EXIT_FAILURE;
	}
	if((cmd != WRITE_READ_REG) && (wr_data[1] != rd_data[1]))
	{
		fprintf(stderr, "r/w register failed: addr %d, data %d\n", adr, data);
		return EXIT_FAILURE;
	}
	
	return data;
	
}

int write_msg(int adr, unsigned char *data)
{
	int ret;
	
	if ((ret = write_raw_data(1, WRITE_MESSAGE, data)) < 0)
	{
		fprintf(stderr, "write message failed\n");
		return EXIT_FAILURE;
	}
	return ret;
	
}


