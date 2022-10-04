#include "mainwindow.h"

#include <QApplication>
#include "C:\Users\RPlsicik\Documents\GitHub\RVC\usb2can_driver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
