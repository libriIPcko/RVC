#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphics.h"
#include "canview.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QtSerialPortVersion>
#include <QtSerialPort/QtSerialPortDepends>

//4Test Case var
int temp_count = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    //QMetaObject::connectSlotsByName(MainWindow);

    //port1 = new QSerialPort(this);
    //port2 = new QSerialPort(this);
    u2c = new USB2CAN_driver();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //ui->listView->
    //ui->listView->setAttribute()
    //QtSerialPortInfo::
    //a = QSerialPortInfo("COM7");
    ui->textBrowser->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QString s = QObject::tr("Port: ") + info.portName() + "\n"
                    + QObject::tr("Location: ") + info.systemLocation() + "\n"
                    + QObject::tr("Description: ") + info.description() + "\n"
                    + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                    + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
                    + QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n";
                   // + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";

        //auto label = new QLabel(s);
        //layout->addWidget(label);
        //ui->textBrowser->setPlainText(s);
        ui->textBrowser->append(s);
    }
}

//Delete it !
void MainWindow::on_pushButton_connect2_clicked()
{

}


//Open PORT1
void MainWindow::on_pushButton_connect1_toggled(bool checked)
{
    temp_count++;
    ui->textBrowser_Port1->clear();
    //4GetTxt
   //QSerialPort port1;
    port1 = new QSerialPort(this);
    port1->setBaudRate(ui->plainTextEdit_1_BaudRate->toPlainText().toInt());
    qDebug()<< port1->baudRate();
    //port1->setBaudRate(9600);   //115200        //9600
    //checked = !checked;
    if (checked == 1){
        port1->setPortName(ui->textEdit_Port1->toPlainText());
        port1->setDataBits(QSerialPort::Data8);
        //port1->openMode();
        port1->open(QIODevice::ReadWrite);
        QString data = QString::number(temp_count)+" Check status: "+QString::number(checked)+"\n";
        ui->textBrowser_Port1->insertPlainText(data);
        // qDebug() << QObject::connect(port2,SIGNAL(readyRead()),this,SLOT(readSerial_2()));

        if (port1->isOpen() == 1){
            //opened
            ui->pushButton_connect1->setAutoFillBackground(true);
            QPalette palette = ui->textBrowser_Port1->palette();
            palette.setColor(QPalette::ButtonText,QColor(Qt::green));
            ui->pushButton_connect1->setPalette(palette);
            ui->pushButton_connect1->update();
            ui->pushButton_connect1->setText("Connected");

            qDebug() << QObject::connect(port1,SIGNAL(readyRead()),this,SLOT(readSerial_1()));
        }
        else{
            //error, or closed
            ui->pushButton_connect1->setAutoFillBackground(true);
            QPalette palette = ui->textBrowser_Port1->palette();
            palette.setColor(QPalette::ButtonText,QColor(Qt::red));
            ui->pushButton_connect1->setPalette(palette);
            ui->pushButton_connect1->update();
            //4TestCase
            ui->textBrowser_Port1->insertPlainText(QString::number(temp_count));
            ui->textBrowser_Port1->insertPlainText(": ");
            ui->textBrowser_Port1->insertPlainText("\t ");
            ui->textBrowser_Port1->insertPlainText("Port Name: ");
            ui->textBrowser_Port1->insertPlainText(ui->textEdit_Port1->toPlainText());
            ui->textBrowser_Port1->insertPlainText("\n");
            //ui->textBrowser_Port1->insertPlainText(port1->);
            ui->textBrowser_Port1->insertPlainText("\tDeviceNotFoundError: ");
            //ui->textBrowser_Port1->insertPlainText(QString::number(QSerialPort::DeviceNotFoundError));
            ui->textBrowser_Port1->insertPlainText(QString::number(port1->DeviceNotFoundError));
            ui->textBrowser_Port1->insertPlainText("\n");
            ui->textBrowser_Port1->insertPlainText("\tOpenError: ");
            ui->textBrowser_Port1->insertPlainText(QString::number(port1->OpenError));
            ui->textBrowser_Port1->insertPlainText("\n");
            ui->textBrowser_Port1->insertPlainText("\tPermissionError: ");
            ui->textBrowser_Port1->insertPlainText(QString::number(port1->PermissionError));
            ui->textBrowser_Port1->insertPlainText("\n");
            port1->clearError();
            port1->close();
        }
    }
    else{
        QString data = QString::number(temp_count)+" Check status: "+QString::number(checked)+"\n";
        ui->textBrowser_Port1->insertPlainText(data);

        port1->close();
        if(port1->isOpen()){
            ui->pushButton_connect1->setText("Conected");
        }
        else {
            QPalette palette = ui->textBrowser_Port1->palette();
            palette.setColor(QPalette::ButtonText,QColor(Qt::black));
            ui->pushButton_connect1->setPalette(palette);
            ui->pushButton_connect1->update();
            ui->pushButton_connect1->setText("Connect");
            port1->close();
        }
    }
}

//Open PORT2
void MainWindow::on_pushButton_connect2_toggled(bool checked)
{
    temp_count++;
    ui->textBrowser_Port2->clear();
    port2 = new QSerialPort(this);
    port2->setBaudRate(ui->plainTextEdit_2_BaudRate->toPlainText().toInt());
    qDebug() << port2->baudRate();
    //port2->setBaudRate(9600);
    //checked = !checked;
    if (checked == 1){
        port2->setPortName(ui->textEdit_Port2->toPlainText());
        port2->setDataBits(QSerialPort::Data8);
        //Port2.openMode();
        port2->open(QIODevice::ReadWrite);
        QString data = QString::number(temp_count)+" Check status: "+QString::number(checked)+"\n";
        ui->textBrowser_Port2->insertPlainText(data);

        if (port2->isOpen() == 1){
            //opened
            ui->pushButton_connect2->setAutoFillBackground(true);
            QPalette palette = ui->textBrowser_Port2->palette();
            palette.setColor(QPalette::ButtonText,QColor(Qt::green));
            ui->pushButton_connect2->setPalette(palette);
            ui->pushButton_connect2->update();
            ui->pushButton_connect2->setText("Connected");

            //qDebug() << QObject::connect(port2,SIGNAL(readyRead()),this,SLOT(readSerial2));
            qDebug() << QObject::connect(port2,SIGNAL(readyRead()),this,SLOT(readSerial_2()));


        }
        else{
            //error, or closed
            ui->pushButton_connect2->setAutoFillBackground(true);
            QPalette palette = ui->textBrowser_Port2->palette();
            palette.setColor(QPalette::ButtonText,QColor(Qt::red));
            ui->pushButton_connect2->setPalette(palette);
            ui->pushButton_connect2->update();
            //4TestCase
            ui->textBrowser_Port2->insertPlainText(QString::number(temp_count));
            ui->textBrowser_Port2->insertPlainText(": ");
            ui->textBrowser_Port2->insertPlainText("\t ");
            ui->textBrowser_Port2->insertPlainText("Port Name: ");
            ui->textBrowser_Port2->insertPlainText(ui->textEdit_Port2->toPlainText());
            ui->textBrowser_Port2->insertPlainText("\n");
            //ui->textBrowser_Port2->insertPlainText(Port2.);
            ui->textBrowser_Port2->insertPlainText("\tDeviceNotFoundError: ");
            //ui->textBrowser_Port2->insertPlainText(QString::number(QSerialPort::DeviceNotFoundError));
            ui->textBrowser_Port2->insertPlainText(QString::number(port2->DeviceNotFoundError));
            ui->textBrowser_Port2->insertPlainText("\n");
            ui->textBrowser_Port2->insertPlainText("\tOpenError: ");
            ui->textBrowser_Port2->insertPlainText(QString::number(port2->OpenError));
            ui->textBrowser_Port2->insertPlainText("\n");
            ui->textBrowser_Port2->insertPlainText("\tPermissionError: ");
            ui->textBrowser_Port2->insertPlainText(QString::number(port2->PermissionError));
            ui->textBrowser_Port2->insertPlainText("\n");
        }
    }
    else{
        QString data = QString::number(temp_count)+" Check status: "+QString::number(checked)+"\n";
        ui->textBrowser_Port2->insertPlainText(data);

        port2->close();
        if(port2->isOpen()){
            ui->pushButton_connect2->setText("Connected");
        }
        else {
            QPalette palette = ui->textBrowser_Port2->palette();
            palette.setColor(QPalette::ButtonText,QColor(Qt::black));
            ui->pushButton_connect2->setPalette(palette);
            ui->pushButton_connect2->update();
            ui->pushButton_connect2->setText("Connect");
            port2->close();
        }
    }
}


void MainWindow::on_pushButton_port1_clear_clicked()
{
    ui->textBrowser_Port1->clear();
}


void MainWindow::on_pushButton_port2_clear_clicked()
{
    ui->textBrowser_Port2->clear();
}

//send port1
void MainWindow::on_pushButton_4_clicked()
{
    QString txt = ui->textBrowser_Port1->toPlainText();
    qsizetype i = 0;
    if(txt.at(i) == QChar('x') || txt.at(i) == QChar('X')){
        qDebug()<<"Hex code has been detected" << txt;
        //bool ok;

        QByteArray tst;
        QString dat;

        for(qsizetype i = 0;i<txt.length();i++){
            if(txt.at(i) == QChar('x') || txt.at(2) == QChar('X')){
                dat = txt.sliced(++i,2);
                //qDebug() << dat << QByteArray::fromHex(dat.toLatin1());
                while(!port1->waitForBytesWritten(300)){
                    port1->write(QByteArray::fromHex(dat.toLatin1()));
                }
            }
        }
        //qDebug() << dat <<dat.toUInt(&ok,16);

    }
    //Commands separation
    else if(txt.at(0) == QChar('#')){
        i = 1;
        txt = txt.sliced(i);

        if(QString::compare(txt,"getmode") == 0){
           static const char initData[] = {
                '\x0f', '\x06' , '\x00'
            };
            QByteArray sendData = QByteArray::fromRawData(initData,sizeof (initData));

            while(!port1->waitForBytesWritten(300)){
                port1->write(sendData );
                qDebug() << sendData;
            }
            qDebug() << "Get mode command" << sendData;
        }
        else if(QString::compare(txt,"readreg") == 0){  //Implement asking from fine adresse
           static const char initData[] = {
                '\x0f', '\x12' , '\x00'
            };
            QByteArray sendData = QByteArray::fromRawData(initData,sizeof (initData));

            while(!port1->waitForBytesWritten(300)){
                port1->write(sendData );
            }
            qDebug() << "Read reg command" << sendData;
        }

        else if(QString::compare(txt,"init") == 0){
            u2c->init();
            /*
            Timer_sendLine = new QTimer(this);
            Timer_sendLine->setInterval(250);
            Timer_sendLine->setSingleShot(false);
            qDebug() << QObject::connect(Timer_sendLine,SIGNAL(timeout()),this,SLOT(SendNextRow_InitUSB2CAN()));
            Timer_sendLine->start();
            incLine = 0;
            */
        }

        else if(QString::compare(txt,"busoff") == 0){
            static const char stopCMD[] = {
                 '\x0f', '\x08' , '\x00'
             };
             QByteArray sendData = QByteArray::fromRawData(stopCMD,sizeof (stopCMD));

             while(!port1->waitForBytesWritten(300)){
                 port1->write(sendData );
             }
             qDebug() << "Bus Off status command" << sendData;
        }

        else if(QString::compare(txt,"normal") == 0){
            static const char stopCMD[] = {
                 '\x0f', '\x03' , '\x00'
             };
             QByteArray sendData = QByteArray::fromRawData(stopCMD,sizeof (stopCMD));

             while(!port1->waitForBytesWritten(300)){
                 port1->write(sendData );
             }
             qDebug() << "Normal mode command sent" << sendData;
        }
        else if(QString::compare(txt,"config") == 0){
            static const char stopCMD[] = {
                 '\x0f', '\x02' , '\x00'
             };
             QByteArray sendData = QByteArray::fromRawData(stopCMD,sizeof (stopCMD));

             while(!port1->waitForBytesWritten(300)){
                 port1->write(sendData );
             }
             qDebug() << "Config mode command sent" << sendData;
        }
        else if(QString::compare(txt,"reset") == 0){
            static const char stopCMD[] = {
                 '\x0f', '\x12' , '\x02', '\x00', '\x01'
             };
             QByteArray sendData = QByteArray::fromRawData(stopCMD,sizeof (stopCMD));

             while(!port1->waitForBytesWritten(300)){
                 port1->write(sendData );
             }
             qDebug() << "Reset command sent" << sendData;
        }


        else{
            qDebug()<< "Command does not exist";
        }
    }
    else if (txt.at(0) == QChar('!')) {
        if(QString::compare(txt,"getmode") == 0){
            u2c->Get_Mode();
        }
        else{
            u2c->write(txt.sliced(1).toLatin1());
            //u2c->write("hey");
        }
    }

    else{
        QByteArray data = txt.toUtf8();
        while(!port1->waitForBytesWritten(300)){
            port1->write(data);
        }
    }

}

//Send port2
void MainWindow::on_pushButton_5_clicked()
{
    QString txt = ui->textBrowser_Port2->toPlainText();
    qsizetype i = 0;
    if(txt.at(i) == QChar('x') || txt.at(i) == QChar('X')){
            qDebug()<<"Hex code has been detected";
            bool ok;

            QByteArray tst;
            QString dat;
            for(qsizetype i = 0;i<txt.length();i++){
                if(txt.at(i) == QChar('x') || txt.at(2) == QChar('X')){
                    dat = txt.sliced(++i,2);
                    uint8_t parsedData = dat.toUInt(&ok,16);

                    while(!port2->waitForBytesWritten(300)){
                        port2->write(tst.setNum(parsedData));
                    }
                    //qDebug() << dat << "-" << parsedData << "-" << i <<"/" << txt.length();
                }
            }

    }
    else{
        QByteArray data = txt.toUtf8();
        port2->write(data);
    }


}


void MainWindow::on_pushButton_2_clicked()
{
    Graphics gr;
    gr.setModal(true);
    gr.exec();
}

//Send packet list
void MainWindow::on_pushButton_3_clicked()
{
    for(int n=0;n<300;n++){
        txtLineByLine[n].clear();
    }
    int countChar = 0;
    QString txt = ui->textBrowser_Port1->toPlainText();
    char text[txt.length()];

    //Separating strings line by line
    while(countChar < ui->textBrowser_Port1->toPlainText().length()){
        text[countChar] = txt.at(countChar).toLatin1();
        if(text[countChar] == '\n'){
            txtLineByLine[countLine].append("\n");
            //qDebug() << "txtLineByLine:" << txtLineByLine[countLine];
            countLine++;
        }
        else{
            txtLineByLine[countLine].append(text[countChar]);
        }
        countChar++;
    }

    Timer_sendLine = new QTimer(this);
    Timer_sendLine->setInterval(1300);
    Timer_sendLine->setSingleShot(false);
    qDebug() << QObject::connect(Timer_sendLine,SIGNAL(timeout()),this,SLOT(SendNextRow()));
    //QObject::connect(Timer_sendLine,Timer_sendLine->timeout(),MainWindow::SendNextRow());
    //QObject::connect(Timer_sendLine,timeout(),SendNextRow());
    Timer_sendLine->start(1300);

}

//Write is correct
void MainWindow::SendNextRow(){
    //QString txtLineByLine[300];
    QByteArray data = txtLineByLine[incLine].toUtf8();
    //int64_t err = 0;
        //port1->write(data);

    /*
    while(!port1->waitForBytesWritten(400)){
        qDebug() << incLine << " - " << data << " - " << port1->write(data);
    }
    */

    qDebug() << incLine << " - " << data << " - " << port1->write(data);

    //qDebug() << incLine << " - " << txtLineByLine[incLine].toLocal8Bit();
    //qDebug() << incLine << " - " << data;

    incLine++;
    if(incLine >= countLine){
        incLine = 0;
        countLine = 0;
        Timer_sendLine->stop();
    }
}

//Error in receive signal or slot
void MainWindow::readSerial_2(){
    //ui->textBrowser_Port2->setPlainText("Received: ");
    //ui->textBrowser_Port2->setPlainText(port2->readAll());
    QString ReadData = port2->readAll();
    qDebug() << "Received_port2" << ReadData;
    //ui->textBrowser_Port2->setTextColor(QColor(0,0,255));
    //ui->textBrowser_Port2->setPlainText(ReadData + "\n");
    //ui->textBrowser_port2_RX->setPlainText(ReadData + "\n");
    ui->textBrowser_port2_RX->append(ReadData);
    //ui->textBrowser_Port2->setTextColor(QColor(255,255,255));


}

void MainWindow::readSerial_1(){
    bool ok;
    QByteArray ReadData = port1->readAll();
    //QString ArrivedData = QString::number(ReadData.fromHex(ReadData),10);
    QString ArrivedData;

  //ArrivedData = QString::fromUtf8((char*)ReadData.data());
    ArrivedData = ReadData.data();
    //qDebug() << "Received_port1: " << QByteArray::fromHex(ReadData);

    //ui->textBrowser_port1_RX->append(QByteArray::fromHex(ReadData) );
    //ui->textBrowser_port1_RX->append(ReadData);
    //QByteArray tst = ReadData.fromHex(ReadData);
    //QString tst = ReadData.fromHex(ReadData);
    //QString tst = ReadData.fromHex(ReadData);
    //QString tst = ReadData;
    ui->textBrowser_port1_RX->append(ArrivedData.toLatin1());
    qDebug() << "Received_port1: " << ReadData << "--" <<  ArrivedData;
}

void MainWindow::on_pushButton_6_released()
{
    //Graphics gr;
    CANview viewCAN;
    viewCAN.setModal(true);
    viewCAN.exec();
}


void MainWindow::on_pushButton_port1_RX_clear_clicked(bool checked)
{
    ui->textBrowser_port1_RX->clear();
}


void MainWindow::on_pushButton_port2_RX_clear_clicked(bool checked)
{
    ui->textBrowser_port2_RX->clear();
}


void MainWindow::SendNextRow_InitUSB2CAN()
{
    /*
    QByteArray sendData;
    qint64 feedback;
    //For Set value is used command WriteReg-[0x12]  - EXCEPT FOR 1.8.9. step
    switch (incLine){
        case 0:
            //1-Set to Config Mode [0x02]
                static const char Config[] = {
                     '\x0f', '\x02' , '\x00', '\x00'
                 };
                 sendData = QByteArray::fromRawData(Config,sizeof (Config));
                 while(!port1->waitForBytesWritten(300)){
                     feedback = port1->write(Config);
                 }
                 qDebug() << incLine << "-"  << "Config Mode" << "-"  << feedback << "-"  << Config;
        break;
        case 1:
            //2-Set Reset Mode [0x00]on value 0x01   (by WriteReg[x12])
                static const char ResetMod[] = {
                  '\x0f','\x12','\x02','\x00','\x01'
                };
                sendData = QByteArray::fromRawData(ResetMod,sizeof (ResetMod));
                while(!port1->waitForBytesWritten(300)){
                  feedback = port1->write(sendData);
                }
                qDebug() << incLine << "-"  << "Reset Mode" << "-"  << feedback << "-"  << ResetMod;
        break;
        case 2:
            //3-Set Clock divider [0x1F] on value 0xC0 (by WriteReg[x12])
                static const char ClockDivData[] = {
                   '\x0f','\x12','\x02','\x1F','\xC0'
                };
                sendData = QByteArray::fromRawData(ClockDivData,sizeof (ClockDivData));
                while(!port1->waitForBytesWritten(300)){
                   feedback = port1->write(sendData);
                }
                qDebug() << incLine << "-"  << "Clock divider data" << "-"  << feedback << "-"  << ClockDivData;
        break;
        case 3:
            //4.1-Set message filter; without filtration: (by WriteReg[x12])
            //set-> Acceptance Code [?] on 0x00
                static const char AccCode[] = {
                    '\x0f','\x12','\x02','\x10','\x00'
                };
                sendData = QByteArray::fromRawData(AccCode,sizeof (AccCode));
                while(!port1->waitForBytesWritten(300)){
                    feedback = port1->write(sendData);
                }
                qDebug() << incLine << "-" << "Acceptance Code" << "-"  << feedback << "-"  << AccCode;
        break;
        case 4:
            //4.2 set-> Acceptance Mask [0x05] on 0xff
                static const char AccMask[] = {
                 '\x0f', '\x12', '\x02' , '\x14' , '\xff'
                };
                sendData = QByteArray::fromRawData(AccMask,sizeof (AccMask));
                while(!port1->waitForBytesWritten(300)){
                    feedback = port1->write(sendData);
                }
                qDebug() << incLine << "-" << "Acceptance Mask" << "-"  << feedback << "-"  << AccMask;

        break;
        case 5:
            //5-Set OutputControl[0x08] on 0xDA (by WriteReg[x12])
                static const char OutCtrl[] = {
                  '\x0f','\x12','\x02','\x08','\xDA'
                };
                sendData = QByteArray::fromRawData(OutCtrl,sizeof (OutCtrl));
                while(!port1->waitForBytesWritten(300)){
                  feedback = port1->write(sendData);
                }
                qDebug() << incLine << "-" << "Output Control" << "-"  << feedback << "-"  << OutCtrl;
        break;
        case 6:
            //7. -Set Interrupt enable[]  on 0x03  (by WriteReg[x12])
                static const char IE[] = {
                    '\x0f','\x12','\x02','\x04','\x03'
                };
                sendData = QByteArray::fromRawData(IE,sizeof (IE));
                while(!port1->waitForBytesWritten(300)){
                    feedback = port1->write(sendData);
                }
                qDebug() << incLine << "-" << "Interrupt enable" << "-"  << feedback << "-"  << IE;
        break;
        case 7:
            //6.1 - Bus Timing 0
                static const char BT0[] = {
                     '\x0f','\x12','\x02','\x06','\x00'
                 };
                 sendData = QByteArray::fromRawData(BT0,sizeof (BT0));
                 while(!port1->waitForBytesWritten(300)){
                     feedback = port1->write(sendData);
                 }
                 qDebug() << incLine << "-" << "Bus Timing 0" << "-"  << feedback << "-"  << BT0;
        break;
        case 8:
            //6.2 - Bus Timing 1
                static const char BT1[] = {
                     '\x0f','\12','\x02','\x07','\x14'
                 };
                 sendData = QByteArray::fromRawData(BT1,sizeof (BT1));
                 while(!port1->waitForBytesWritten(300)){
                     feedback = port1->write(sendData);
                 }
                 qDebug() << incLine << "-" << "Bus Timing 1" << "-"  << feedback << "-"  << BT1;
        break;

                 //Here are some data

        case 9:
            //8.-Set Transmit Critical Limit and Transmit Ready limit by cmd COMMAND
            //8.1 Set TCL
                static const char CTL_Code[] = {
                     '\x0f','\x20','\x01','\x18'
                 };
                 sendData = QByteArray::fromRawData(CTL_Code,sizeof (CTL_Code));
                 while(!port1->waitForBytesWritten(300)){
                     feedback = port1->write(sendData);
                 }
                 qDebug() << incLine << "-" << "CTL_Code" << "-"  << feedback << "-"  << CTL_Code;
        break;
        case 10:
            //8.2 Set-> TRL
                static const char TRL_Code[] = {
                     '\x0f','\x20','\x02','\x01'
                 };
                 sendData = QByteArray::fromRawData(TRL_Code,sizeof (TRL_Code));
                 while(!port1->waitForBytesWritten(300)){
                     feedback = port1->write(sendData);
                 }
                 qDebug() << incLine << "-" << "TRL_Code" << "-"  << feedback << "-"  << TRL_Code;
        break;
        case 11:
            //9-Set Normal Mode
                static const char NormalMode[] = {
                   '\x0f','\x03','\x00'
                };
                sendData = QByteArray::fromRawData(NormalMode,sizeof (NormalMode));
                while(!port1->waitForBytesWritten(300)){
                   feedback = port1->write(sendData);
                }
                qDebug() << incLine << "-" << "Normal Mode" << "-"  << feedback << "-"  << NormalMode;
        break;
        case 12:
            //10-Set Mode register [0x00], the value depends on Message Filter   (by WriteReg[x12])
            //values can be 0x00 or 0x08
               static const char ModRegDat[] = {
                    '\x0f','\x12','\x02','\x00','\x00'
                };
                sendData = QByteArray::fromRawData(ModRegDat,sizeof (ModRegDat));
                while(!port1->waitForBytesWritten(300)){
                    feedback = port1->write(sendData);
                }
                qDebug() << incLine << "-" << "Set Mode" << "-"  << feedback << "-"  << ModRegDat;
        break;
    }
    if(incLine>12){
        //After this steps is possible sending and receiving the CAN messages
        qDebug() << "Init command" << sendData;
        Timer_sendLine->stop();
        incLine = 0;
    }
    else{
        incLine++;
    }
    */
}


void MainWindow::on_checkBox_toggled(bool checked)
{
    if(checked == 1){
        qDebug() << ui->textEdit_Port1->toPlainText() << "Status of open COMport" << u2c->connectToPort(ui->textEdit_Port1->toPlainText());
    }
    else{
        qDebug() << "Status of open COMport {1...open/0...close}" << u2c->disconnectedFromPort();
    }
}

