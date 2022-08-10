#ifndef RADAR_AWR1843_H
#define RADAR_AWR1843_H

#include <QObject>
#include "QIODevice"
#include "QSerialPort"
#include "QThread"
#include <QTimer>
#include <QFile>

class RADAR_AWR1843 : QSerialPort
{
    Q_OBJECT
public:
    RADAR_AWR1843();
    ~RADAR_AWR1843();
    int init(QString path);
    int initialization(QString path);
    int connect();

    int PortConnect(QString portName, int BaudRate, QString portType);
    int PortDisconnect();

    int port_AUXILIARY_baudRate = 921600;
    int port_COMM_baudRate = 115200;

    //Debug part of SC
    QTimer *tim_debug = new QTimer;
    QTimer *watchdog_RX = new QTimer;
    //QFile debug_file("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/deb.txt");
    int marker = 0;
    QString RX;

private:
    int ReadConfigCMD(QString path,std::array<QString, 60> txtLines);
    int PortDisconnect(QString typePort);
    int send_COMM(QString data);

    int readPackets(int msec);
    std::array<QString, 60> temporary_arrayCMD;
    QSerialPort *port_AUXILIARY;
    QSerialPort *port_COMM;


public: signals:
    //QIODevice ReadyRead();
    void timeout();
    void readyRead();


public slots:
    int port_COMM_receive();
    int port_AUXILIARY_receive();
    //int tim_timeout();
    void tim_debug_handler();
    void watchdog_RX_handler();
    /*
public: signals:
    //QIODevice ReadyRead();
    QTimer timeout();


private slots:
    int port_COMM_receive();
    int port_AUXILIARY_receive();
    //int tim_timeout();
    void tim_debug_handler(int marker);
    */
};

#endif // RADAR_AWR1843_H
