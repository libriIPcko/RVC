#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QSerialPort>
#include "usb2can_driver.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTimer *Timer_sendLine;

    QString txtLineByLine[300];
    int countLine = 0;
    int incLine = 1;

    QSerialPort *port1;
    QSerialPort *port2;
    USB2CAN_driver *u2c;
    //QSerialPort port2;
    //QSerialPort port1;


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private: signals:
    void timeout();
    void readyRead();


private slots:

    void SendNextRow();

    void SendNextRow_InitUSB2CAN();

    void readSerial_2();

    void readSerial_1();

    void on_pushButton_clicked();

    void on_pushButton_connect2_clicked();

    void on_pushButton_connect1_toggled(bool checked);

    void on_pushButton_connect2_toggled(bool checked);

    void on_pushButton_port1_clear_clicked();

    void on_pushButton_port2_clear_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_released();

    void on_pushButton_port1_RX_clear_clicked(bool checked);

    void on_pushButton_port2_RX_clear_clicked(bool checked);

    void on_checkBox_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
