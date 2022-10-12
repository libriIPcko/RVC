#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    listSendTimer = new QTimer();
    connect(listSendTimer,SIGNAL(timeout()),this,SLOT(on_timeout_listSendTimer()));
    u2c = new USB2CAN_driver();
    connect(u2c,SIGNAL(dataReceived(QByteArray)),this,SLOT(on_dataReceived(QByteArray)));
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_dataReceived(QByteArray data){
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



//connect disconnect
void MainWindow::on_pushButton_released(){
    connectButton = !connectButton;
    if(connectButton == true){
        ui->pushButton->setText("Connected");
        u2c->connectToPort(ui->lineEdit->text());           //COM5
    }
    else{                                                   //connectButton == false
        u2c->close();
        ui->pushButton->setText("Disconnected");
    }
}

void MainWindow::on_pushButton_SendBtn_clicked()
{
    QString txt = ui->TX_textEdit->toPlainText();
    if((txt.isEmpty() == 0)||(u2c->isOpen())){
        qDebug() << "length: " << u2c->SendString(txt);
    }
}


void MainWindow::on_pushButton_ListSendBtn_released(){
    QString inputTXT = ui->TX_textEdit->toPlainText();
    QString outputTxt_string;
    //find the CR and LF
    for(int i=0; i < inputTXT.length();i++){
        if(inputTXT.at(i) == '\n'){
           //outputTxt.at(pDeque).push_back(inputTXT.at(i));
           //pDeque++;
            outputTxt_string.append(inputTXT.at(i));
            outputTxt.push_back(outputTxt_string);
            outputTxt_string.clear();
        }
        else{
            outputTxt_string.append(inputTXT.at(i));
        }
    }
    //RUN timer or Thread
    listSendTimer->setInterval(800);
    listSendTimer->start();
}

void MainWindow::on_timeout_listSendTimer(){
    if(outputTxt.size() == 0){
        listSendTimer->stop();
    }
    else{
        u2c->SendString(outputTxt.front()); //???
        outputTxt.pop_front();
    }
}
