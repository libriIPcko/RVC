#include "canview.h"
#include "ui_canview.h"

CANview::CANview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CANview)
{
    ui->setupUi(this);
}

CANview::~CANview()
{
    delete ui;
}
