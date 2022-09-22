#include "mythread.h"
#include "QDebug"

//Threads global theory:
//https://www.geeksforgeeks.org/cpu-scheduling-in-operating-systems/

MyThread::MyThread(QObject *parent) : QThread(parent)
{
    MyThread::stop = false;
}
MyThread::~MyThread(){

}


void MyThread::run(){
    for(int i = value;i < 20;i++){
        QMutex mutex;
        mutex.lock();
        if(this->stop){
            MyThread::stop = false; //Enable toogling thread
            i=value;
            break;
        }
        mutex.unlock();
        emit NumberChanged(i,name);
        //emit NumberChanged(i);
        this->msleep(10);
     }

}

void MyThread::cycleNum(){
    for(int i = value;i < 20;i++){
        QMutex mutex;
        mutex.lock();
        if(this->stop){
            MyThread::stop = false; //Enable toogling thread
            i=value;
            break;
        }
        mutex.unlock();
        emit NumberChanged(i,name);
        //emit NumberChanged(i);
        this->msleep(10);
     }

}

void MyThread::randomizer(){
    QRandomGenerator rand;
    emit randomizer_out(rand.generate(),MyThread::name);
}
