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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QWidget *tab_2;
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
        pushButton_showDev->setGeometry(QRect(488, 18, 75, 20));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(380, 20, 101, 16));
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
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
        lineEdit->setText(QCoreApplication::translate("MainWindow", "COM12", nullptr));
        pushButton_SendBtn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_ListSendBtn->setText(QCoreApplication::translate("MainWindow", "ListSend", nullptr));
        pushButton_RX_clean->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_TX_clean->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        lineEdit_lineEdit_timdelaylist->setText(QCoreApplication::translate("MainWindow", "800", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TX list delay:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "[ms]", nullptr));
        pushButton_showDev->setText(QCoreApplication::translate("MainWindow", "ShowDev", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "USB2CAN works...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Connect", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "MotorControl", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
