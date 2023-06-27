/********************************************************************************
** Form generated from reading UI file 'missionpushbutton.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISSIONPUSHBUTTON_H
#define UI_MISSIONPUSHBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MissionPushButton
{
public:

    void setupUi(QWidget *MissionPushButton)
    {
        if (MissionPushButton->objectName().isEmpty())
            MissionPushButton->setObjectName("MissionPushButton");
        MissionPushButton->resize(750, 50);
        MissionPushButton->setMinimumSize(QSize(750, 50));
        MissionPushButton->setMaximumSize(QSize(750, 50));

        retranslateUi(MissionPushButton);

        QMetaObject::connectSlotsByName(MissionPushButton);
    } // setupUi

    void retranslateUi(QWidget *MissionPushButton)
    {
        MissionPushButton->setWindowTitle(QCoreApplication::translate("MissionPushButton", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MissionPushButton: public Ui_MissionPushButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSIONPUSHBUTTON_H
