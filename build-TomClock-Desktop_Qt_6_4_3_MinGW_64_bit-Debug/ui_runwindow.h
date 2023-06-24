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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunWindow
{
public:

    void setupUi(QWidget *RunWindow)
    {
        if (RunWindow->objectName().isEmpty())
            RunWindow->setObjectName("RunWindow");
        RunWindow->resize(400, 300);

        retranslateUi(RunWindow);

        QMetaObject::connectSlotsByName(RunWindow);
    } // setupUi

    void retranslateUi(QWidget *RunWindow)
    {
        RunWindow->setWindowTitle(QCoreApplication::translate("RunWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RunWindow: public Ui_RunWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNWINDOW_H
