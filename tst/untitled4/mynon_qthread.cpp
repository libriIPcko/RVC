#include "mynon_qthread.h"

myNon_QThread::myNon_QThread()
{

}

void myNon_QThread::run(){         //default thread
    for(int n=0;n<=100;n++){
        qDebug() << myNon_QThread::name << "defaultThread "<< "-" << n;
        //emit
            //num changed
    }
}

void myNon_QThread::run_a(){
    for(int n=0;n<=100;n++){
        qDebug() << myNon_QThread::name << "run_a" << "-" << n;
        //emit
            //num changed
    }
}

void myNon_QThread::run_b(){
    for(int n=0;n<=100;n++){
        if(n%2){
            qDebug() << myNon_QThread::name << "run_b" << "-" << n;
        }
        //emit
            //num changed
    }
}
