/********************************************************************************
** Form generated from reading UI file 'runwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNWINDOW_H
#define UI_RUNWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunWindow
{
public:
    QLabel *MissionNameLabel;
    QFrame *frame;
    QLabel *TimeDisplay;
    QWidget *widget;
    QPushButton *PauseResumeButton;
    QPushButton *AbortButton;

    void setupUi(QWidget *RunWindow)
    {
        if (RunWindow->objectName().isEmpty())
            RunWindow->setObjectName("RunWindow");
        RunWindow->resize(800, 500);
        RunWindow->setMinimumSize(QSize(800, 500));
        MissionNameLabel = new QLabel(RunWindow);
        MissionNameLabel->setObjectName("MissionNameLabel");
        MissionNameLabel->setGeometry(QRect(290, 30, 181, 41));
        MissionNameLabel->setMinimumSize(QSize(180, 40));
        MissionNameLabel->setAlignment(Qt::AlignCenter);
        frame = new QFrame(RunWindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(190, 100, 400, 241));
        frame->setMinimumSize(QSize(400, 240));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        TimeDisplay = new QLabel(frame);
        TimeDisplay->setObjectName("TimeDisplay");
        TimeDisplay->setGeometry(QRect(100, 70, 171, 91));
        TimeDisplay->setMinimumSize(QSize(170, 90));
        TimeDisplay->setAlignment(Qt::AlignCenter);
        widget = new QWidget(RunWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(190, 360, 381, 71));
        widget->setMinimumSize(QSize(380, 70));
        PauseResumeButton = new QPushButton(widget);
        PauseResumeButton->setObjectName("PauseResumeButton");
        PauseResumeButton->setGeometry(QRect(0, 0, 151, 61));
        PauseResumeButton->setMinimumSize(QSize(150, 60));
        AbortButton = new QPushButton(widget);
        AbortButton->setObjectName("AbortButton");
        AbortButton->setGeometry(QRect(230, 0, 151, 61));
        AbortButton->setMinimumSize(QSize(150, 60));

        retranslateUi(RunWindow);

        QMetaObject::connectSlotsByName(RunWindow);
    } // setupUi

    void retranslateUi(QWidget *RunWindow)
    {
        RunWindow->setWindowTitle(QCoreApplication::translate("RunWindow", "Form", nullptr));
        MissionNameLabel->setText(QCoreApplication::translate("RunWindow", "\345\255\246\344\271\240XXX", nullptr));
        TimeDisplay->setText(QCoreApplication::translate("RunWindow", "XX:XX", nullptr));
        PauseResumeButton->setText(QCoreApplication::translate("RunWindow", "\346\232\202\345\201\234", nullptr));
        AbortButton->setText(QCoreApplication::translate("RunWindow", "\347\273\210\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RunWindow: public Ui_RunWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNWINDOW_H
