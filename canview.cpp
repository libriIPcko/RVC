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
    if(u2c->port_USB2CAN->isOpen()){
        u2c->disconnectedFromPort();
    }
    else{
        connect(u2c->port_USB2CAN,SIGNAL(readyRead()),this,SLOT(read_u2c()));
        qDebug() << "open session Status:" << u2c->connectToPort(ui->inputNamePort->text());

    }
    //Controll of opened/close port
    if(u2c->port_USB2CAN->isOpen()){
        ui->connectPort->setCheckState(Qt::CheckState::Checked);
    }
    else{
        ui->connectPort->setCheckState(Qt::CheckState::Unchecked);
        connect(u2c->tim,SIGNAL(timeout()),this,SLOT(timerSubrutine()));
        u2c->tim->start(800);
    }
}

//Send function
void CANview::on_pushButton_released()
{
    QString txt = ui->TX_textBrowser->toPlainText();
    if(ui->TX_textBrowser->toPlainText().toLatin1().at(0) == '#'){
        u2c->init();
    }

    else if( (ui->TX_textBrowser->toPlainText().toLatin1().at(0) == 'x')||(ui->TX_textBrowser->toPlainText().toLatin1().at(0) == 'X')){
        qDebug()<<"Hex code has been detected" << txt;
        QByteArray tst;
        QString dat;

        for(qsizetype i = 0;i<txt.length();i++){
            if(txt.at(i) == QChar('x') || txt.at(2) == QChar('X')){
                dat = txt.sliced(++i,2);
                //qDebug() << dat << QByteArray::fromHex(dat.toLatin1());
                while(!u2c->port_USB2CAN->waitForBytesWritten(300)){
                    u2c->port_USB2CAN->write(QByteArray::fromHex(dat.toLatin1()));
                }
            }
        }
    }
    else{
        u2c->port_USB2CAN->write(ui->TX_textBrowser->toPlainText().toLatin1(),static_cast<int>(ui->TX_textBrowser->toPlainText().length()));
    }

}

QByteArray CANview::read_u2c(){
    QByteArray rxData = u2c->port_USB2CAN->readAll();
    QString rxText = QString(rxData.toHex()).toLatin1();
//separate 2bytes
/*
    int i = 0;
    int cnt = 0;
    while (i<rxText.length()) {
        if(i%2 == 0){
            rxText.insert(i + cnt,' ');
            cnt++;
        }
        i++;
    }
*/
    qDebug() << "RX:" << QString(rxData.toHex()).toLatin1();
    ui->RX_textBrowser_2->setPlainText(rxText);
    return rxData;
}

void CANview::timerSubrutine(){
    qDebug() << "TimerEvent" << u2c->tim_counter++;
    if(u2c->tim_counter >= 4){
        u2c->tim_counter = 0;
        u2c->tim->stop();
    }
}

