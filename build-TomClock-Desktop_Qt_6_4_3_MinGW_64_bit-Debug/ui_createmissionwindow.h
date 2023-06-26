/********************************************************************************
** Form generated from reading UI file 'createmissionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEMISSIONWINDOW_H
#define UI_CREATEMISSIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateMissionWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameOfMission;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *relaxTime;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_20;
    QSplitter *splitter;
    QPushButton *comfirm;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *workTime;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *CreateMissionWindow)
    {
        if (CreateMissionWindow->objectName().isEmpty())
            CreateMissionWindow->setObjectName("CreateMissionWindow");
        CreateMissionWindow->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateMissionWindow->sizePolicy().hasHeightForWidth());
        CreateMissionWindow->setSizePolicy(sizePolicy);
        CreateMissionWindow->setMinimumSize(QSize(600, 400));
        CreateMissionWindow->setMaximumSize(QSize(600, 400));
        CreateMissionWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 189, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        gridLayout = new QGridLayout(CreateMissionWindow);
        gridLayout->setObjectName("gridLayout");
        cancel = new QPushButton(CreateMissionWindow);
        cancel->setObjectName("cancel");
        sizePolicy.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy);
        cancel->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(255, 255, 255);\n"
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

        gridLayout->addWidget(cancel, 0, 3, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 10, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(CreateMissionWindow);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        horizontalLayout->addWidget(label);

        nameOfMission = new QLineEdit(CreateMissionWindow);
        nameOfMission->setObjectName("nameOfMission");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameOfMission->sizePolicy().hasHeightForWidth());
        nameOfMission->setSizePolicy(sizePolicy1);
        nameOfMission->setStyleSheet(QString::fromUtf8("font: 290 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(nameOfMission);

        horizontalLayout->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_17, 0, 2, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_21, 1, 3, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 6, 2, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_19, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(CreateMissionWindow);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        horizontalLayout_3->addWidget(label_4);

        relaxTime = new QComboBox(CreateMissionWindow);
        relaxTime->addItem(QString());
        relaxTime->addItem(QString());
        relaxTime->addItem(QString());
        relaxTime->addItem(QString());
        relaxTime->addItem(QString());
        relaxTime->addItem(QString());
        relaxTime->setObjectName("relaxTime");
        sizePolicy1.setHeightForWidth(relaxTime->sizePolicy().hasHeightForWidth());
        relaxTime->setSizePolicy(sizePolicy1);
        relaxTime->setStyleSheet(QString::fromUtf8("font: 290 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(relaxTime);

        label_5 = new QLabel(CreateMissionWindow);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        horizontalLayout_3->addWidget(label_5);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout_3, 5, 2, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_22, 7, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 9, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_20, 1, 4, 1, 1);

        splitter = new QSplitter(CreateMissionWindow);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        comfirm = new QPushButton(splitter);
        comfirm->setObjectName("comfirm");
        sizePolicy.setHeightForWidth(comfirm->sizePolicy().hasHeightForWidth());
        comfirm->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        comfirm->setFont(font);
        comfirm->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton{\n"
"background-color: rgb(255, 255, 255);\n"
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
        splitter->addWidget(comfirm);

        gridLayout->addWidget(splitter, 8, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(CreateMissionWindow);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        horizontalLayout_2->addWidget(label_2);

        workTime = new QComboBox(CreateMissionWindow);
        workTime->addItem(QString());
        workTime->addItem(QString());
        workTime->addItem(QString());
        workTime->addItem(QString());
        workTime->addItem(QString());
        workTime->addItem(QString());
        workTime->setObjectName("workTime");
        sizePolicy.setHeightForWidth(workTime->sizePolicy().hasHeightForWidth());
        workTime->setSizePolicy(sizePolicy);
        workTime->setStyleSheet(QString::fromUtf8("font: 290 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(workTime);

        label_3 = new QLabel(CreateMissionWindow);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        horizontalLayout_2->addWidget(label_3);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout_2, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 1);
        gridLayout->setRowStretch(6, 1);
        gridLayout->setRowStretch(7, 1);
        gridLayout->setRowStretch(8, 1);
        gridLayout->setRowStretch(9, 1);
        gridLayout->setRowStretch(10, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(3, 1);

        retranslateUi(CreateMissionWindow);

        QMetaObject::connectSlotsByName(CreateMissionWindow);
    } // setupUi

    void retranslateUi(QWidget *CreateMissionWindow)
    {
        CreateMissionWindow->setWindowTitle(QCoreApplication::translate("CreateMissionWindow", "Form", nullptr));
        cancel->setText(QCoreApplication::translate("CreateMissionWindow", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("CreateMissionWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">\344\273\273\345\212\241\345\220\215\357\274\232</span></p></body></html>", nullptr));
        nameOfMission->setText(QString());
        label_4->setText(QCoreApplication::translate("CreateMissionWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">\344\274\221\346\201\257\346\227\266\351\227\264\357\274\232</span></p></body></html>", nullptr));
        relaxTime->setItemText(0, QCoreApplication::translate("CreateMissionWindow", "2", nullptr));
        relaxTime->setItemText(1, QCoreApplication::translate("CreateMissionWindow", "3", nullptr));
        relaxTime->setItemText(2, QCoreApplication::translate("CreateMissionWindow", "4", nullptr));
        relaxTime->setItemText(3, QCoreApplication::translate("CreateMissionWindow", "6", nullptr));
        relaxTime->setItemText(4, QCoreApplication::translate("CreateMissionWindow", "8", nullptr));
        relaxTime->setItemText(5, QCoreApplication::translate("CreateMissionWindow", "10", nullptr));

        label_5->setText(QCoreApplication::translate("CreateMissionWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\210\206\351\222\237</span></p></body></html>", nullptr));
        comfirm->setText(QCoreApplication::translate("CreateMissionWindow", "\346\267\273\345\212\240\345\210\260\344\273\273\345\212\241\345\210\227\350\241\250", nullptr));
        label_2->setText(QCoreApplication::translate("CreateMissionWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\267\245\344\275\234\346\227\266\351\227\264\357\274\232</span></p></body></html>", nullptr));
        workTime->setItemText(0, QCoreApplication::translate("CreateMissionWindow", "15", nullptr));
        workTime->setItemText(1, QCoreApplication::translate("CreateMissionWindow", "20", nullptr));
        workTime->setItemText(2, QCoreApplication::translate("CreateMissionWindow", "25", nullptr));
        workTime->setItemText(3, QCoreApplication::translate("CreateMissionWindow", "30", nullptr));
        workTime->setItemText(4, QCoreApplication::translate("CreateMissionWindow", "40", nullptr));
        workTime->setItemText(5, QCoreApplication::translate("CreateMissionWindow", "50", nullptr));

        label_3->setText(QCoreApplication::translate("CreateMissionWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\210\206\351\222\237</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateMissionWindow: public Ui_CreateMissionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEMISSIONWINDOW_H
