#include "radar_awr1843.h"
#include "QCoreApplication"
#include "QFile"
#include "QTextStream"
#include <list>
#include <iostream>
#include <stdio.h>
#include <QDir>
#include <QTimer>

RADAR_AWR1843::RADAR_AWR1843(QObject *parent) //: QThread(parent)
{
    port_AUXILIARY = new QSerialPort;
    port_COMM = new QSerialPort;
    qDebug() << "RX_radar_data File status open: " << RX_radar_data->open(QIODevice::ReadWrite);
    qDebug() << "DebugLog File status open: " << DebugLog->open(QIODevice::ReadWrite);
}
RADAR_AWR1843::~RADAR_AWR1843(){
    PortDisconnect();
    RX_radar_data->close();
    //tim->destroyed();
}

                                                                                              //Not used
int RADAR_AWR1843::initialization(QString path){
    ReadConfigCMD(path,temporary_arrayCMD);
    marker = 0;
        //Stop RX
        //QObject::connect(port_COMM,SIGNAL(readyRead()),this,SLOT(port_COMM_receive()));
        //QObject::connect(port_AUXILIARY,SIGNAL(readyRead()),this,SLOT(port_AUXILIARY_receive()));

    //QObject::connect(tim_debug,SIGNAL(timeout()),this,SLOT(tim_debug_handler()));

    RX_radar_data->open(QIODevice::ReadWrite | QFile::Append);


    tim_debug->start(tim_debug_period);
    return 0;
}


void RADAR_AWR1843::tim_debug_handler(){
    //qDebug() << "stopwatch";
    qDebug() << "line: " << marker;
    tim_debug->stop();
    if(marker == 0){
        QFile debug_file("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/deb.txt");
        debug_file.open(QIODevice::WriteOnly);
        QTextStream outstr(&debug_file);
        outstr << "";
        debug_file.close();
        send_COMM(temporary_arrayCMD[marker]);
        QObject::connect(watchdog_RX,SIGNAL(timeout()),this,SLOT(watchdog_RX_handler()));

        watchdog_RX->start(watchdog_RX_period);
        marker++;
    }
    else if(marker>=29){
        tim_debug->stop();
        watchdog_RX->stop();
        disconnect(tim_debug);
        qDebug() << "End of Init";
        qDebug() << stopwatch.currentTime();
        //port_COMM->close();
        //port_AUXILIARY->close();

    }
    else{
        //qDebug () << "Error during sending:" << send_COMM(temporary_arrayCMD[marker]);
        send_COMM(temporary_arrayCMD[marker]);
        watchdog_RX->stop();
        QFile debug_file("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/deb.txt");
        debug_file.open(QIODevice::ReadWrite | QFile::Append | QFile::Text);
        QTextStream out(&debug_file);
        out << marker << " --- " << temporary_arrayCMD[marker] << "\n";
        debug_file.close();

        QObject::connect(watchdog_RX,SIGNAL(timeout()),this,SLOT(watchdog_RX_handler()));
        watchdog_RX->start(watchdog_RX_period);
        marker++;
    }


}


int RADAR_AWR1843::ReadConfigCMD(QString path,std::array<QString, 60> txtLines){
    //Read from .txt  file
        QFile configFile(path);
        if(!configFile.open(QIODeviceBase::ReadOnly)){
            qCritical() << "ERROR during open the file at path:" << path;
            return 1;
        }
        else{
            //qDebug() << "File has been open...";
        }
    //Save to txt block
        QTextStream stream(&configFile);
        QString all_txt;
        QString txt;
        QString line;
        //std::list<QString> txtLines;
        all_txt = stream.readAll();
        //count lines & fill list by QString lines without header
            int countLines = 0;
            int iterator = 0;
            int DebugVar = all_txt.length();
            while (iterator < all_txt.length()) {
                if(all_txt.at(iterator) == '\n' ){
                    //txtLines.push_back(txt);
                    if(txt.at(0) != '%'){   //filtered RAW data without header
                        //txtLines[countLines] = txt;
                        temporary_arrayCMD[countLines] = txt;
                        countLines++;
                    }
                     txt.clear();
                }
                else{
                    txt.append(all_txt.at(iterator));
                }
                iterator++;
            }
}

int RADAR_AWR1843:: init(QString path){
//Read from .txt  file
    QFile configFile(path);
    if(!configFile.open(QIODeviceBase::ReadOnly)){
        qCritical() << "ERROR during open the file at path:" << path;
        return 1;
    }
    else{
        //qDebug() << "File has been open...";
    }
//Save to txt block
    QTextStream stream(&configFile);
    QString all_txt;
    QString txt;
    QString line;

    //std::list<QString> txtLines;
    all_txt = stream.readAll();
    std::array<QString, 60> txtLines;
    //count lines & fill list by QString lines without header
        int countLines = 0;
        int iterator = 0;
        int DebugVar = all_txt.length();
        while (iterator < all_txt.length()) {
            if(all_txt.at(iterator) == '\n' ){
                //txtLines.push_back(txt);
                if(txt.at(0) != '%'){   //filtered RAW data without header
                    txtLines[countLines] = txt;
                    countLines++;
                }
                 txt.clear();
            }
            else{
                txt.append(all_txt.at(iterator));
            }
            iterator++;
        }
//Iteration line for direct sending
    //Direct sending by COMM port to the empy array item
        if(port_COMM->isOpen()){
            QString path_feedbackFile = "C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/fb_data.txt";
            QFile feedbackFile(path_feedbackFile);
            if((!feedbackFile.isOpen())&&(!feedbackFile.open(QIODeviceBase::ReadWrite))){
                qCritical() << "ERROR during open the file at path:" << path_feedbackFile;
                return 1;
            }
            else{
                //qDebug() << "File has been open...";
                for(int i=0;i<countLines;i++){
                    QString tst = txtLines[i];
                    QTextStream str(&feedbackFile);
                    str << i << " --- " <<txtLines[i];
                    if(!port_COMM->waitForBytesWritten(1)){
                        qDebug() << "\n" << i << "---" << port_COMM->write(tst.toUtf8()+"\n")<<"/"<< tst.length() << " --- " << tst;
                    }
                    QString receive;
                    if(port_COMM->waitForReadyRead(600)){
                        receive.append(port_COMM->readLine());
                        //qDebug() << port_COMM->readLine();
                    }
                    else{
                        str << "\t\t\t --> " << "Nop\n";
                    }
                    str << "\tRX: " << receive;
                    receive.clear();
                }
            }
        }


//Close .cfg file
      configFile.close();
      return 0;
}

//@ Direct send data
int RADAR_AWR1843::send_COMM(QString data){
    port_COMM->flush();
    qint64 lengthWrittenData = 0;
    while(!port_COMM->waitForBytesWritten(10)){
        lengthWrittenData = port_COMM->write(data.toUtf8());
    }
        if(lengthWrittenData == data.toUtf8().length()){
            return 0;   //all is OK
        }
        else if(lengthWrittenData > data.toUtf8().length()){
            return 1;   //It was write more than data contain
        }
        else if(lengthWrittenData < data.toUtf8().length()){
            return 2;   //I was write less than data contain
        }
        else{
            return 99;  //Non possible statement
        }
}


int RADAR_AWR1843::PortConnect(QString portName, int BaudRate, QString typePort){
    //@portName == COM14 or COM15
    //@typePort == AUX for AUXILIARY port
    //@typePort == COM for COMMUNICATION port
    if(QString::compare(typePort,"AUX",Qt::CaseInsensitive) == 0){
        port_AUXILIARY->setPortName(portName);
        port_AUXILIARY->setBaudRate(BaudRate);
        return port_AUXILIARY->open(QIODevice::ReadOnly);
    }
    else if(QString::compare(typePort,"COM",Qt::CaseInsensitive) == 0){
        port_COMM->setPortName(portName);
        port_COMM->setBaudRate(BaudRate);
        return port_COMM->open(QIODevice::ReadWrite);
    }
    else{   //default settings COM14 and COM15
        return 1;   //Error statement
    }
}


int RADAR_AWR1843::PortDisconnect(QString typePort){
    //@typePort == AUX for AUXILIARY port
    //@typePort == COM for COMMUNICATION port
    //@return 2 == Port was closed
    //@return 1 == Port is closed
    if(QString::compare(typePort,"AUX")){
        bool closeStatus = !port_AUXILIARY->isOpen();
        if(closeStatus == false){
            port_AUXILIARY->disconnect();
            port_AUXILIARY->close();
            return 0;
        }
        else{
            return 2;
        }
    }
    else if(QString::compare(typePort,"COM")){
        bool closeStatus = !port_COMM->isOpen();
        if(closeStatus == false){
            port_COMM->disconnect();
            port_COMM->close();
            return 0;
        }
        else{
            return 2;
        }
    }
    else{
        PortDisconnect();
        return 0;
    }
}

int RADAR_AWR1843::PortDisconnect(){
    bool closeStatus_AUX = !port_AUXILIARY->isOpen();
    bool closeStatus_COMM = !port_COMM->isOpen();

    if(closeStatus_AUX == false){
        port_AUXILIARY->disconnect();
        port_AUXILIARY->close();
    }
    if(closeStatus_COMM == false){
        port_COMM->disconnect();
        port_COMM->close();
    }

    if((closeStatus_AUX == false)&&(closeStatus_COMM == false)){
        return 1;   //error statement
    }
    else{
        return 0;   //close was sucesfull
    }

}

//without catch statement
int RADAR_AWR1843::connect(){
    //Default path
        //COM 3 - APP\User UART
        //COM 4 - AUxiliary Data Port
    int status = 0;
    status = PortConnect("COM14",port_COMM_baudRate,"COM");
    status = status + PortConnect("COM15",port_AUXILIARY_baudRate,"AUX");
    return status;
}

int RADAR_AWR1843::port_COMM_receive(){
    RX = port_COMM->readAll();
    if(RX.isEmpty()){
        return 1;
    }
    else{
        watchdog_RX->stop();
        QFile debug_file("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/deb.txt");
        debug_file.open(QIODevice::ReadWrite | QFile::Append | QFile::Text);
        QTextStream out(&debug_file);
        out << "\nRX:\t " << RX <<"\n";
        debug_file.close();
        tim_debug->start(tim_debug_period);
    }
}

void RADAR_AWR1843::watchdog_RX_handler(){
    tim_debug->start(tim_debug_period);
    qDebug() << "Nothing received";
    /*
    QFile debug_file("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/deb.txt");
    debug_file.open(QIODevice::ReadWrite | QFile::Append | QFile::Text);
    QTextStream out(&debug_file);
    out << marker << " --- " << temporary_arrayCMD[marker] << "\nRX:\t Nothing received\n";
    //out << marker << " --- " << temporary_arrayCMD[marker] <<"\n";
    debug_file.close();
    */
    /*
    marker = 29;
    tim_debug->start(tim_debug_period);
    qDebug() << "Nothing receive";
    */
}

int RADAR_AWR1843::port_AUXILIARY_receive(){
    //QFile RX_radar_data("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/RX_radar_data.txt");
    //RX_radar_data->open(QIODevice::ReadWrite | QFile::Append | QFile::Text);    
    QTextStream DebugLogStream(DebugLog);

    QByteArray RX_byte_array = port_AUXILIARY->readAll();
    DebugLogStream << RX_byte_array.length();
    QString RX = RX_byte_array.toHex();
    if(!RX.contains("0201040306050807")){
        RX_byte_array.clear();
    }
    else{
        QTextStream out(RX_radar_data); //assign file to txtStream
        //out << RX_byte_array.toHex() << "\n\n";
        out << RX_byte_array.toHex();
        qDebug() << "\n\t\t\t" << stopwatch.msec()<< RX_byte_array.toHex();

        //out << marker << " --- " << temporary_arrayCMD[marker] << "\nRX:\t Nothing received\n";
        //out << marker << " --- " << temporary_arrayCMD[marker] <<"\n";
        //RX_radar_data.close();
    }    
}
int RADAR_AWR1843::DEBUG_allignData_fromFile(){
    QTextStream inputStream(DebugLog);
    QByteArray sync = "0201040306050807";
    int dataCounter = 0;
    int n = 0;
    QString data;
    do{
        //data = DebugLog->readLine(10);
        data = inputStream.readLine();
        if(data.contains(sync)){
            dataCounter++;
            //qDebug() << "Data was find: " << dataCounter << data;
            Q_EMIT Interrupt_ReadPacket(data, dataCounter);                    //signal
        }
        n++;
    }while(!DebugLog->atEnd() || n <= 4);

}
int RADAR_AWR1843::sortData(QByteArray data,TLV_dat outData){
    int length = data.length();
    int n = 1;
    int pos = n +ofset;
    while(n<=data.length()){
    //FrameHeaderStructType     defaultPosition
        //
        //sync
        if(n<= 8){
            //outData.fHST->sync = {'x02', 'x01', 'x04', 'x03', 'x06', 'x05', 'x08', 'x07'};
            //outData.fHST.sync = {'\x02', '\x01', '\x04', '\x03', '\x06', '\x05', '\x08', '\x07'};
            //outData.fHST.sync = {0x02,0x01,0x04,0x03,0x06,0x05,0x08,0x07};
            //outData.fHST.sync = QByteArray::fromHex("0201040306050807");
            //outData.fHST.sync = QByteArrayLiteral("\x02\x01\x04");
            //outData.fHST.sync
            //QByteArray abc[5];
            //abc = QByteArrayLiteral("\x02\x01\x04");
        }
        //version
        else if(n <= 12){

        }
        //platform
        else if(n <= 16){}
        //timestamp
        else if(n <= 20){}
        //packetLength
        else if(n <= 24){}
        //frameNumber
        else if(n <= 28){}
        //subframeNumber
        else if(n <= 32){}
        //chirpMargin
        else if(n <= 36){}
        //frameMargin
        else if(n <= 40){}
        //uartSendTime
        else if(n <= 44){}
        //trackProcessTime
        else if(n <= 48){}
        // !!! //numTLVs
        else if(n <= 52){}
        //checksum
        else if(n <= 56){}
        //TLV_Header OR Point Cloud OR TargetObject dependent on type
        else if((n > 56)&&(n<=length)){
            //
        }
        else{
            break;
        }
        n++;
    }
}
int RADAR_AWR1843::readPackets(int msec){

}

