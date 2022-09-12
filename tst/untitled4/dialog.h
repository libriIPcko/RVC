#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "ui_dialog.h"
#include "mythread.h"
#include "QDebug"
#include "C:\Users\RPlsicik\Documents\GitHub\RVC\radar_awr1843.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    MyThread *mThread;
    RADAR_AWR1843 *rad;

private:
    Ui::Dialog *ui;
public slots:
    void onNumberChanged(int);
private slots:
    void on_pushButtons_Start_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOG_H
