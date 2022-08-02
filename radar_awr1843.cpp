#include "radar_awr1843.h"

RADAR_AWR1843::RADAR_AWR1843()
{
    port_AUXILIARY = new QSerialPort;
    port_COMM = new QSerialPort;
}
RADAR_AWR1843::~RADAR_AWR1843(){
    PortDisconnect();
}

//@portName == COM14 or COM15
//@typePort == AUX for AUXILIARY port
//@typePort == COM for COMMUNICATION port
int RADAR_AWR1843::PortConnect(QString portName, int BaudRate, QString typePort){
    if(QString::compare(typePort,"AUX")){
        port_AUXILIARY->setPortName(portName);
        port_AUXILIARY->setBaudRate(BaudRate);
        return port_AUXILIARY->open(QIODevice::ReadOnly);
    }
    else if(QString::compare(typePort,"COM")){
        port_COMM->setPortName(portName);
        port_COMM->setBaudRate(BaudRate);
        return port_COMM->open(QIODevice::ReadWrite);
    }
    else{   //default settings COM14 and COM15
        return 1;   //Error statement
    }
}

//@typePort == AUX for AUXILIARY port
//@typePort == COM for COMMUNICATION port
//@return 2 == Port was closed
//@return 1 == Port is closed
int RADAR_AWR1843::PortDisconnect(QString typePort){
    if(QString::compare(typePort,"AUX")){
        bool closeStatus = !port_AUXILIARY->isOpen();
        if(closeStatus == false){
            port_AUXILIARY->disconnect();
            port_AUXILIARY->close();
            return 0;
        }
        else{
            return 2;
        }
    }
    else if(QString::compare(typePort,"AUX")){
        bool closeStatus = !port_COMM->isOpen();
        if(closeStatus == false){
            port_COMM->disconnect();
            port_COMM->close();
            return 0;
        }
        else{
            return 2;
        }
    }
    else{
        PortDisconnect();
    }
}

int RADAR_AWR1843::PortDisconnect(){
    bool closeStatus_AUX = !port_AUXILIARY->isOpen();
    bool closeStatus_COMM = !port_COMM->isOpen();

    if(closeStatus_AUX == false){
        port_AUXILIARY->disconnect();
        port_AUXILIARY->close();
    }
    if(closeStatus_COMM == false){
        port_COMM->disconnect();
        port_COMM->close();
    }

    if((closeStatus_AUX == false)&&(closeStatus_COMM == false)){
        return 1;   //error statement
    }
    else{
        return 0;   //close was sucesfull
    }

}
