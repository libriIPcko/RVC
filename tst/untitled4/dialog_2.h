#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>

namespace Ui {
class Dialog_2;
}

class Dialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2(QWidget *parent = nullptr);
    ~Dialog_2();

private:
    Ui::Dialog_2 *ui;

public: signals:

public slots:

private slots:
    void on_pushButton_clicked();
};

#endif // DIALOG_2_H
