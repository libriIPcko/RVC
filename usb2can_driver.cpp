#include "usb2can_driver.h"
#include "USB2CAN_define.h"
#include "QSerialPort"

#include "QSerialPort"
#include "QObject"
#include "QDebug"



USB2CAN_driver::USB2CAN_driver()
{
    //USB2CAN_driver:: = new QSerialPort();
    //USB2CAN_driver::Baud9600;
    //USB2CAN_driver::AllDirections;
    //qDebug() << "Open port" << USB2CAN_driver::open(QIODevice::ReadWrite);

}

/*
USB2CAN_driver::~USB2CAN_driver(){
    QObject::disconnect(USB2CAN_driver::,SIGNAL(readyRead()),USB2CAN_driver::,SLOT(QByteArray read_USB2CAN()));
}
*/

int USB2CAN_driver::connectToPort(QString portName){
    //USB2CAN_driver::portName = portName;
    USB2CAN_driver::setPortName(portName);
    USB2CAN_driver::setPortName(portName);
    USB2CAN_driver::setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);
    USB2CAN_driver::setPortName(portName);
    //Reimplemented separately as signal of driver. !!!
    //QObject::connect(USB2CAN_driver::,SIGNAL(readyRead()),USB2CAN_driver::,SLOT(QByteArray read_USB2CAN()));
    return USB2CAN_driver::open(QIODevice::ReadWrite);
}

int USB2CAN_driver::disconnectedFromPort(){
    QObject::disconnect(this,SIGNAL(readyRead()),this,SLOT(read_USB2CAN()));
    USB2CAN_driver::close();

    if(USB2CAN_driver::isOpen()){
        return 1;
    }
    else{
        return 0;
    }
}


void USB2CAN_driver::USB_LoopBack(){

}
void USB2CAN_driver::Boot_Mode(){

}
void USB2CAN_driver::Config_Mode(){

}
void USB2CAN_driver::Normal_Mode(){

}
void USB2CAN_driver::LoopBack_Mode(){

}
QByteArray USB2CAN_driver::Get_Mode(){
    while(!USB2CAN_driver::waitForBytesWritten(300)){
        USB2CAN_driver::write(getMode);

    }
    return USB2CAN_driver::readAll();
}

void USB2CAN_driver::WriteReg(QByteArray regAdress, QByteArray value[]){
    int length = regAdress.length() + value->length();
    QByteArray len;
    len.setNum(length);
    QByteArray sendVal[] = { writeReg, len, regAdress, *value };
    QByteArray sendData;
    sendData.fromRawData(*sendVal,sizeof (sendVal));
    while(!USB2CAN_driver::waitForBytesWritten(300)){
        USB2CAN_driver::write(sendData);

    }
}
QByteArray USB2CAN_driver::WriteCMD(QByteArray CMD_name, QByteArray value){

}
QByteArray USB2CAN_driver::ReadReg(QByteArray regAdress){

}

int USB2CAN_driver::init(){
    tim_interrupt_1 = new QTimer();
    //QObject::connect(tim_interrupt_1,SIGNAL(timeout()),this,SLOT(USB2CAN_driver::initSend()));
    QObject::connect(tim_interrupt_1,SIGNAL(timeout()),this,SLOT(initSend()));
    tim_interrupt_1->start(500);
}

QByteArray USB2CAN_driver::read_USB2CAN(){
    return USB2CAN_driver::readAll();
}

void USB2CAN_driver::initSend(){
    bool stop = false;
    int waitForBytesWritten = 300;
    //qDebug() << USB2CAN_driver::flush();
    switch (temporary_init_Counter) {
        case 0:                     //1-Set to Config Mode [0x02]
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(Config,qstrlen(Config));
                USB2CAN_driver::write(Config,3);
            }
        break;
        case 1:                    //2-Set Reset Mode [0x00]on value 0x01   (by WriteReg[x12])
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ResetMod);
                //USB2CAN_driver::write(ResetMod,qstrlen(ResetMod));
                USB2CAN_driver::write(ResetMod,5);
            }
        break;
        case 2:                    //3-Set Clock divider [0x1F] on value 0xC0 (by WriteReg[x12])
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ClockDivData);
                //USB2CAN_driver::write(ClockDivData,qstrlen(ClockDivData));
                USB2CAN_driver::write(ClockDivData,5);
            }
        break;
        case 3:                    //4.1-Set message filter; without filtration: (by WriteReg[x12])
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(AccCode);
                //USB2CAN_driver::write(AccCode,qstrlen(AccCode));
                USB2CAN_driver::write(AccCode,5);
            }
        break;
        case 4:                    //4.2 set-> Acceptance Mask [0x05] on 0xff
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(AccMask);
                //USB2CAN_driver::write(AccMask,qstrlen(AccMask));
                USB2CAN_driver::write(AccMask,5);
            }
        break;
        case 5:                   //5-Set OutputControl[0x08] on 0xDA (by WriteReg[x12])
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(OutCtrl);
                //USB2CAN_driver::write(OutCtrl),qstrlen(OutCtrl);
                USB2CAN_driver::write(OutCtrl,5);
            }
        break;
        case 6:                  //7. -Set Interrupt enable[]  on 0x03  (by WriteReg[x12])
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(IE);
                //USB2CAN_driver::write(IE,qstrlen(IE));
                USB2CAN_driver::write(IE,5);
            }
        break;
        case 7:                 //6.1 - Bus Timing 0
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(BT0);
                //USB2CAN_driver::write(BT0,qstrlen(BT0));
                USB2CAN_driver::write(BT0,5);
            }
        break;
        case 8:                 //6.2 - Bus Timing 1
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(BT1);
                //USB2CAN_driver::write(BT1,qstrlen(BT1));
                USB2CAN_driver::write(BT1,5);
            }
        break;
        case 9:                 //8.1 -Set Transmit Critical Limit and Transmit Ready limit by cmd COMMAND TCL
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(CTL_Code);
                //USB2CAN_driver::write(CTL_Code,qstrlen(CTL_Code));
                USB2CAN_driver::write(CTL_Code,4);
            }
        break;
        case 10:               //8.2 Set-> TRL
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(TRL_Code);
                //USB2CAN_driver::write(TRL_Code,qstrlen(TRL_Code));
                USB2CAN_driver::write(TRL_Code,4);
            }
        break;
        case 11:              //9-Set Normal Mode
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(NormalMode);
                //USB2CAN_driver::write(NormalMode,qstrlen(NormalMode));
                USB2CAN_driver::write(NormalMode,3);
            }
            break;
        case 12:              //10-Set Mode register [0x00], the value depends on Message Filter   (by WriteReg[x12])
            while(!USB2CAN_driver::waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ModRegDat);
                //USB2CAN_driver::write(ModRegDat,qstrlen(ModRegDat));
                USB2CAN_driver::write(ModRegDat,5);
            }
        break;
        case 13:              //End of Initialize sub-routine
            stop = true;
        break;
        default:
            qDebug() << "ERROR init !! case" << temporary_init_Counter;
        break;
    }

    if(stop == true){
        temporary_init_Counter = 0;
        tim_interrupt_1->stop();
        //QObject::disconnect(tim_interrupt_1,SIGNAL(readyRead()),tim_interrupt_1,SLOT(initSend()));
    }
    else{
        temporary_init_Counter++;
    }



}

/*
int USB2CAN_driver::write(QString data){
    //USB2CAN_driver::write(data,static_cast<qint64>(data));
}
*/
