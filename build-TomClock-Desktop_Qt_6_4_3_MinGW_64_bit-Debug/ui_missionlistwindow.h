/********************************************************************************
** Form generated from reading UI file 'missionlistwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISSIONLISTWINDOW_H
#define UI_MISSIONLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MissionListWindow
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton;

    void setupUi(QWidget *MissionListWindow)
    {
        if (MissionListWindow->objectName().isEmpty())
            MissionListWindow->setObjectName("MissionListWindow");
        MissionListWindow->resize(800, 628);
        MissionListWindow->setMinimumSize(QSize(800, 500));
        label = new QLabel(MissionListWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 20, 151, 51));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(600, 400));
        scrollArea = new QScrollArea(MissionListWindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(-1, 79, 801, 551));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 782, 4000));
        scrollAreaWidgetContents->setMinimumSize(QSize(600, 4000));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(MissionListWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 30, 75, 23));

        retranslateUi(MissionListWindow);

        QMetaObject::connectSlotsByName(MissionListWindow);
    } // setupUi

    void retranslateUi(QWidget *MissionListWindow)
    {
        MissionListWindow->setWindowTitle(QCoreApplication::translate("MissionListWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("MissionListWindow", "<html><head/><body><p><span style=\" font-size:28pt;\">\344\273\273\345\212\241\345\210\227\350\241\250</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MissionListWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MissionListWindow: public Ui_MissionListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSIONLISTWINDOW_H
