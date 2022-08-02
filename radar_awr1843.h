#ifndef RADAR_AWR1843_H
#define RADAR_AWR1843_H

#include <QObject>
#include "QSerialPort"
#include "QThread"

class RADAR_AWR1843
{
    Q_OBJECT
public:
    RADAR_AWR1843();
    int init(QString path);





private:
    ~RADAR_AWR1843();

    int PortConnect(QString portName, int BaudRate, QString portType);
    int PortDisconnect(QString typePort);
    int PortDisconnect();
    int send_COMM(QString data);

    int port_AUXILIARY_baudRate = 118200;
    int port_COMM_baudRate = 118200;


    QSerialPort *port_AUXILIARY;
    QSerialPort *port_COMM;


public: signals:
    QIODevice ReadyRead();

private slots:
    int port_COMM_receive();
    int port_AUXILIARY_receive();



};

#endif // RADAR_AWR1843_H
