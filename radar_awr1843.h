#ifndef RADAR_AWR1843_H
#define RADAR_AWR1843_H

#include <QObject>
#include "QIODevice"
#include "QSerialPort"
#include "QThread"
#include <QTimer>

class RADAR_AWR1843 : QSerialPort
{
    Q_OBJECT
public:
    RADAR_AWR1843();
    int init(QString path);
    int connect();

    int PortConnect(QString portName, int BaudRate, QString portType);
    int PortDisconnect();

    int port_AUXILIARY_baudRate = 921600;
    int port_COMM_baudRate = 115200;

private:
    ~RADAR_AWR1843();


    int PortDisconnect(QString typePort);

    int send_COMM(QString data);

    int readPackets(int msec);




    QSerialPort *port_AUXILIARY;
    QSerialPort *port_COMM;

    //QTimer *tim;


public: signals:
    //QIODevice ReadyRead();
    //QTimer timeout();

private slots:
    int port_COMM_receive();
    int port_AUXILIARY_receive();
    //int tim_timeout();



};

#endif // RADAR_AWR1843_H
