/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *TX_textEdit;
    QTextEdit *RX_textEdit;
    QPushButton *pushButton_SendBtn;
    QPushButton *pushButton_ListSendBtn;
    QPushButton *pushButton_RX_clean;
    QPushButton *pushButton_TX_clean;
    QLineEdit *lineEdit_lineEdit_timdelaylist;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_showDev;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_baudrate;
    QLineEdit *lineEdit_baudrate;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QDial *dial_position;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_speed;
    QRadioButton *radioButton;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 801, 551));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 20, 75, 20));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 20, 113, 22));
        TX_textEdit = new QTextEdit(tab);
        TX_textEdit->setObjectName(QString::fromUtf8("TX_textEdit"));
        TX_textEdit->setGeometry(QRect(40, 50, 311, 221));
        TX_textEdit->setStyleSheet(QString::fromUtf8("gridline-color: rgb(0, 0, 0);"));
        RX_textEdit = new QTextEdit(tab);
        RX_textEdit->setObjectName(QString::fromUtf8("RX_textEdit"));
        RX_textEdit->setGeometry(QRect(40, 300, 311, 221));
        pushButton_SendBtn = new QPushButton(tab);
        pushButton_SendBtn->setObjectName(QString::fromUtf8("pushButton_SendBtn"));
        pushButton_SendBtn->setGeometry(QRect(270, 240, 75, 24));
        pushButton_ListSendBtn = new QPushButton(tab);
        pushButton_ListSendBtn->setObjectName(QString::fromUtf8("pushButton_ListSendBtn"));
        pushButton_ListSendBtn->setGeometry(QRect(190, 240, 75, 24));
        pushButton_RX_clean = new QPushButton(tab);
        pushButton_RX_clean->setObjectName(QString::fromUtf8("pushButton_RX_clean"));
        pushButton_RX_clean->setGeometry(QRect(330, 300, 21, 24));
        pushButton_TX_clean = new QPushButton(tab);
        pushButton_TX_clean->setObjectName(QString::fromUtf8("pushButton_TX_clean"));
        pushButton_TX_clean->setGeometry(QRect(330, 50, 21, 24));
        lineEdit_lineEdit_timdelaylist = new QLineEdit(tab);
        lineEdit_lineEdit_timdelaylist->setObjectName(QString::fromUtf8("lineEdit_lineEdit_timdelaylist"));
        lineEdit_lineEdit_timdelaylist->setGeometry(QRect(260, 20, 51, 22));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 0, 71, 21));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 20, 31, 21));
        pushButton_showDev = new QPushButton(tab);
        pushButton_showDev->setObjectName(QString::fromUtf8("pushButton_showDev"));
        pushButton_showDev->setGeometry(QRect(40, 277, 75, 20));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(690, 0, 101, 16));
        QFont font;
        font.setStrikeOut(false);
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setFrameShadow(QFrame::Plain);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 400, 31, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setKerning(true);
        label_4->setFont(font1);
        label_4->setLineWidth(1);
        label_4->setText(QString::fromUtf8("RX:"));
        label_4->setTextFormat(Qt::PlainText);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 140, 31, 31));
        label_5->setFont(font1);
        label_5->setLineWidth(1);
        label_5->setText(QString::fromUtf8("TX:"));
        label_5->setTextFormat(Qt::PlainText);
        label_baudrate = new QLabel(tab);
        label_baudrate->setObjectName(QString::fromUtf8("label_baudrate"));
        label_baudrate->setGeometry(QRect(370, 0, 81, 16));
        lineEdit_baudrate = new QLineEdit(tab);
        lineEdit_baudrate->setObjectName(QString::fromUtf8("lineEdit_baudrate"));
        lineEdit_baudrate->setGeometry(QRect(370, 20, 113, 22));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 278, 75, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        dial_position = new QDial(tab_2);
        dial_position->setObjectName(QString::fromUtf8("dial_position"));
        dial_position->setGeometry(QRect(280, 10, 181, 141));
        lcdNumber = new QLCDNumber(tab_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(630, 20, 64, 23));
        lcdNumber_speed = new QLCDNumber(tab_2);
        lcdNumber_speed->setObjectName(QString::fromUtf8("lcdNumber_speed"));
        lcdNumber_speed->setGeometry(QRect(630, 50, 64, 23));
        radioButton = new QRadioButton(tab_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 10, 121, 31));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(710, 20, 49, 16));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(710, 50, 49, 16));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(tabWidget, pushButton);
        QWidget::setTabOrder(pushButton, lineEdit);
        QWidget::setTabOrder(lineEdit, TX_textEdit);
        QWidget::setTabOrder(TX_textEdit, RX_textEdit);
        QWidget::setTabOrder(RX_textEdit, pushButton_SendBtn);
        QWidget::setTabOrder(pushButton_SendBtn, pushButton_ListSendBtn);
        QWidget::setTabOrder(pushButton_ListSendBtn, pushButton_RX_clean);
        QWidget::setTabOrder(pushButton_RX_clean, pushButton_TX_clean);
        QWidget::setTabOrder(pushButton_TX_clean, lineEdit_lineEdit_timdelaylist);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "COM6", nullptr));
        TX_textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">#msg701/ffaa01</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">#msg601/ffaabb01</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">#msg101/0001</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">#msg201/0002</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0"
                        "px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_SendBtn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_ListSendBtn->setText(QCoreApplication::translate("MainWindow", "ListSend", nullptr));
        pushButton_RX_clean->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_TX_clean->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        lineEdit_lineEdit_timdelaylist->setText(QCoreApplication::translate("MainWindow", "800", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TX list delay:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "[ms]", nullptr));
        pushButton_showDev->setText(QCoreApplication::translate("MainWindow", "ShowDev", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "USB2CAN works...", nullptr));
        label_baudrate->setText(QCoreApplication::translate("MainWindow", "BaudRate", nullptr));
        lineEdit_baudrate->setText(QCoreApplication::translate("MainWindow", "9600", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Get Mode", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Connect", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Motor Activation", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "angle", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "speed", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "MotorControl", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
