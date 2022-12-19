#include <QCoreApplication>
#include <iostream>
#include "C:\Users\RPlsicik\Documents\GitHub\RVC\radar_awr1843.h"
#include "testc.h"
//#include "trainthread.h"
//#include "trainthread_v1.h"
#include "mythread.h"

#include <dialog.h>
#include <dialog_2.h>
#include <QApplication>




QString cfgPath = "C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/tstFile.txt";


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    Dialog w;   //Dialog oficial code, processing of radar data from the file
    //Dialog_2 w;   //Thread tutorial dialog window
    w.show();


    //Radar receive output to txt
    /*
    RADAR_AWR1843 *rad;
    rad = new RADAR_AWR1843;

    //qDebug() << "APP/User UART status: " << rad->PortConnect("COM66", 9600, "COM");
    qDebug() << "APP/User UART status: " << rad->PortConnect("COM3", rad->port_COMM_baudRate, "COM");
    rad->init(cfgPath); //initialized

    qDebug() << rad->PortDisconnect();
    */

    return a.exec();

}
