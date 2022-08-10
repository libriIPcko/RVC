#ifndef TESTC_H
#define TESTC_H

#include <QObject>
#include <QTimer>
#include "C:\Users\RPlsicik\Documents\GitHub\RVC\radar_awr1843.h"
#include "QDebug"

class testC : QObject
{
    Q_OBJECT
public:
    testC();
    ~testC();
    RADAR_AWR1843 *rad = new RADAR_AWR1843;

    void start(int ms, int cycleCount);
    void start_infinity(int ms);
    QTimer *cas = new QTimer;
    int var=0;
    int var_ref=0;

    int testCase_Initialize_RADAR(QString RadOrVirt);

public: signals:
    void timeout();
private slots:
    void cas_handler();
    void cas_infinity_handler();

};

#endif // TESTC_H
