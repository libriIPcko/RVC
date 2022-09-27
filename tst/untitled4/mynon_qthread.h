#ifndef MYNON_QTHREAD_H
#define MYNON_QTHREAD_H

#include <QDebug>

class myNon_QThread
{
public:
    myNon_QThread();
    void run();         //default thread
    void run_a();       //first thread
    void run_b();       //second thread

    QString name;
};

#endif // MYNON_QTHREAD_H
