#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include "C:\\Users\RPlsicik\Documents\GitHub\RVC\usb2can_driver.h"
#include "QByteArray"
#include "deque"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    USB2CAN_driver *u2c;
    bool connectStatus = false;
    bool connectButton = false;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool event(QEvent *event);
    std::deque<QString> outputTxt;
    //std::vector<QString> outputTxt;
    QTimer *listSendTimer;

    void menu_sendCommands(QString cmd);

public: signals:
    void timeout();
    void readyRead();
private slots:
    void on_dataReceived(QByteArray);
    void on_timeout_listSendTimer();


    void on_pushButton_released();
    void on_pushButton_SendBtn_clicked();
    void on_pushButton_ListSendBtn_released();
    void on_pushButton_3_released();
    void on_pushButton_RX_clean_released();
};
#endif // MAINWINDOW_H
