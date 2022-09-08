#include <QCoreApplication>
#include <iostream>
#include "C:\Users\RPlsicik\Documents\GitHub\RVC\radar_awr1843.h"
#include "testc.h"
#include "trainthread.h"

QString cfgPath = "C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/tstFile.txt";


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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
    return a.exec();

}
