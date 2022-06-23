#ifndef USB2CAN_DRIVER_H
#define USB2CAN_DRIVER_H

#include "QSerialPort"
#include "QTimer"
#include "USB2CAN_define.h"

#include "QObject"


class USB2CAN_driver
{
    //Q_OBJECT;
public:
    USB2CAN_driver();

    QSerialPort *port_USB2CAN = new QSerialPort();
    QTimer *tim_interrupt_1 = new QTimer();

    int init();
    void USB_LoopBack();
    void Boot_Mode();
    void Config_Mode();
    void Normal_Mode();
    void LoopBack_Mode();
    QByteArray Get_Mode();

    void WriteReg(QByteArray regAdress, QByteArray value[]);
    QByteArray WriteCMD(QByteArray CMD_name, QByteArray value);
    QByteArray ReadReg(QByteArray regAdress);



private: signals:
    void readyRead();

private slots:
    QByteArray read_USB2CAN();
    void initSend();

};

#endif // USB2CAN_DRIVER_H
