#ifndef USB2CAN_DEFINE_H
#define USB2CAN_DEFINE_H

#endif // USB2CAN_DEFINE_H

#include "QString"
/*
0f0200
0f12020001
0f12021FC0
0f12021000
0f120214ff
0f120208DA
0f12020403
0f12020600
0f12020714
0f200118
0f200201
0f0300
0f12020000
*/


static const char Config[] =        {'\x0f',    '\x02', '\x00'                         };
static const char ResetMod[] =      {'\x0f',    '\x12', '\x02', '\x00', '\x01'         };
static const char ClockDivData[] =  {'\x0f',    '\x12', '\x02', '\x1F', '\xC0'         };
static const char AccCode[] =       {'\x0f',    '\x12', '\x02', '\x10', '\x00'         };
static const char AccMask[] =       {'\x0f',    '\x12', '\x02', '\x14', '\xff'         };
static const char OutCtrl[] =       {'\x0f',    '\x12', '\x02', '\x08', '\xDA'         };
static const char IE[] =            {'\x0f',    '\x12', '\x02', '\x04', '\x03'         };
static const char BT0[] =           {'\x0f',    '\x12', '\x02', '\x06', '\x00'         };
static const char BT1[] =           {'\x0f',    '\x12', '\x02', '\x07', '\x14'         };
static const char CTL_Code[] =      {'\x0f',    '\x20', '\x01', '\x18'                 };
static const char TRL_Code[] =      {'\x0f',    '\x20', '\x02', '\x01'                 };
static const char NormalMode[] =    {'\x0f',    '\x03', '\x00'                         };
static const char ModRegDat[] =     {'\x0f',    '\x12', '\x02', '\x00', '\x00'         };

static const char synchr =          {'\x0f' };
static const char CMD_writeReg =    {'\x12'};
static const char writeReg[] =      {synchr,    CMD_writeReg};
static const char readReg[] =       {'\x0f',    '\x10'};

static const char getMode[] =       {'\x0f',    '\x06',    '\x00'};



/*
static const char Config[] =        {'\x0f',    '\x02', '\x00', '\x0D'                 };
static const char ResetMod[] =      {'\x0f',    '\x12', '\x02', '\x00', '\x01'         };
static const char ClockDivData[] =  {'\x0f',    '\x12', '\x02', '\x1F', '\xC0'         };
static const char AccCode[] =       {'\x0f',    '\x12', '\x02', '\x10', '\x00'         };
static const char AccMask[] =       {'\x0f',    '\x12', '\x02', '\x14', '\xff'         };
static const char OutCtrl[] =       {'\x0f',    '\x12', '\x02', '\x08', '\xDA'         };
static const char IE[] =            {'\x0f',    '\x12', '\x02', '\x04', '\x03'         };
static const char BT0[] =           {'\x0f',    '\x12', '\x02', '\x06', '\x00'         };
static const char BT1[] =           {'\x0f',    '\12',  '\x02', '\x07', '\x14'         };
static const char CTL_Code[] =      {'\x0f',    '\x20', '\x01', '\x18'                 };
static const char TRL_Code[] =      {'\x0f',    '\x20', '\x02', '\x01'                 };
static const char NormalMode[] =    {'\x0f',    '\x03', '\x00'                         };
static const char ModRegDat[] =     {'\x0f',    '\x12', '\x02', '\x00', '\x00'         };

static const char synchr[] =        {'\x0f'           };
static const char writeReg[] =      {'\x0f',    '\x12'};
static const char readReg[] =       {'\x0f',    '\x10'};

static const char getMode[] =       {'\x0f',    '\x06',    '\x00'};
*/
//Commands
static const QString msg = "msg";
static const QString test1 = "test1";
