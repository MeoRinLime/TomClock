/********************************************************************************
** Form generated from reading UI file 'achievementwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACHIEVEMENTWINDOW_H
#define UI_ACHIEVEMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AchievementWindow
{
public:

    void setupUi(QWidget *AchievementWindow)
    {
        if (AchievementWindow->objectName().isEmpty())
            AchievementWindow->setObjectName("AchievementWindow");
        AchievementWindow->resize(400, 300);

        retranslateUi(AchievementWindow);

        QMetaObject::connectSlotsByName(AchievementWindow);
    } // setupUi

    void retranslateUi(QWidget *AchievementWindow)
    {
        AchievementWindow->setWindowTitle(QCoreApplication::translate("AchievementWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AchievementWindow: public Ui_AchievementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHIEVEMENTWINDOW_H
