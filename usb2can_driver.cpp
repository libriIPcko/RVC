#include "usb2can_driver.h"
#include "QSerialPort"

#include "QSerialPort"
#include "QObject"
#include "QDebug"



USB2CAN_driver::USB2CAN_driver()
{
    port_USB2CAN = new QSerialPort();
    QObject::connect(port_USB2CAN,SIGNAL(readyRead()),port_USB2CAN,SLOT(QByteArray read_USB2CAN()));
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
    while(port_USB2CAN->waitForBytesWritten(300)){
        port_USB2CAN->write(getMode);

    }
    return port_USB2CAN->readAll();
}

void USB2CAN_driver::WriteReg(QByteArray regAdress, QByteArray value[]){
    int length = regAdress.length() + value->length();
    QByteArray len;
    len.setNum(length);
    QByteArray sendVal[] = { writeReg, len, regAdress, *value };
    QByteArray sendData;
    sendData.fromRawData(*sendVal,sizeof (sendVal));
    while(port_USB2CAN->waitForBytesWritten(300)){
        port_USB2CAN->write(sendData);

    }
}
QByteArray USB2CAN_driver::WriteCMD(QByteArray CMD_name, QByteArray value){

}
QByteArray USB2CAN_driver::ReadReg(QByteArray regAdress){

}

int USB2CAN_driver::init(){
    tim_interrupt_1 = new QTimer();
    QObject::connect(tim_interrupt_1,SIGNAL(timeout()),tim_interrupt_1,SLOT(initSend()));
}

QByteArray USB2CAN_driver::read_USB2CAN(){
    return port_USB2CAN->readAll();
}

void USB2CAN_driver::initSend(){
    USB2CAN_driver::port_USB2CAN->write(Config);

}
