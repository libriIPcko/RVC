#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include "C:\\Users\RPlsicik\Documents\GitHub\RVC\usb2can_driver.h"
#include "QByteArray"

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
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool event(QEvent *event);
public: signals:
private slots:
    void on_dataReceived(QByteArray);

    void on_pushButton_clicked(bool checked);
    void on_pushButton_released();
    void on_pushButton_2_released();
    void on_pushButton_Send_released();
    void on_pushButton_SendBtn_clicked();
};
#endif // MAINWINDOW_H
