#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mThread = new MyThread(this);
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

void Dialog::on_pushButtons_Start_clicked()
{
    //Start
    //mThread->stop = false;
    //mThread->start();




    //qDebug() << "APP/User UART status: " << rad->PortConnect("COM66", 9600, "COM");
    qDebug() << "APP/User UART status: " << rad->PortConnect("COM3", rad->port_COMM_baudRate, "COM");
    rad->init(rad->cfgPath); //initialized


    qDebug() << rad->PortDisconnect();

}


void Dialog::on_pushButton_2_clicked()
{
    //Stop
    //mThread->stop = true;
}

