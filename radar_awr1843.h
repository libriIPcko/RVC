#ifndef RADAR_AWR1843_H
#define RADAR_AWR1843_H

//#include <QObject>
#include "QIODevice"
#include "QSerialPort"
#include "QThread"
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <tlv_dat.h>

#include "QChar"

class RADAR_AWR1843 : public QSerialPort//, public QThread
{
    Q_OBJECT
public:
    explicit RADAR_AWR1843(QObject *parent = 0);
    ~RADAR_AWR1843();
    int init(QString path);
    int initialization(QString path);
    int connect();

    int PortConnect(QString portName, int BaudRate, QString portType);
    int PortDisconnect();

    int port_AUXILIARY_baudRate = 921600;
    int port_COMM_baudRate = 115200;
    QString port_defaultPort_AUX = "COM4";
    QString port_defaultPort_COM = "COM3";

    //Debug part of SC
    int openFile(QString DataPath);
    QTimer *tim_debug = new QTimer;
    int tim_debug_period = 200;
    QTimer *watchdog_RX = new QTimer;
    int watchdog_RX_period = 2000;
    //QFile debug_file("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/deb.txt");
    int marker = 0;
    QString RX;
    QString cfgPath = "C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/xwr18xx_profile_2022_05_30T13_05_06_607.txt";
    //QString cfgPath = "C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/template TLV radar data.txt";
    QString RadarDataPath = "C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/template TLV radar data.txt";

    std::vector<QString> TLV_RAW_packets;
    std::vector<TLV_dat> TLV_packets;
    std::vector<int> pos;                            //vector of start position of sync chain
    TLV_dat outData;
    QString data;
    //Dev-Deb Var DDV
    int algorithm_ReadFromFile();
    int syncDetect();
    int loadPackets();
    int ofset = 0;

private:
    int ReadConfigCMD(QString path,std::array<QString, 60> txtLines);
    int PortDisconnect(QString typePort);
    int send_COMM(QString data);
    int readPackets(int msec);
    int sortData(QString,int);
    //1 - point cloud | 2 - target object | 3 - target index
    int activeType = 0;
    std::array<QString, 60> temporary_arrayCMD;
    QSerialPort *port_AUXILIARY;
    QSerialPort *port_COMM;

    //RX_radar_data obj and variables
        //QFile  = new QFile;
        //QFile *RX_radar_data(C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/RX_radar_data.txt);
        QFile *RX_radar_data = new QFile("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/RX_radar_data.txt");
        //QFile *DebugLog = new QFile("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/DebugLog.txt");             //old path
        //QFile *DebugLog = new QFile("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/Backup RX data/RX_radar_data - 1h45m 11.8.2022.txt");               //new path
        //QFile *DebugLog = new QFile("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/Backup RX data/template TLV radar data.txt");
        QFile *DebugLog = new QFile();


        QTime stopwatch;


public: signals:
    //QIODevice ReadyRead();
    void timeout();
    void readyRead();
    void Interrupt_ReadPacket(QString data, int dataCounter);
    void Interrupt_ReadTLV_packets(TLV_dat TLV_packets);


public slots:
    int port_COMM_receive();
    int port_AUXILIARY_receive();
    //int tim_timeout();
    void tim_debug_handler();
    void watchdog_RX_handler();

    /*
public: signals:
   //QIODevice ReadyRead();
   // QTimer timeout();

private slots:
    int port_COMM_receive();
    int port_AUXILIARY_receive();
    //int tim_timeout();
    void tim_debug_handler(int marker);
    */

};

#endif // RADAR_AWR1843_H
