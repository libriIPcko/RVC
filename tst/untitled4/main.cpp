#include <QCoreApplication>
#include <iostream>
#include "C:\Users\RPlsicik\Documents\GitHub\RVC\radar_awr1843.h"
#include "testc.h"

QString cfgPath = "C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/tstFile.txt";


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    RADAR_AWR1843 *rad = new RADAR_AWR1843;
    qDebug() << "APP/User UART status: " << rad->PortConnect("COM66", 9600, "COM");
    //qDebug() << "APP/User UART status: " << rad->PortConnect("COM3", rad->port_COMM_baudRate, "COM");
    qDebug() << "Auxiliary data status: " << rad->PortConnect("COM4", rad->port_AUXILIARY_baudRate, "AUX");
    rad->initialization(cfgPath);
    //rad->init(cfgPath); //initialized
    //take data
    std::cout << "End";
    qDebug() << "Status port: " << rad->PortDisconnect();
    qDebug() << "Duration of QTimer: " << rad->tim_debug->remainingTime();
    rad->~RADAR_AWR1843();
    */
    testC *stopwatch = new testC;
    stopwatch->testCase_Initialize_RADAR("rad");
    //stopwatch->start_infinity(100);


    return a.exec();
    //return 0;
}
