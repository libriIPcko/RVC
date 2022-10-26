#include "usb2can_driver.h"
#include "USB2CAN_define.h"
#include "QSerialPort"

#include "QSerialPort"
#include "QObject"
#include "QDebug"

//#include <QSignalSpy>



USB2CAN_driver::USB2CAN_driver()
{
    port_USB2CAN = new QSerialPort();
    ListTimer = new QTimer();
    initListTimer = new QTimer();

    qDebug() << "Connection of readyRead to sw interrupt:" <<connect(port_USB2CAN,SIGNAL(readyRead()),this,SLOT(read_USB2CAN()));

}

/*
USB2CAN_driver::~USB2CAN_driver(){
    QObject::disconnect(USB2CAN_driver::,SIGNAL(readyRead()),USB2CAN_driver::,SLOT(QByteArray read_USB2CAN()));
}
*/

int USB2CAN_driver::connectToPort(QString portName){
    port_USB2CAN->setPortName(portName);
    port_USB2CAN->setBaudRate(Baud9600,AllDirections);
    tim = new QTimer;
    return port_USB2CAN->open(QIODevice::ReadWrite);
}
int USB2CAN_driver::connectToPort(QString portName,int BaudRate){
    port_USB2CAN->setPortName(portName);
    port_USB2CAN->setBaudRate(BaudRate,AllDirections);
    tim = new QTimer;
    return port_USB2CAN->open(QIODevice::ReadWrite);
}

/*
void USB2CAN_driver::timEvent(){
    qDebug() << "Tim" << tim_counter++;
    if(tim_counter >= 5){
        tim_counter = 0;
        tim->stop();
    }
}
*/

int USB2CAN_driver::disconnectedFromPort(){
    port_USB2CAN->close();
    if(port_USB2CAN->isOpen()){
        return 1;
    }
    else{
        qDebug() << "------------------Port is diconected-----------------";
        return 0;
    }
}


void USB2CAN_driver::USB_LoopBack(){

}
void USB2CAN_driver::Boot_Mode(){

}
void USB2CAN_driver::Config_Mode(){

}
void USB2CAN_driver::Normal_Mode(){

}
void USB2CAN_driver::LoopBack_Mode(){

}
QByteArray USB2CAN_driver::Get_Mode(){
    while(!port_USB2CAN->waitForBytesWritten(300)){
        port_USB2CAN->write(getMode);

    }
    return USB2CAN_driver::readAll();
}

void USB2CAN_driver::WriteReg(QByteArray regAdress, QByteArray value){
    QByteArray sync = "0f";
    QByteArray out = {QByteArray::fromHex(sync) +QByteArray::fromHex("12") + regAdress + QByteArray::fromHex(QByteArray::number(value.size())) + value};
    SendHex(out);
    /*
    while(!port_USB2CAN->waitForBytesWritten(300)){
        port_USB2CAN->write(out);

    }
    */
    /*
    int length = regAdress.length() + value->length();
    QByteArray len;
    len.setNum(length);
    QByteArray sendVal[] = { writeReg, len, regAdress, *value };
    QByteArray sendData;
    sendData.fromRawData(*sendVal,sizeof (sendVal));
    while(!port_USB2CAN->waitForBytesWritten(300)){
        port_USB2CAN->write(sendData);

    }
    */
}

int USB2CAN_driver::SendString(QString data){
    //sendData.fromRawData(*sendVal,sizeof (sendVal));
    long length;
    while(!port_USB2CAN->waitForBytesWritten(300)){
        length = port_USB2CAN->write(data.toUtf8(),data.size());
    }
    return length;
}
int USB2CAN_driver::SendHex(QByteArray data){
    long length;
    while(!port_USB2CAN->waitForBytesWritten(300)){
        length = port_USB2CAN->write(data);
    }
    return length;
}
QByteArray USB2CAN_driver::WriteCMD(QByteArray CMD_name, QByteArray value){

}
QByteArray USB2CAN_driver::ReadReg(QByteArray regAdress){

}

int USB2CAN_driver::init(){
    //Init CMD by timer period
        activeInit = true;
        temporary_init_Counter = 0;
        connect(initListTimer,SIGNAL(timeout()),this,SLOT(initSend()));
        initSend();
        initListTimer->setTimerType(Qt::PreciseTimer);
        initListTimer->start(initTimerDelay);
    //BadCode
        //initSend_1();
}

QByteArray USB2CAN_driver::read_USB2CAN(){
    //qDebug() <<"From driver RX" << USB2CAN_driver::readAll();
    QByteArray temporary = port_USB2CAN->readAll();
    if(activeInit == true){
        initListTimer->stop();
        emit dataReceived(temporary);
        initSend();
        if(activeInit == true){
            initListTimer->setTimerType(Qt::PreciseTimer);
            initListTimer->start(initTimerDelay);
        }
    }
    else{
        emit dataReceived(temporary);
    }
    return 0;
}

void USB2CAN_driver::writeCANmsg(QString msg){
    //WRITE_MESSAGE 65 N,L Odoslanie CAN spravy
    /*
                    Tato zpráva nese požadavek na odeslání zprávy na CAN. Struktura datové ásti
                    zprávy odpovídá struktue transmit bufferu obvodu SJA 1000. Tzn. nejprve hodnota
                    registru, TX frame Information, dále pak 2 (standardní 11 bitový identifikátor) nebo 4
                    (rozšíený 29 bitový identifikátor) bajty registr TX identifier a následn 0 až 8
                    datových bajt CAN zprávy. Délka USB zprávy je tedy závislá na délce CAN zprávy.
    */
    //0F +  CMD + Length(0x00-0x10) + Data bytes {RegName + TX frame information + 11bit ID + CAN data}
                                            //Datahseet SJA1000 -   39page
    //Tato zpráva nese požadavek na odeslání zprávy na CAN. Struktura datové ásti zprávy odpovídá struktue transmit bufferu obvodu SJA 1000. Tzn. nejprve hodnota
    //registru, TX frame Information, dále pak
    //x0F 40 xyxy  d10 00 d11 ff d12 01 d13 02 d14 03
    //0F 40 xyxy TX_frame TX_ID1 TX_ID2 TX_DatB-1-8
    //TX Frame information SFF
                //B7   B6 B5  B4  B3       B2       B1      B0
                //FF  RTR X   X   DLC.3   DLC.2   DLC.1   DLC.0
            //FF - 0 Standard Frame Format
            //RTR   1 - remote frame    0 - data frame
            //B7   B6 B5  B4       B3             B2       B1        B0
            //0     0 0   0     DataLength DataLength DataLength DataLength
    //TX Identifier 1-2 16b CAN_ID
    //CAN Data


}

void USB2CAN_driver::writeCANmsg(QByteArray msg){
}

bool USB2CAN_driver::initSend(){
     bool stop = false;
    qDebug() << "case" << temporary_init_Counter << "time: " << initListTimer->remainingTime();
    initListTimer->stop();
    int waitForBytesWritten = 200;
    int status;
    switch (temporary_init_Counter) {
        case 0:                     //1-Set to Config Mode [0x02]
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                status = port_USB2CAN->write(Config,3);
                qDebug() << "TX:" << QString::fromLocal8Bit(Config) << "Status" << status << "Config" << temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
                /*
                //USB2CAN_driver::write(Config,qstrlen(Config));

                bool ok = false;
                int cycle = 0;
                while(ok == true){
                    status = port_USB2CAN->write(Config,3);
                    while(!port_USB2CAN->waitForReadyRead(5)){
                        if((strcmp(port_USB2CAN->readAll(),"FF"))==1){
                                ok = true;
                        }
                        if(cycle >= 4){
                            ok = true;
                        }
                        qDebug() << cycle++;
                    }
                }

            }
            */
        break;
        case 1:                    //2-Set Reset Mode [0x00]on value 0x01   (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ResetMod);
                //USB2CAN_driver::write(ResetMod,qstrlen(ResetMod));
                status = port_USB2CAN->write(ResetMod,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(ResetMod) << "Status" << status << "ResetMod"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 2:                    //3-Set Clock divider [0x1F] on value 0xC0 (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ClockDivData);
                //USB2CAN_driver::write(ClockDivData,qstrlen(ClockDivData));
                status = port_USB2CAN->write(ClockDivData,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(ClockDivData) << "Status" << status << "ClockDivData"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 3:                    //4.1-Set message filter; without filtration: (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(AccCode);
                //USB2CAN_driver::write(AccCode,qstrlen(AccCode));
                status = port_USB2CAN->write(AccCode,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(AccCode) << "Status" << status << "AccCode"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 4:                    //4.2 set-> Acceptance Mask [0x05] on 0xff
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(AccMask);
                //USB2CAN_driver::write(AccMask,qstrlen(AccMask));
                status = port_USB2CAN->write(AccMask,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(AccMask) << "Status" << status << "AccMask"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 5:                   //5-Set OutputControl[0x08] on 0xDA (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(OutCtrl);
                //USB2CAN_driver::write(OutCtrl),qstrlen(OutCtrl);
                status = port_USB2CAN->write(OutCtrl,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(OutCtrl) << "Status" << status << "OutCtrl"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 6:                  //7. -Set Interrupt enable[]  on 0x03  (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(IE);
                //USB2CAN_driver::write(IE,qstrlen(IE));
                status = port_USB2CAN->write(IE,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(IE) << "Status" << status << "IE"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 7:                 //6.1 - Bus Timing 0
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(BT0);
                //USB2CAN_driver::write(BT0,qstrlen(BT0));
                status = port_USB2CAN->write(BT0,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(BT0) << "Status" << status << "BT0"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 8:                 //6.2 - Bus Timing 1
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(BT1);
                //USB2CAN_driver::write(BT1,qstrlen(BT1));
                status = port_USB2CAN->write(BT1,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(BT1) << "Status" << status << "BT1"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 9:                 //8.1 -Set Transmit Critical Limit and Transmit Ready limit by cmd COMMAND TCL
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(CTL_Code);
                //USB2CAN_driver::write(CTL_Code,qstrlen(CTL_Code));
                status = port_USB2CAN->write(CTL_Code,4);
                qDebug() << "TX:" << QString::fromLocal8Bit(CTL_Code) << "Status" << status << "CTL_Code"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 10:               //8.2 Set-> TRL
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(TRL_Code);
                //USB2CAN_driver::write(TRL_Code,qstrlen(TRL_Code));
                status = port_USB2CAN->write(TRL_Code,4);
                qDebug() << "TX:" << QString::fromLocal8Bit(TRL_Code) << "Status" << status << "TRL_Code"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 11:              //9-Set Normal Mode
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(NormalMode);
                //USB2CAN_driver::write(NormalMode,qstrlen(NormalMode));
                status = port_USB2CAN->write(NormalMode,3);
                qDebug() << "TX:" << QString::fromLocal8Bit(NormalMode) << "Status" << status << "NormalMode"<< temporary_init_Counter;
            }
            initListTimer->start(initTimerDelay);
        break;
        case 12:              //10-Set Mode register [0x00], the value depends on Message Filter   (by WriteReg[x12])
            while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten)){
                //USB2CAN_driver::write(ModRegDat);
                //USB2CAN_driver::write(ModRegDat,qstrlen(ModRegDat));
                status = port_USB2CAN->write(ModRegDat,5);
                qDebug() << "TX:" << QString::fromLocal8Bit(ModRegDat) << "Status" << status << "ModRegDat - final"<< temporary_init_Counter;

            }
            initListTimer->start(initTimerDelay);
        break;
        case 13:              //End of Initialize sub-routine
            stop = true;
            temporary_init_Counter = 0;
            activeInit = false;
            initListTimer->stop();
            qDebug() << QObject::disconnect(initListTimer);
            qDebug() << "initTimer is active? " << initListTimer->isActive();
            //return true;
        break;
        default:
            qDebug() << "ERROR init !! case" << temporary_init_Counter;
            return false;
        break;
    }

    if(stop == true){        
        initListTimer->stop();        
        QObject::disconnect(initListTimer);
        //temporary_init_Counter = 0;
        return true;
    }
    else{
        temporary_init_Counter++;
        return false;
    }



}

void USB2CAN_driver::initSend_1(){
    QByteArray initSeq[] = {Config, ResetMod, ClockDivData, AccCode, AccMask, OutCtrl, IE, BT0, BT1, CTL_Code, TRL_Code, NormalMode, ModRegDat};
    int step = 0;
    int step_fb = 0;
    while(step <= sizeof (initSeq)){
        while(!port_USB2CAN->waitForBytesWritten(waitForBytesWritten())){
            port_USB2CAN->write(initSeq[step]);
        }
        step++;
        qDebug() << step_fb++ << "/" << sizeof (initSeq);
        /*
        if(step_fb>=50){
            break;
        }
        */
    }
}
