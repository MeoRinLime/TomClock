/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *functionList;
    QPushButton *historyRecord;
    QPushButton *achievement;
    QPushButton *start;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../resourse/images/Icons/MainIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("../resourse/images/Icons/MainIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        functionList = new QWidget(centralwidget);
        functionList->setObjectName("functionList");
        functionList->setGeometry(QRect(10, 0, 491, 151));
        functionList->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(225, 225, 225);\n"
"border:2px groove gray;\n"
"border-radius:10px;\n"
"padding:2px 4px;\n"
"border-style: outset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(229, 241, 251); \n"
"color: black;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:rgb(204, 228, 247);\n"
"border-style: inset;\n"
"}\n"
""));
        historyRecord = new QPushButton(functionList);
        historyRecord->setObjectName("historyRecord");
        historyRecord->setGeometry(QRect(10, 20, 211, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\351\223\255\347\237\263\344\275\223 \347\256\200")});
        font.setPointSize(40);
        historyRecord->setFont(font);
        achievement = new QPushButton(functionList);
        achievement->setObjectName("achievement");
        achievement->setGeometry(QRect(260, 20, 211, 81));
        achievement->setSizeIncrement(QSize(0, 0));
        achievement->setFont(font);
        achievement->setStyleSheet(QString::fromUtf8(""));
        achievement->setIconSize(QSize(20, 20));
        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        start->setGeometry(QRect(230, 150, 471, 371));
        start->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TomClock", nullptr));
        historyRecord->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        achievement->setText(QCoreApplication::translate("MainWindow", "\346\210\220\345\260\261", nullptr));
        start->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
