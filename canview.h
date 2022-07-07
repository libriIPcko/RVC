#ifndef CANVIEW_H
#define CANVIEW_H

#include <QDialog>
#include <usb2can_driver.h>

namespace Ui {
class CANview;
}

class CANview : public QDialog
{
    Q_OBJECT

public:
    explicit CANview(QWidget *parent = nullptr);
    ~CANview();

    USB2CAN_driver *u2c;
    QTimer *timer;
    QTimer *timer_listSend;

    //Important for list send
    QString txtLineByLine[300];
    int countLine = 0;
    int incLine = 0;

private: signals:
    void timeout();

private slots:
    void on_connectPort_released();

    void on_pushButton_released();

    QByteArray read_u2c();

    void timerSubrutine();

    void timer_listSend_event();

    void on_ListSend_released();

private:
    Ui::CANview *ui;
};

#endif // CANVIEW_H
