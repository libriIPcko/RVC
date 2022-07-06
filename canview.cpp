#include "canview.h"
#include "ui_canview.h"
#include "QSignalSpy"

CANview::CANview(QWidget *parent) : QDialog(parent),ui(new Ui::CANview)
{
    ui->setupUi(this);
    u2c = new USB2CAN_driver;

}

CANview::~CANview()
{
    delete ui;   
}

//connect fcn
void CANview::on_connectPort_released()
{
    if(u2c->isOpen()){
        u2c->disconnectedFromPort();
    }
    else{
        //qDebug() << "u2c some port is open" << u2c->connectToPort(ui->inputNamePort->text());
        u2c->connectToPort(ui->inputNamePort->text());
        //qDebug() << "port_USB2CAN is open " << u2c->port_USB2CAN->isOpen();
        //QObject::connect(u2c,SIGNAL(readyRead()),this,SLOT(QByteArray read_u2c()));
        //qDebug() << "Connect rx task" << QObject::connect(u2c,SIGNAL(readyRead()),this,SLOT(read_u2c()));


        //qDebug() << "Connect rx task, status: " << connect(u2c,SIGNAL(USB2CAN_driver::readyRead()),this,SLOT(read_u2c()));

        //qDebug() << "Connect rx task, status: " << connect(u2c,SIGNAL(readyRead()),this,SLOT(read_u2c()));
        qDebug() << "Connect rx task, status: " << connect(???,SIGNAL(QIODevice::readyRead()),this,SLOT(read_u2c()));
        //connect(u2c,SIGNAL(readChannelFinished()),this,SLOT(event_readChannelFinished()));

                    //time = new QTimer;
                    //connect(time,SIGNAL(timeout()),this,SLOT(timerSubrutine()));
                    //time->start(1500);
        connect(u2c->tim,SIGNAL(timeout()),this,SLOT(timerSubrutine()));
        u2c->tim->start(800);

    }

    //Controll of opened/close port
    if(u2c->isOpen()){
        ui->connectPort->setCheckState(Qt::CheckState::Checked);
    }
    else{
        ui->connectPort->setCheckState(Qt::CheckState::Unchecked);
    }
}

//Send function
void CANview::on_pushButton_released()
{
    u2c->write(ui->TX_textBrowser->toPlainText().toLatin1(),static_cast<int>(ui->TX_textBrowser->toPlainText().length()));
    qDebug() << "Send: " << static_cast<int> (ui->TX_textBrowser->toPlainText().length());
    QSignalSpy spy(u2c,SIGNAL(readyRead()));
    qDebug() << spy.signal() << spy.signalsBlocked() << spy.isValid();
}

QByteArray CANview::read_u2c(){
    qDebug() << "RX:" << u2c->readAll();
    ui->RX_textBrowser_2->setPlainText(u2c->readAll());
    return u2c->readAll();
}

void CANview::timerSubrutine(){
    qDebug() << "TimerEvent" << u2c->tim_counter++;
    if(u2c->tim_counter >= 5){
        u2c->tim->stop();
    }
}

