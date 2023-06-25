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
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AchievementWindow
{
public:
    QLabel *TomatoLabel;
    QLabel *numOfTomato;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *AchievementWindow)
    {
        if (AchievementWindow->objectName().isEmpty())
            AchievementWindow->setObjectName("AchievementWindow");
        AchievementWindow->resize(600, 400);
        AchievementWindow->setMinimumSize(QSize(600, 400));
        TomatoLabel = new QLabel(AchievementWindow);
        TomatoLabel->setObjectName("TomatoLabel");
        TomatoLabel->setGeometry(QRect(20, 20, 61, 20));
        numOfTomato = new QLabel(AchievementWindow);
        numOfTomato->setObjectName("numOfTomato");
        numOfTomato->setGeometry(QRect(100, 20, 131, 21));
        scrollArea = new QScrollArea(AchievementWindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 50, 561, 331));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(0);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 561, 331));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(AchievementWindow);

        QMetaObject::connectSlotsByName(AchievementWindow);
    } // setupUi

    void retranslateUi(QWidget *AchievementWindow)
    {
        TomatoLabel->setText(QCoreApplication::translate("AchievementWindow", "\345\267\262\346\234\211\347\225\252\350\214\204\346\225\260", nullptr));
        numOfTomato->setText(QCoreApplication::translate("AchievementWindow", "0", nullptr));
        (void)AchievementWindow;
    } // retranslateUi

};

namespace Ui {
    class AchievementWindow: public Ui_AchievementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACHIEVEMENTWINDOW_H
