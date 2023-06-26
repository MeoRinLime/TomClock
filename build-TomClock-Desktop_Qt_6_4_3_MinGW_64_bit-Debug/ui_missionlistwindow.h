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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MissionListWindow
{
public:

    void setupUi(QWidget *MissionListWindow)
    {
        if (MissionListWindow->objectName().isEmpty())
            MissionListWindow->setObjectName("MissionListWindow");
        MissionListWindow->resize(400, 300);

        retranslateUi(MissionListWindow);

        QMetaObject::connectSlotsByName(MissionListWindow);
    } // setupUi

    void retranslateUi(QWidget *MissionListWindow)
    {
        MissionListWindow->setWindowTitle(QCoreApplication::translate("MissionListWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MissionListWindow: public Ui_MissionListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSIONLISTWINDOW_H
