#include "radar_awr1843.h"
#include "QCoreApplication"
#include "QFile"
#include "QTextStream"
#include <list>
#include <iostream>
#include <stdio.h>
#include <QDir>
#include <QTimer>

#include "tlv_dat.h"

RADAR_AWR1843::RADAR_AWR1843(QObject *parent) //: QThread(parent)
{
    port_AUXILIARY = new QSerialPort;
    port_COMM = new QSerialPort;
    //qDebug() << "RX_radar_data File status open: " << RX_radar_data->open(QIODevice::ReadWrite);
    RX_radar_data->open(QIODevice::ReadWrite);
    //qDebug() << "DebugLog File status open: " << DebugLog->open(QIODevice::ReadWrite);
    //DebugLog->open(QIODevice::ReadWrite);

    QObject::connect(port_COMM,SIGNAL(readyRead()),this,SLOT(port_COMM_receive()));
    QObject::connect(port_AUXILIARY,SIGNAL(readyRead()),this,SLOT(port_AUXILIARY_receive()));
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
        QObject::connect(port_COMM,SIGNAL(readyRead()),this,SLOT(port_COMM_receive()));
        QObject::connect(port_AUXILIARY,SIGNAL(readyRead()),this,SLOT(port_AUXILIARY_receive()));

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
    status = status + 2*PortConnect("COM15",port_AUXILIARY_baudRate,"AUX");
    //if status == 1 only connected COMM
    //if status == 2 only connected AUX
    //if status == 3 succesfull connection
    return status;
}
int RADAR_AWR1843::connect(QString COMM,QString AUX){
    //Default path
        //COM 3 - APP\User UART
        //COM 4 - AUxiliary Data Port
    int status = 0;
    status = PortConnect(COMM,port_COMM_baudRate,"COM");
    status = status + 2*PortConnect(AUX,port_AUXILIARY_baudRate,"AUX");
    //if status == 1 only connected COMM
    //if status == 2 only connected AUX
    //if status == 3 succesfull connection
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
    emit received_comm(RX);
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
    qDebug() << "tim: "  << timer_debug.nsecsElapsed();
    timer_debug.restart();
    //QFile RX_radar_data("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/RX_radar_data.txt");
    //RX_radar_data->open(QIODevice::ReadWrite | QFile::Append | QFile::Text);    
    QTextStream DebugLogStream(DebugLog);
    QByteArray RX_byte_array = port_AUXILIARY->readAll();
    DebugLogStream << RX_byte_array.length();
    QString RX = RX_byte_array.toHex();

    QString sync = "0201040306050807";
    if(RX.contains("0201040306050807")){
        int pos = RX.indexOf(sync);
        int pos_next = RX.indexOf(sync,pos+1);

        if(packet_ongoing_fullfilement == true){
            for(int n = 0;n<=RX.length() && n <= pos_next;n++){
                //datForProcess.push_back(RX.at(n));
                if(n == RX.length()){
                    //The end of packet does not reached.
                    //The code in the next receive interrupt will continuous in the
                    //filling packet from iteration, which was before actual

                    //will continue variable
                    packet_ongoing_fullfilement = true;
                }
                else if(n==pos_next){
                    datForProcess.push_back(packet);
                    emit received_aux(packet);
                    packet.clear();
                    packet.append(RX.at(n));
                    //will continue
                }
                else{
                    packet.append(RX.at(n));
                }
            }
        }
        else{   //new set
            for(int n = pos;n<=RX.length() && n <= pos_next;n++){
                //datForProcess.push_back(RX.at(n));
                if(n == RX.length()){
                    //The end of packet does not reached.
                    //The code in the next receive interrupt will continuous in the
                    //filling packet from iteration, which was before actual

                    //will continue variable
                    packet_ongoing_fullfilement = true;
                }
                else if(n==pos_next){
                    datForProcess.push_back(packet);
                    emit received_aux(packet);
                  //There will be train the operation with vector...
                    //emit received_aux(datForProcess.);
                    //datForProcess.at(datForProcess.end())
                    packet.clear();
                    packet.append(RX.at(n));
                    //will continue
                }
                else{
                    packet.append(RX.at(n));
                }
            }
        }


    }
    //the data do not contain of synch an intermediate step
    else{
        for(int n=0;n<RX.length();n++){
            packet.append(RX.at(n));
        }
    }
    /*
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
    */
    //0201040306050807 - sync


    timer_debug.start();
}

//int RADAR_AWR1843::openFile(QString DataPath){
int RADAR_AWR1843::openFile(){
    //DebugLog->setFileName(DataPath);
    qDebug() << DebugLog->open(QIODevice::ReadOnly);
    return 0;
}
int RADAR_AWR1843::openFile(QString DataPath){
    DebugLog->setFileName(DataPath);
    qDebug() << DebugLog->open(QIODevice::ReadOnly);
    return 0;
}

int RADAR_AWR1843::closeFile(){
    DebugLog->close();
    return 0;
}

int RADAR_AWR1843::syncDetect(){
    QTextStream inputStream(DebugLog);
    QByteArray sync = "0201040306050807";
    //TLV_dat tlvData;
        data.clear();
        qDebug() << DebugLog->isOpen();
        data = DebugLog->readAll();
        //data_1 = DebugLog->readAll();
        pos.push_back(data.indexOf(sync));
        while(pos.at(pos.size()-1) <= data.length()){
            pos.push_back(data.indexOf(sync,1+pos.at(pos.size()-1)));
            qDebug() << pos.at((pos.size()-1)) << pos.size();
            if((pos.at(pos.size()-1)== -1)||(pos.at(pos.size()-2)==pos.at(pos.size()-1))){
                pos.pop_back();
                break;
                return 0;
            }
        }

}
int RADAR_AWR1843::loadPackets(){
    //Read all packets
    qsizetype j = 0;
    int i = 0;
    QString temp;
    temp.clear();
    TLV_RAW_packets.clear();
    do{
        temp.append(data.at(i));
        // add if for breakpoint 1390 = j
        if(i==pos.at(pos.size()-1)||i==pos.at(j+1)){
            TLV_RAW_packets.push_back(temp);
            temp.clear();
            if(i == pos.at(pos.size()-1)){
                break;
            }
            else{
                j++;
            }
        }
        i++;
    }while(i<=pos.at(j+1));
}

int RADAR_AWR1843::algorithm_ReadFromFile(){
    openFile();
    syncDetect();
    loadPackets();
    for(uint16_t i=0;i <= TLV_RAW_packets.size()-1;i++){
        sortData(TLV_RAW_packets.at(i),i);
    }
    closeFile();
}

// - Start here, the outData are filled but not store in the TLV_packets
//
//int RADAR_AWR1843::sortData(QString data,TLV_dat outData){
int RADAR_AWR1843::sortData(QString data,int num){
    QFile outFile("C:/Users/RPlsicik/Documents/GitHub/RVC/tst/untitled4/outFile_sortedData.txt");

    int length = data.length();
    int n = 0;
    int offset = 0;
    int bO = 2;
    int vect_iterator = 0;
    QByteArray temp;
    QTextStream out(&outFile);
    out << "\n----" << num << "----\n";
    if(num == 0){
        qDebug() << "Open output file: "<<outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    }
    else{
        qDebug() << "Open output file: "<<outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    }
    //int pos = 0;
    while(n<data.length()){
    //FrameHeaderStructType     defaultPosition
        //sync
        if(n < 8*bO){
            //pos = n;
            if(n==0){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " "<< "sync: \t\t\t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.sync.append(data.toUtf8().at(n));
        }
        //version
        else if(n < (12*bO)){
            //if(n==9){ofset=9;pos=n-ofset;}
            //QTextStream out(&outFile);
            if(n==8*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " "<< "version: \t\t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.version.append(data.toUtf8().at(n));
        }
        //platform
        else if(n < (16*bO)){
            //QTextStream out(&outFile);
            if(n==12*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " "<< "platform: \t\t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.platform.append(data.toUtf8().at(n));
        }
        //timestamp
        else if(n < 20*bO){
            //QTextStream out(&outFile);
            if(n==16*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " "<< "timestamp: \t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.timestamp.append(data.toUtf8().at(n));
        }
        //packetLength
        else if(n < 24*bO){
            //QTextStream out(&outFile);
            if(n==20*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " "<< "packetLength: \t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.packetLength.append(data.toUtf8().at(n));
        }
        //frameNumber
        else if(n < 28*bO){
            //QTextStream out(&outFile);
            if(n==24*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " "<< "frameNumber: \t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.frameNumber.append(data.toUtf8().at(n));
        }
        //subframeNumber
        else if(n < 32*bO){
            //QTextStream out(&outFile);
            if(n==28*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " "<< "subframeNumber: \t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.subframeNumber.append(data.toUtf8().at(n));
        }
        //chirpMargin
        else if(n < 36*bO){
            //QTextStream out(&outFile);
            if(n==32*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " "<< "chirpMargin: \t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.chirpMargin.append(data.toUtf8().at(n));
        }
        //frameMargin
        else if(n < 40*bO){
            //QTextStream out(&outFile);
            if(n==36*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" <<  QString::number(n) << " " << "frameMargin: \t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.frameMargin.append(data.toUtf8().at(n));
        }
        //uartSendTime
        else if(n < 44*bO){
            //QTextStream out(&outFile);
            if(n==40*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " " << "uartSendTime: \t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.uartSendTime.append(data.toUtf8().at(n));
        }
        //trackProcessTime
        else if(n < 48*bO){
            //QTextStream out(&outFile);
            if(n==44*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " " << "trackProcessTime: \t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.trackProcessTime.append(data.toUtf8().at(n));
        }

        // !!! //numTLVs

        else if(n < 52*bO){           
            //QTextStream out(&outFile);
            if(n==48*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " " << "numTLVs: \t\t\t";
            }
            out << data.toUtf8().at(n);
            //qDebug() << data.toUtf8().at(n);
            outData.fHST.numTLVs.append(data.toUtf8().at(n));
        }


        /*
        //checksum
        else if((n < 52*bO) && (n < 56*bO)){
            //QTextStream out(&outFile);
            if(n==52*bO){
                out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " " << "checksum: \t\t";
            }
            out << data.toUtf8().at(n);
            qDebug() << data.toUtf8().at(n);
            outData.fHST.checksum.append(data.toUtf8().at(n));
        }
        */
        //TLV_Header OR Point Cloud OR TargetObject dependent on type
        //else if((n > 56*bO)&&(n<=length)){
        else if((n<=length)){
            //if(n==52*bO){
            if(n<=length-25){
                //out << "\n"<< QString::number(TLV_packets.size()) << "/" << QString::number(n)  << " " << "Other: \t\t\n";
                //TLV Header 4+4 = 8
                    int i = 0;
                    outData.tlvHeader_vect.resize(vect_iterator+1);
                    outData.pointCloud_vect.resize(vect_iterator+1);
                    while(i<4){
                        outData.tlvHeader_vect[vect_iterator].type.append(data.toUtf8().at(n));
                        i++;
                        n++;
                    }
                        out << "\n type:" << outData.tlvHeader_vect[vect_iterator].type;
                    while(i>=4 && i<8){
                        outData.tlvHeader_vect[vect_iterator].length.append(data.toUtf8().at(n));
                        i++;
                        n++;
                    }
                        out << "\n length:" << outData.tlvHeader_vect[vect_iterator].length;
                    //PointCloud
                    if(outData.tlvHeader_vect[vect_iterator].type.compare("0600") == 0){
                        //Point Cloud 4+4+4+4 = 16
                            while(i>=8 && i<24){
                                if(i>=8 && i<12){    //range, in m
                                    outData.point_cloud.range.append(data.toUtf8().at(n));
                                }
                                else if(i>=12 && i<16){    //azimuth, in rad
                                    outData.point_cloud.azimuth.append(data.toUtf8().at(n));
                                }
                                else if(i>=16 && i<20){    //Doppler, in m/s
                                    outData.point_cloud.doppler.append(data.toUtf8().at(n));
                                }
                                else if(i>=20 && i<24){    //SNR, ratio
                                    outData.point_cloud.snr.append(data.toUtf8().at(n));
                                }
                                i++;
                                n++;
                            }
                            //outData.pointCloud_vect.insert(outData.point_cloud.range)->range;
                            outData.pointCloud_vect.resize(vect_iterator+1);

                            outData.pointCloud_vect[vect_iterator].range = outData.point_cloud.range;
                            outData.pointCloud_vect[vect_iterator].azimuth = outData.point_cloud.azimuth;
                            outData.pointCloud_vect[vect_iterator].doppler = outData.point_cloud.doppler;
                            outData.pointCloud_vect[vect_iterator].snr = outData.point_cloud.snr;

                            out << "\n range: " << outData.pointCloud_vect[vect_iterator].range;
                            out << "\n azimuth: " << outData.pointCloud_vect[vect_iterator].azimuth;
                            out << "\n doppler: " << outData.pointCloud_vect[vect_iterator].doppler;
                            out << "\n snr: " << outData.pointCloud_vect[vect_iterator].snr;
                    }

                    //Target Object List
                    else if(outData.tlvHeader_vect[vect_iterator].type.compare("0700") == 0){
                        //Target Object 4+4+4+4+4+4+4+9*4+4 = 36
                            while(i > 16  && i<=36){
                                out << " \nTargetObjectList: \t" << data.toUtf8().at(n);
                                i++;
                                n++;
                            }
                    }
                    //Target index
                    else if(outData.tlvHeader_vect[vect_iterator].type.compare("0800") == 0){
                        //Target Object list 1 byte
                            while(i > 36){
                                out << " \nTargetObjectList: \t" << data.toUtf8().at(n);
                                i++;
                                n++;
                            }
                    }
                    vect_iterator++;


                    //The TLV data
                    /*
                    else{

                    }
                    */
                //out << "\n"<< "Other: \t\t\n";
            }
            out <<"\n other:" <<  data.toUtf8().at(n);
            //qDebug() << n <<"/"<<length << ":" << data.toUtf8().at(n);
        }

        else{
            break;
        }
        n++;

    }
}
int RADAR_AWR1843::readPackets(int msec){

}

