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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryWindow
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *totalTime;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *numOfTotal;

    void setupUi(QWidget *HistoryWindow)
    {
        if (HistoryWindow->objectName().isEmpty())
            HistoryWindow->setObjectName("HistoryWindow");
        HistoryWindow->resize(800, 500);
        HistoryWindow->setMinimumSize(QSize(800, 500));
        scrollArea = new QScrollArea(HistoryWindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 40, 800, 600));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 800, 5000));
        scrollAreaWidgetContents->setMinimumSize(QSize(800, 5000));
        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(HistoryWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(61, 10, 561, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        totalTime = new QLabel(widget);
        totalTime->setObjectName("totalTime");

        horizontalLayout->addWidget(totalTime);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        numOfTotal = new QLabel(widget);
        numOfTotal->setObjectName("numOfTotal");

        horizontalLayout->addWidget(numOfTotal);


        retranslateUi(HistoryWindow);

        QMetaObject::connectSlotsByName(HistoryWindow);
    } // setupUi

    void retranslateUi(QWidget *HistoryWindow)
    {
        HistoryWindow->setWindowTitle(QCoreApplication::translate("HistoryWindow", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("HistoryWindow", "          \346\200\273\346\227\266\351\225\277\357\274\232", nullptr));
        totalTime->setText(QCoreApplication::translate("HistoryWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("HistoryWindow", "\346\200\273\344\273\273\345\212\241\350\256\260\345\275\225\346\225\260\357\274\232", nullptr));
        numOfTotal->setText(QCoreApplication::translate("HistoryWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryWindow: public Ui_HistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWINDOW_H
