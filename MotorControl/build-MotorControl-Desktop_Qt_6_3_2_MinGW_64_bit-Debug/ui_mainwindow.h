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
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 75, 24));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 10, 113, 22));
        TX_textEdit = new QTextEdit(tab);
        TX_textEdit->setObjectName(QString::fromUtf8("TX_textEdit"));
        TX_textEdit->setGeometry(QRect(20, 50, 311, 221));
        TX_textEdit->setStyleSheet(QString::fromUtf8("gridline-color: rgb(0, 0, 0);"));
        RX_textEdit = new QTextEdit(tab);
        RX_textEdit->setObjectName(QString::fromUtf8("RX_textEdit"));
        RX_textEdit->setGeometry(QRect(360, 50, 311, 221));
        pushButton_SendBtn = new QPushButton(tab);
        pushButton_SendBtn->setObjectName(QString::fromUtf8("pushButton_SendBtn"));
        pushButton_SendBtn->setGeometry(QRect(250, 240, 75, 24));
        pushButton_ListSendBtn = new QPushButton(tab);
        pushButton_ListSendBtn->setObjectName(QString::fromUtf8("pushButton_ListSendBtn"));
        pushButton_ListSendBtn->setGeometry(QRect(170, 240, 75, 24));
        pushButton_RX_clean = new QPushButton(tab);
        pushButton_RX_clean->setObjectName(QString::fromUtf8("pushButton_RX_clean"));
        pushButton_RX_clean->setGeometry(QRect(650, 50, 21, 24));
        pushButton_TX_clean = new QPushButton(tab);
        pushButton_TX_clean->setObjectName(QString::fromUtf8("pushButton_TX_clean"));
        pushButton_TX_clean->setGeometry(QRect(310, 50, 21, 24));
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

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "COM66", nullptr));
        pushButton_SendBtn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_ListSendBtn->setText(QCoreApplication::translate("MainWindow", "ListSend", nullptr));
        pushButton_RX_clean->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_TX_clean->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
