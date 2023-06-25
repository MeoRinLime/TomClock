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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *optionalFunction;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *historyData;
    QPushButton *personalAchievement;
    QPushButton *missionList;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QPushButton *startIcon;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *startText;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *settingAndAbout;
    QHBoxLayout *horizontalLayout;
    QPushButton *settings;
    QPushButton *aboutTeam;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(671, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/resourse/images/Icons/Main_Color/tomato1.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(600, 400));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        optionalFunction = new QWidget(centralwidget);
        optionalFunction->setObjectName("optionalFunction");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(optionalFunction->sizePolicy().hasHeightForWidth());
        optionalFunction->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\351\223\255\347\237\263\344\275\223 \347\256\200")});
        optionalFunction->setFont(font);
        optionalFunction->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
"}"));
        horizontalLayout_2 = new QHBoxLayout(optionalFunction);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        historyData = new QPushButton(optionalFunction);
        historyData->setObjectName("historyData");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(historyData->sizePolicy().hasHeightForWidth());
        historyData->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(historyData);

        personalAchievement = new QPushButton(optionalFunction);
        personalAchievement->setObjectName("personalAchievement");
        sizePolicy1.setHeightForWidth(personalAchievement->sizePolicy().hasHeightForWidth());
        personalAchievement->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(personalAchievement);

        missionList = new QPushButton(optionalFunction);
        missionList->setObjectName("missionList");
        sizePolicy1.setHeightForWidth(missionList->sizePolicy().hasHeightForWidth());
        missionList->setSizePolicy(sizePolicy1);
        missionList->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
"}"));

        horizontalLayout_2->addWidget(missionList);


        gridLayout_2->addWidget(optionalFunction, 0, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(358, 19, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer_3, 0, 2, 1, 4);

        horizontalSpacer = new QSpacerItem(106, 278, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 2, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_4 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 0, 1, 1, 1);

        startIcon = new QPushButton(widget);
        startIcon->setObjectName("startIcon");
        sizePolicy.setHeightForWidth(startIcon->sizePolicy().hasHeightForWidth());
        startIcon->setSizePolicy(sizePolicy);
        startIcon->setMinimumSize(QSize(350, 200));
        startIcon->setIcon(icon);
        startIcon->setIconSize(QSize(200, 200));
        startIcon->setFlat(true);

        gridLayout->addWidget(startIcon, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(34, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 2, 1, 1, 1);


        gridLayout_2->addWidget(widget, 1, 1, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(106, 278, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 5, 2, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_6 = new QSpacerItem(105, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        startText = new QPushButton(widget_2);
        startText->setObjectName("startText");
        sizePolicy.setHeightForWidth(startText->sizePolicy().hasHeightForWidth());
        startText->setSizePolicy(sizePolicy);
        startText->setMinimumSize(QSize(200, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\351\223\255\347\237\263\344\275\223 \347\256\200")});
        font1.setPointSize(22);
        startText->setFont(font1);

        horizontalLayout_3->addWidget(startText);

        horizontalSpacer_7 = new QSpacerItem(104, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        gridLayout_2->addWidget(widget_2, 2, 1, 1, 4);

        verticalSpacer_2 = new QSpacerItem(106, 44, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer_2, 3, 0, 2, 1);

        verticalSpacer = new QSpacerItem(218, 44, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer, 3, 1, 2, 2);

        verticalSpacer_4 = new QSpacerItem(248, 9, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer_4, 3, 3, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(105, 28, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 4, 3, 1, 1);

        settingAndAbout = new QWidget(centralwidget);
        settingAndAbout->setObjectName("settingAndAbout");
        sizePolicy.setHeightForWidth(settingAndAbout->sizePolicy().hasHeightForWidth());
        settingAndAbout->setSizePolicy(sizePolicy);
        settingAndAbout->setFont(font);
        settingAndAbout->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
"}"));
        horizontalLayout = new QHBoxLayout(settingAndAbout);
        horizontalLayout->setObjectName("horizontalLayout");
        settings = new QPushButton(settingAndAbout);
        settings->setObjectName("settings");
        sizePolicy1.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(settings);

        aboutTeam = new QPushButton(settingAndAbout);
        aboutTeam->setObjectName("aboutTeam");
        sizePolicy1.setHeightForWidth(aboutTeam->sizePolicy().hasHeightForWidth());
        aboutTeam->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(aboutTeam);


        gridLayout_2->addWidget(settingAndAbout, 4, 4, 1, 2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TomClock", nullptr));
        historyData->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        personalAchievement->setText(QCoreApplication::translate("MainWindow", "\344\270\252\344\272\272\346\210\220\345\260\261", nullptr));
        missionList->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\345\210\227\350\241\250", nullptr));
        startIcon->setText(QString());
        startText->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        settings->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        aboutTeam->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
