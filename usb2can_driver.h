#ifndef USB2CAN_DRIVER_H
#define USB2CAN_DRIVER_H

#include "QSerialPort"


class USB2CAN_driver
{
public:
    USB2CAN_driver();


    QSerialPort *port_USB2CAN;

private: signals:
    void readyRead();

private slots:
    void read_USB2CAN();
};

#endif // USB2CAN_DRIVER_H
