/********************************************************************************
** Form generated from reading UI file 'historywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYWINDOW_H
#define UI_HISTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryWindow
{
public:

    void setupUi(QWidget *HistoryWindow)
    {
        if (HistoryWindow->objectName().isEmpty())
            HistoryWindow->setObjectName("HistoryWindow");
        HistoryWindow->resize(400, 300);

        retranslateUi(HistoryWindow);

        QMetaObject::connectSlotsByName(HistoryWindow);
    } // setupUi

    void retranslateUi(QWidget *HistoryWindow)
    {
        HistoryWindow->setWindowTitle(QCoreApplication::translate("HistoryWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryWindow: public Ui_HistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWINDOW_H
