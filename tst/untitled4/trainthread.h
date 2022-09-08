#ifndef TRAINTHREAD_H
#define TRAINTHREAD_H

#include <QObject>
#include <QFile>
#include "QThread"
#include <QVector>
#include <QRandomGenerator>
#include <QTextStream>
#include <QDebug>

class TrainThread : QObject
{
    Q_OBJECT
public:
    TrainThread();
    ~TrainThread();

    QVector<int> *var_a = new QVector<int>;
    QVector<int> *var_b = new QVector<int>;
    QVector<int> *var_c = new QVector<int>;
    //int generate(int countGenerateFiles, QVector<int> vector);
    int saveToFile(QVector<int> input);
    int saveToFile(QChar Operation,QVector<int> input_a, QVector<int> input_b, QVector<int> input_c);
    int loadFromFile(QVector<int> output);

    int sum(QVector<int> a,QVector<int> b, QVector<int> output);
    int subtract(QVector<int> a,QVector<int> b, QVector<int> output);
    int multiply(QVector<int> a,QVector<int> b, QVector<int> output);
    int divide(QVector<int> a,QVector<int> b, QVector<int> output);

    QVector<int> generate(int countGenerateFiles);

private:
    int var;
    QVector<QThread> *var2 = new QVector<QThread>;
    QFile *vectorFile = new QFile("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/ThreadTestOutput/thread.txt");

    int generateNum(int min, int max);
    int generateNum(int min, int max, int seed);
/*
    QThread thread_1;
public: signals:
    void finished();
    void started();
    void error(QString);
private slots:
    void process();
    void quit();
    void deleteLater();
*/
};
#endif // TRAINTHREAD_H
