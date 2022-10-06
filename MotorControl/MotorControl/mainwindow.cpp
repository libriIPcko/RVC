#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    u2c = new USB2CAN_driver();
    connect(u2c,SIGNAL(dataReceived(QByteArray)),this,SLOT(on_dataReceived(QByteArray)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dataReceived(QByteArray data){
    //ui->RX_textBrowser.setTxt(QString::fromLatin1(data));
    ui->RX_textEdit->setText(QString::fromLatin1(data));

}

bool MainWindow::event(QEvent *event){
    if(event->type() == QEvent::Resize){
        ui->tabWidget->resize(ui->centralwidget->size());
        return true;
    }
    else if(event->type() == QEvent::Close){
        u2c->close();

    }
    return QMainWindow::event(event);
}




void MainWindow::on_pushButton_released(){
    qDebug() << ui->lineEdit->text();
    connectStatus = u2c->connectToPort(ui->lineEdit->text()); //COM5
    qDebug() << connectStatus;
    if(connectStatus == true){
        ui->pushButton->setText("Initializing");
        if(u2c->init()){
            ui->pushButton->setText("Initialized");
        }
        else{
            ui->pushButton->setText("Non-Initialized");
        }
    }
    else if(connectStatus == false){
        u2c->close();
        if(u2c->isOpen()){
            connectStatus = false;
            ui->pushButton->setText("Disconnected");
        }

    }
    else{
        qDebug() << "ERROR";
    }
}



/*
void MainWindow::on_pushButton_Send_released()
{
    if(u2c->isOpen()){
        qDebug() << "length: " << u2c->SendString(ui->TX_textEdit->toPlainText());

    }
    else{
        qDebug() << "ERROR - device is not open...";
    }

}
*/

void MainWindow::on_pushButton_SendBtn_clicked()
{
    qDebug() << "length: " << u2c->SendString(ui->TX_textEdit->toPlainText());

    /*
    if(u2c->isOpen()){
        qDebug() << "length: " << u2c->SendString(ui->TX_textEdit->toPlainText());

    }
    else{
        qDebug() << "ERROR - device is not open...";
    }
    */
}

