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
    QTimer *time;


private: signals:
    friend void USB2CAN_driver::readyRead();
private slots:
    void on_connectPort_released();

    void on_pushButton_released();

    QByteArray read_u2c();

    void timerSubrutine();

private:
    Ui::CANview *ui;
};

#endif // CANVIEW_H
