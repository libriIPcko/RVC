#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //mThread = new MyThread(this);
    rad = new RADAR_AWR1843;
    //connect(mThread,SIGNAL(NumberChanged(int)),this,SLOT(onNumberChanged(int)));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onNumberChanged(int Number)
{
    //ui->label->setText(QString::number((Number)));
}

//start
void Dialog::on_pushButtons_Start_clicked()
{
    //Start
    //mThread->stop = false;
    //mThread->start();

    /*
    //qDebug() << "APP/User UART status: " << rad->PortConnect("COM66", 9600, "COM");
    qDebug() << "Comm UART status: " << rad->PortConnect(rad->port_defaultPort_COM, rad->port_COMM_baudRate, "COM");
    qDebug() << "Auxiliary UART status: " << rad->PortConnect(rad->port_defaultPort_AUX, rad->port_AUXILIARY_baudRate, "AUX");
    rad->init(rad->cfgPath); //initialized  //Stop RX

    qDebug() << "Status of interclass connection : ";
    qDebug() << connect(rad,SIGNAL(Interrupt_ReadPacket(QString,int)),this,SLOT(onInterrupt_ReadPacket(QString,int)));
    */

    //rad->init(rad->cfgPath); //initialized  //Stop RX
    rad->openFile(rad->RadarDataPath);
    //rad->init("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/template TLV radar data.txt");
    rad->algorithm_ReadFromFile();
    qDebug() << rad->PortDisconnect();    //Disconnecting of radar

}


void Dialog::on_pushButton_2_clicked()
{
    //Stop
    //mThread->stop = true;
    //qDebug() << rad->PortDisconnect();    //Disconnecting of radar
    qDebug() << "Stop case";
    qDebug() << rad->PortDisconnect();    //Disconnecting of radar
    ui->textBrowser->append("END\n");
}

void Dialog::onInterrupt_ReadPacket(QString data, int dataCounter){
    //QString txt = QString::number(dataCounter) + "\n" + data;
    //ui->textBrowser->append(txt);
    ui->textBrowser->append(rad->TLV_packets.at(dataCounter).fHST.sync);

}

