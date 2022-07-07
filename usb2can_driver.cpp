#include "usb2can_driver.h"
#include "USB2CAN_define.h"
#include "QSerialPort"

#include "QSerialPort"
#include "QObject"
#include "QDebug"

#include <QSignalSpy>



USB2CAN_driver::USB2CAN_driver()
{
    port_USB2CAN = new QSerialPort();
    ListTimer = new QTimer();
    initListTimer = new QTimer();
    connect(initListTimer,SIGNAL(timeout()),this,SLOT(initSend()));
}

/*
USB2CAN_driver::~USB2CAN_driver(){
    QObject::disconnect(USB2CAN_driver::,SIGNAL(readyRead()),USB2CAN_driver::,SLOT(QByteArray read_USB2CAN()));
}
*/

int USB2CAN_driver::connectToPort(QString portName){
    port_USB2CAN->setPortName(portName);
    port_USB2CAN->setBaudRate(Baud9600,AllDirections);
    tim = new QTimer;
    return port_USB2CAN->open(QIODevice::ReadWrite);
}

/*
void USB2CAN_driver::timEvent(){
    qDebug() << "Tim" << tim_counter++;
    if(tim_counter >= 5){
        tim_counter = 0;
        tim->stop();
    }
}
*/

int USB2CAN_driver::disconnectedFromPort(){
    port_USB2CAN->close();
    if(port_USB2CAN->isOpen()){
        return 1;
    }
    else{
        qDebug() << "------------------Port is diconected-----------------";
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
    while(!port_USB2CAN->waitForBytesWritten(300)){
        port_USB2CAN->write(getMode);

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
    while(!port_USB2CAN->waitForBytesWritten(300)){
        port_USB2CAN->write(sendData);

    }
}
QByteArray USB2CAN_driver::WriteCMD(QByteArray CMD_name, QByteArray value){

}
QByteArray USB2CAN_driver::ReadReg(QByteArray regAdress){

}

int USB2CAN_driver::init(){
    //connect(initListTimer,SIGNAL)
    initListTimer->start(200);
}

QByteArray USB2CAN_driver::read_USB2CAN(){
    qDebug() <<"From driver RX" << USB2CAN_driver::readAll();
    return port_USB2CAN->readAll();
}

void USB2CAN_driver::initSend(){
    bool stop = false;
    int waitForBytesWritten = 300;
    //qDebug() << USB2CAN_driver::flush();
    switch (temporary_init_Counter) {
        case 0:                     //1-Set to Config Mode [0x02]
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(Config,qstrlen(Config));
                port_USB2CAN->write(Config,3);
            }
        break;
        case 1:                    //2-Set Reset Mode [0x00]on value 0x01   (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ResetMod);
                //USB2CAN_driver::write(ResetMod,qstrlen(ResetMod));
                port_USB2CAN->write(ResetMod,5);
            }
        break;
        case 2:                    //3-Set Clock divider [0x1F] on value 0xC0 (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ClockDivData);
                //USB2CAN_driver::write(ClockDivData,qstrlen(ClockDivData));
                port_USB2CAN->write(ClockDivData,5);
            }
        break;
        case 3:                    //4.1-Set message filter; without filtration: (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(AccCode);
                //USB2CAN_driver::write(AccCode,qstrlen(AccCode));
                port_USB2CAN->write(AccCode,5);
            }
        break;
        case 4:                    //4.2 set-> Acceptance Mask [0x05] on 0xff
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(AccMask);
                //USB2CAN_driver::write(AccMask,qstrlen(AccMask));
                port_USB2CAN->write(AccMask,5);
            }
        break;
        case 5:                   //5-Set OutputControl[0x08] on 0xDA (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(OutCtrl);
                //USB2CAN_driver::write(OutCtrl),qstrlen(OutCtrl);
                port_USB2CAN->write(OutCtrl,5);
            }
        break;
        case 6:                  //7. -Set Interrupt enable[]  on 0x03  (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(IE);
                //USB2CAN_driver::write(IE,qstrlen(IE));
                port_USB2CAN->write(IE,5);
            }
        break;
        case 7:                 //6.1 - Bus Timing 0
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(BT0);
                //USB2CAN_driver::write(BT0,qstrlen(BT0));
                port_USB2CAN->write(BT0,5);
            }
        break;
        case 8:                 //6.2 - Bus Timing 1
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(BT1);
                //USB2CAN_driver::write(BT1,qstrlen(BT1));
                port_USB2CAN->write(BT1,5);
            }
        break;
        case 9:                 //8.1 -Set Transmit Critical Limit and Transmit Ready limit by cmd COMMAND TCL
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(CTL_Code);
                //USB2CAN_driver::write(CTL_Code,qstrlen(CTL_Code));
                port_USB2CAN->write(CTL_Code,4);
            }
        break;
        case 10:               //8.2 Set-> TRL
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(TRL_Code);
                //USB2CAN_driver::write(TRL_Code,qstrlen(TRL_Code));
                port_USB2CAN->write(TRL_Code,4);
            }
        break;
        case 11:              //9-Set Normal Mode
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(NormalMode);
                //USB2CAN_driver::write(NormalMode,qstrlen(NormalMode));
                port_USB2CAN->write(NormalMode,3);
            }
            break;
        case 12:              //10-Set Mode register [0x00], the value depends on Message Filter   (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ModRegDat);
                //USB2CAN_driver::write(ModRegDat,qstrlen(ModRegDat));
                port_USB2CAN->write(ModRegDat,5);
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
        initListTimer->stop();
        //QObject::disconnect(tim_interrupt_1,SIGNAL(readyRead()),tim_interrupt_1,SLOT(initSend()));
    }
    else{
        temporary_init_Counter++;
    }



}
