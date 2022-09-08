#ifndef MYTHREAD_H
#define MYTHREAD_H

#include "QtCore"
#include "QThread"
#include "QDebug"
#include "QThread"
#include "QObject"


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    ~MyThread();

    QString name;
    bool stop = false;
    void run();
    //void start();
signals:
    void NumberChanged(int);
public slots:
};

#endif // MYTHREAD_H
