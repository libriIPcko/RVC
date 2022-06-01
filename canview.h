#ifndef CANVIEW_H
#define CANVIEW_H

#include <QDialog>

namespace Ui {
class CANview;
}

class CANview : public QDialog
{
    Q_OBJECT

public:
    explicit CANview(QWidget *parent = nullptr);
    ~CANview();

private:
    Ui::CANview *ui;
};

#endif // CANVIEW_H
