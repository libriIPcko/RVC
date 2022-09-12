#include "mythread.h"
#include "QDebug"


MyThread::MyThread(QObject *parent) : QThread(parent)
{
}
MyThread::~MyThread(){

}


void MyThread::run(){
    for(int i = 0;i < 1000;i++){
        QMutex mutex;
        mutex.lock();
        if(this->stop)  break;
        mutex.unlock();

        emit NumberChanged(i);
        this->msleep(10);
     }

}
