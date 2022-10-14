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
    ui->RX_textEdit->append(QString::fromLatin1(data));
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
        u2c->connectToPort(ui->lineEdit->text(),9600);           //COM5
        u2c->init();
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

        if(txt.at(0) == '#'){
            //qDebug() << "length: " << u2c->SendString(txt.sliced(1));
            menu_sendCommands(txt.sliced(1));
        }
        else{
            qDebug() << "length: " << u2c->SendString(txt);
        }


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

void MainWindow::menu_sendCommands(QString cmd){
    //Commands:

    try {
        if(cmd.sliced(0,3).compare("msg") == 0){
            qDebug() << "msg cmd" << cmd << cmd.sliced(3) << QByteArray::fromHex(cmd.sliced(3).toLocal8Bit());
            //hex to char
            QByteArray test = cmd.sliced(3).toLatin1();
            u2c->SendHex(QByteArray::fromHex(cmd.sliced(3).toLocal8Bit()));
            //u2c->SendString(QByteArray::fromHex(cmd.sliced(3).toLocal8Bit()));

        }
        else if(cmd.sliced(0,6).compare("test_1") == 0){
            qDebug() << "test_1 cmd" << cmd << cmd.sliced(6);
            u2c->SendString(cmd.sliced(6).toLatin1());
            //
        }
    } catch (const std::exception& e) {
        qDebug() << e.what();
    }
}
