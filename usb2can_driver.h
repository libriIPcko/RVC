#ifndef USB2CAN_DRIVER_H
#define USB2CAN_DRIVER_H

#include "QSerialPort"
#include "QTimer"

#include "QObject"

//#include "QSignalSpy"


class USB2CAN_driver : public QSerialPort
{
    Q_OBJECT;

public:
    USB2CAN_driver();
    //virtual ~USB2CAN_driver();

    QSerialPort *port_USB2CAN;
    QTimer *tim_interrupt_1 = new QTimer();
    QTimer *ListTimer = new QTimer();
    QTimer *initListTimer = new QTimer();
    QTimer *tim;
    int tim_counter = 0;

    int temporary_init_Counter = 0;
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
    int SendString(QString data);

    void writeCANmsg(QString msg);

    QString portName;
    int connectToPort(QString portName);
    int disconnectedFromPort();


public: signals:
    //void readyRead();
    friend void QIODevice::readyRead();
    void timeout();
    void dataReceived(QByteArray);
    //void QSerialPort::readyRead();
    //void USB2CAN_driver::readyRead();

private slots:
    //For reading from driver, you have to implemented separately to own
    //QObject::connect(port_USB2CAN,SIGNAL(readyRead()),ObjWhereIsOwnMethod,SLOT(QByteArray ownMethod()));

    QByteArray read_USB2CAN();
    bool initSend();
    void initSend_1();
};

#endif // USB2CAN_DRIVER_H
