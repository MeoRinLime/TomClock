#include "missionpushbutton.h"
#include "ui_missionpushbutton.h"

MissionPushButton::MissionPushButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MissionPushButton)
{
    ui->setupUi(this);

    hBlt=new QHBoxLayout();
     pBtn=new QPushButton();
    mBegin=new QPushButton();
    mChange=new QPushButton();
    mDelete=new QPushButton();
     mBegin->setText("开始");
     mBegin->setStyleSheet(
        "QPushButton{"                             // 正常状态样式
        "background-color: rgb(200, 200, 200);"       // 背景色（也可以设置图片）
        "color: white;"                            // 字体颜色
        "font: bold 13px;"                         // 字体: 加粗 大小
        "border-radius: 5px;"                      // 边框圆角半径像素
        "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
        "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
        "text-align: center;"                        // 文本：左对齐
        "}"

        "QPushButton:focus{"                       // 聚焦样式
        "background-color:rgb(255, 128, 64);"
        "color: white;"
        "border-radius: 5px;"
        "border: 2px solid white;"
        "border-style:outset;"
        "font:bold 13px;"
        "text-align: center;"
        "}");
     mBegin->setMinimumSize(QSize(50,0));   //width height
     mBegin->setMaximumSize(QSize(50,100));

    mChange->setText("修改");
    mChange->setStyleSheet(
         "QPushButton{"                             // 正常状态样式
         "background-color: rgb(200, 200, 200);"       // 背景色（也可以设置图片）
         "color: white;"                            // 字体颜色
         "font: bold 13px;"                         // 字体: 加粗 大小
         "border-radius: 5px;"                      // 边框圆角半径像素
         "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
         "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
         "text-align: center;"                        // 文本：左对齐
         "}"

         "QPushButton:focus{"                       // 聚焦样式
         "background-color:rgb(255, 128, 64);"
         "color: white;"
         "border-radius: 5px;"
         "border: 2px solid white;"
         "border-style:outset;"
         "font:bold 13px;"
         "text-align: center;"
         "}");
    mChange->setMinimumSize(QSize(50,0));   //width height
    mChange->setMaximumSize(QSize(50,100));


    mDelete->setText("删除");
     mDelete->setStyleSheet(
        "QPushButton{"                             // 正常状态样式
        "background-color: rgb(200, 200, 200);"       // 背景色（也可以设置图片）
        "color: white;"                            // 字体颜色
        "font: bold 13px;"                         // 字体: 加粗 大小
        "border-radius: 5px;"                      // 边框圆角半径像素
        "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
        "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
        "text-align: center;"                        // 文本：左对齐
        "}"

        "QPushButton:focus{"                       // 聚焦样式
        "background-color:rgb(255, 128, 64);"
        "color: white;"
        "border-radius: 5px;"
        "border: 2px solid white;"
        "border-style:outset;"
        "font:bold 13px;"
        "text-align: center;"
        "}");
     mDelete->setMinimumSize(QSize(50,0));   //width height
     mDelete->setMaximumSize(QSize(50,100));
     pBtn->setText("ooooo");



    pBtn->setStyleSheet(
        "QPushButton{"                             // 正常状态样式
        "background-color: rgb(200, 200, 200);"       // 背景色（也可以设置图片）
        "color: white;"                            // 字体颜色
        "font: bold 13px;"                         // 字体: 加粗 大小
        "border-radius: 5px;"                      // 边框圆角半径像素
        "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
        "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
        "text-align: center;"                        // 文本：左对齐
        "}"

        "QPushButton:focus{"                       // 聚焦样式
        "background-color:rgb(255, 128, 64);"
        "color: white;"
        "border-radius: 5px;"
        "border: 2px solid white;"
        "border-style:outset;"
        "font:bold 13px;"
        "text-align: center;"
        "}");
    pBtn->setMinimumSize(QSize(700,0));   //width height
    pBtn->setMaximumSize(QSize(750,100));
    connect(pBtn,&QPushButton::clicked,this,&MissionPushButton::setAllNum);
    hBlt->addWidget(pBtn);
    this->setLayout(hBlt);
    connect(this->mDelete,&QPushButton::clicked,this,&MissionPushButton::sentDelete);
    connect(this->mBegin,&QPushButton::clicked,this,&MissionPushButton::sentBegin);
}

MissionPushButton::~MissionPushButton()
{
    delete ui;
    delete pBtn;
    delete hBlt;
    delete mBegin;
    delete mChange;
    delete mDelete;
}


void MissionPushButton::setNum(int n){
    num=n;
}
void MissionPushButton::setAllNum(){
    allNum=num;
    pBtn->setMinimumSize(QSize(500,0));   //width height
    pBtn->setMaximumSize(QSize(600,100));
    if(hBlt->count()==1){
    hBlt->addWidget(mBegin);
    hBlt->addWidget(mChange);
    hBlt->addWidget(mDelete);
    }

    mBegin->show();
    mChange->show();
    mDelete->show();

}
int MissionPushButton::getallNum(){
    return allNum;
}
int MissionPushButton::allNum=-1;
void MissionPushButton::disapearChoice(){
    if(num!=allNum){

        mBegin->hide();
    mChange->hide();
        mDelete->hide();
    pBtn->setMinimumSize(QSize(500,0));   //width height
    pBtn->setMaximumSize(QSize(750,100));
    }
}

QPushButton* MissionPushButton::getPBtn(){
    return pBtn;
}

void MissionPushButton::sentDelete(){
    qDebug()<<pBtn->text();
    this->hide();
    emit deleteMission();

}

void MissionPushButton::setAN(int n){
    allNum=n;
}

void MissionPushButton::sentBegin(){
    Mission missionmm;
    missionmm.setId(1);
    missionmm.setName("ggg");
    missionmm.setRelaxTime(QTime(0,2,0));
     missionmm.setWorkTime(QTime(0,30,0));
    emit beginMission(missionmm);

}
