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
    //Dialog w;   //Dialog oficial code, processing of radar data from the file
    Dialog_2 w;   //Thread tutorial dialog window
    w.show();



/*
    MyThread mThread1;
    mThread1.name = "mThread1";


    MyThread mThread2;
    mThread2.name = "mThread2";


    MyThread mThread3;
    mThread3.name = "mThread3";

    mThread1.start();
    //mThread2.start();
    //mThread3.start();
    mThread1.stop = true;
/*
 *
/*
    mThread1.start();
    mThread2.start();
    mThread3.start(QThread::HighestPriority);
*/


    /*
    testC *stopwatch = new testC;
    //stopwatch->testCase_Initialize_RADAR("rad");
    TrainThread *trainT = new TrainThread;

    *trainT->var_a = trainT->generate(10);
    for(int n=0;n<=trainT->var_a->length();n++){
        qDebug() <<"n:" << n << " ->" << trainT->var_a->at(n);
    }
    qDebug() << "----------------------------";
    qDebug() << "End";
    //trainT->generate(10,*trainT->var_b);
    //trainT->sum(*trainT->var_a,*trainT->var_b,*trainT->var_c);
    //trainT->saveToFile('+',*trainT->var_a,*trainT->var_b,*trainT->var_c);
    */

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
