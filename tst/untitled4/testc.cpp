#include "testc.h"
#include <stdio.h>
#include <QDebug>
#include "C:\Users\RPlsicik\Documents\GitHub\RVC\radar_awr1843.h"

testC::testC()
{

}

testC::~testC()
{
    QObject::disconnect();
}

void testC::start(int ms,int cycleCount){
    QObject::connect(cas,SIGNAL(timeout()),this,SLOT(cas_handler()));
    cas->start(ms);
    var_ref = cycleCount;
}

void testC::start_infinity(int ms){
    QObject::connect(cas,SIGNAL(timeout()),this,SLOT(cas_infinity_handler()));
    cas->start(ms);
}

void testC::cas_handler(){
    qDebug() << "Hey";
    if(var >= var_ref){
        cas->stop();
    }
    else {
        var++;
    }
}

void testC::cas_infinity_handler(){
    //qDebug() << var++;
    //qDebug() << "Duration of QTimer: " << rad->tim_debug->remainingTime();
    var++;
}


int testC::testCase_Initialize_RADAR(QString RadOrVirt){
    QString cfgPath = "C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/tstFile.txt";
    //rad->initialization(cfgPath);

    if(QString::compare(RadOrVirt,"rad")==0){
        //qDebug() << "APP/User UART status: " << rad->PortConnect("COM3", rad->port_COMM_baudRate, "COM");
        //qDebug() << "Auxiliary data status: " << rad->PortConnect("COM4", rad->port_AUXILIARY_baudRate, "AUX");
        bool statusCom, statusAUX;
        statusCom = rad->PortConnect("COM3", rad->port_COMM_baudRate, "COM");//COM3
        statusAUX = rad->PortConnect("COM4", rad->port_AUXILIARY_baudRate, "AUX");
        if((statusCom==false)&&(statusAUX)==false){
            qDebug() << "Error during opening ports";
            qDebug() << "APP/User UART status: " << statusCom;
            qDebug() << "Auxiliary data status: " << statusAUX;
            return 0;
        }

        else{
            qDebug() << "Init process;";
            rad->initialization(cfgPath);
        }
    }
    else{
        //qDebug() << "COM66 -  " << rad->PortConnect("COM66", 9600, "COM");
        //qDebug() << "COM4 - Auxiliary data status: " << rad->PortConnect("COM4", rad->port_AUXILIARY_baudRate, "AUX");
        bool statusCom, statusAUX;
        statusCom = rad->PortConnect("COM66", 9600, "COM");
        statusAUX = rad->PortConnect("COM4", rad->port_AUXILIARY_baudRate, "AUX");
        if((statusCom==false)&&(statusAUX)==false){
            qDebug() << "Error during opening ports";
            qDebug() << "COM66 -  " << statusCom;
            qDebug() << "COM4 - Auxiliary data status: " << statusAUX;
            return 0;
        }

        else{
            qDebug() << "Init process;";
            rad->initialization(cfgPath);
        }
    }

    //qDebug() << "Status port: " << rad->PortDisconnect();
    //qDebug() << "Duration of QTimer: " << rad->tim_debug->remainingTime();
    //rad->~RADAR_AWR1843();
}
