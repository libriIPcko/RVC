#ifndef MYTHREAD_H
#define MYTHREAD_H

#include "QtCore"
#include "QThread"
#include "QDebug"
#include "QThread"
#include "QObject"
#include "QSerialPort"
#include "QRandomGenerator"


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    ~MyThread();

    QString name;
    bool stop = false;
    void run();
    void randomizer();
    int value = 0;
    //void start();

public: signals:
    void NumberChanged(int,QString);
    void NumberChanged(int);
    void randomizer_out(int,QString);
public slots:
};

#endif // MYTHREAD_H
