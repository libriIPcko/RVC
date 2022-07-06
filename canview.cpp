#include "canview.h"
#include "ui_canview.h"

CANview::CANview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CANview)
{
    ui->setupUi(this);
    u2c = new USB2CAN_driver;
}

CANview::~CANview()
{
    delete ui;
}
//for commit
void CANview::on_connectPort_released()
{
    qDebug() << "u2c some port is open" << u2c->connectToPort(ui->inputNamePort->text());
    qDebug() << "port_USB2CAN is open " << u2c->port_USB2CAN->isOpen();

    if(u2c->isOpen()){
        ui->connectPort->setCheckState(Qt::CheckState::Checked);
        QObject::connect(u2c,SIGNAL(readyRead()),this,SLOT(QByteArray read_u2c()));
        if(u2c->isOpen()){
            ui->connectPort->setCheckState(Qt::CheckState::Checked);
        }
        else{
            ui->connectPort->setCheckState(Qt::CheckState::Unchecked);
        }
    }
    else{
        ui->connectPort->setCheckState(Qt::CheckState::Unchecked);
    }
}


void CANview::on_pushButton_released()
{
    u2c->write(ui->TX_textBrowser->toPlainText().toLatin1(),static_cast<int>(ui->TX_textBrowser->toPlainText().length()));
}

QByteArray CANview::read_u2c(){
    ui->RX_textBrowser_2->setPlainText(u2c->readAll());
    return u2c->readAll();
}

