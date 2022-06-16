#ifndef DRIVER_H
#define DRIVER_H

enum
{
    USE_LOOPBACK = 0,
    BOOT_MODE,
    CONFIG_MODE,
    NORMAL_MODE,
    LOOPBACK_MODE,
    GET_MODE = 6,
    BUS_OFF = 8,
    ERROR,
    READ_REG = 16,
    READ_REG_BLOCK,
    WRITE_REG,
    WRITE_REG_BLOCK,
    WRITE_READ_REG,
    BITMOD_REG,
    BITMOD_READ_REG,
    COMMAND = 32,
    FW_VERSION,
    TIMESTAMP = 62,
    READ_MESSAGE_TS,
    WRITE_MESSAGE,
    READ_MESSAGE,
    WRITE_SYNC_MESSAGE,
    READ_SYNC_MESSAGE,
    SEND_SYNC_MESSAGE,
    DISABLE_SYNC_MESSAGE,
    DISABLE_ALL_SYNC,
    ENABLE_SYNC_MESSAGE,
    SET_PERIOD_SYNC_MESSAGE,
    SUPPORTED_SYNC_MESSAGE,
    READ_TEC = 96,
    READ_REC,
    READ_RST,
    WRITE_INSTRUCTION = 127
} COMMANDS;



int read_raw_data ( int len, char *cmd, unsigned char* data );
int write_raw_data ( int len, char cmd, unsigned char* data );
int close_adapter();
int init_adapter ( char * dev, int baud, unsigned long adr, unsigned long mask );
int write_reg(int adr, char data);
char read_reg(int adr);


#endif
