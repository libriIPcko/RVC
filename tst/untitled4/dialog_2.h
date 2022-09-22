#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>
#include <mythread.h>
#include <QObject>
#include <thread>

namespace Ui {
class Dialog_2;
}

class Dialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2(QWidget *parent = nullptr);
    ~Dialog_2();

    MyThread *mThread1;
    MyThread *mThread2;
    MyThread *mThread3;

    void ThrFunction_1();
    void ThrFunction_2();

private:
    Ui::Dialog_2 *ui;

public: signals:

public slots:
    void on_NumberChanged(int,QString);
    void on_NumberChanged(int);
    void on_randomizer_out(int, QString);


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOG_2_H
