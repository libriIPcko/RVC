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

    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QString s = QObject::tr("Port: ") + info.portName() + "\n"
                    //+ QObject::tr("Location: ") + info.systemLocation() + "\n"
                    //+ QObject::tr("Description: ") + info.description() + "\n"
                    //+ QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                    + QObject::tr("Serial number: ") + info.serialNumber();
                    //+ QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                    //+ QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n";
                   // + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";
        ui->TX_textEdit->append(s);
    }

}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_dataReceived(QByteArray data){
    //ui->RX_textEdit->append(QString::fromLatin1(data));
    QString HtS;// = QByteArray::fromHex(data.at(4));
    QByteArray temp;
    //HtS = QByteArray::fromHex(data.at(1));
    uchar c;
    for(int i=0;i<data.size();i++){
        c = data.at(i);
        HtS.append(QString("%1").arg(c,2,16,QChar('0')));
    }
    qDebug() << "RX: "<< "RAW: " <<data << "fromHex: "<< QByteArray::fromHex(data) << "HtS: " <<HtS;
    ui->RX_textEdit->append(HtS);
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
        //u2c->init();

        if(u2c->port_USB2CAN->isOpen()){
            qDebug() << "port is open? "<< u2c->port_USB2CAN->isOpen() << "Port name:" << ui->lineEdit->text();
        }
    }
    else{                                                   //connectButton == false
        u2c->port_USB2CAN->close();
        qDebug() << "Close port" << !u2c->port_USB2CAN->isOpen();
        ui->pushButton->setText("Disconnected");
    }
}

void MainWindow::on_pushButton_SendBtn_clicked()
{
    QString txt = ui->TX_textEdit->toPlainText();
    if((txt.isEmpty() == 0)||(u2c->isOpen())){
        if(txt.at(0) == '#'){
            menu_sendCommands(txt.sliced(1));
        }
        else{
            qDebug() << "length: " << u2c->SendHex(QByteArray::fromHex(txt.toLocal8Bit()));
            //u2c->SendHex(QByteArray::fromHex(outputTxt.front().toLocal8Bit()));
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
        u2c->SendHex(QByteArray::fromHex(outputTxt.front().toLocal8Bit()));
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
        }
        else if(cmd.compare("init") == 0){
            qDebug() << "Start init" << cmd;
            u2c->init();
        }
        else if(cmd.sliced(0,1).compare("w") == 0){
            if(cmd.size() >= 4){
                u2c->WriteReg(QByteArray::fromHex(cmd.sliced(1,2).toUtf8()),QByteArray::fromHex(cmd.sliced(4).toUtf8()));
            }
            else{
                //CMD is short
                //QColor errorCol = QColor::red();
                ui->TX_textEdit->append("ERROR /cmd is short/");
            }
        }
        else{
            qDebug() << "default cmd" << cmd << QByteArray::fromHex(cmd.toLocal8Bit());
            //hex to char
            QByteArray test = cmd.toLatin1();
            u2c->SendHex(QByteArray::fromHex(cmd.toLocal8Bit()));
        }
    }catch (const std::exception& e) {
        qDebug() << e.what();
    }
}
/*
//pushButton_TX_clean
void MainWindow::on_pushButton_3_released()
{
    ui->TX_textEdit->clear();
}
*/


void MainWindow::on_pushButton_RX_clean_released(){
    ui->RX_textEdit->clear();
}


void MainWindow::on_pushButton_TX_clean_released(){
    ui->TX_textEdit->clear();
}

