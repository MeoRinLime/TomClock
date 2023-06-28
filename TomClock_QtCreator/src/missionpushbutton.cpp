#include "missionpushbutton.h"
#include "ui_missionpushbutton.h"

MissionPushButton::MissionPushButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MissionPushButton)
{
    ui->setupUi(this);
    mChangeConfirm=new QPushButton();
    mChangeCancel=new QPushButton();
    workTime =new QComboBox() ;
    relaxTime=new QComboBox() ;
    mName=new QLineEdit();

    hBlt=new QHBoxLayout();
     pBtn=new QPushButton();
    mBegin=new QPushButton();
    mChange=new QPushButton();
    mDelete=new QPushButton();

    QStringList sl1;
    sl1<<tr("15")<<tr("20")<<tr("25")<<tr("30")<<tr("40")<<tr("50");
    QStringList sl2;
    sl2<<tr("2")<<tr("3")<<tr("4")<<tr("6")<<tr("8")<<tr("10");
    workTime->addItems(sl1);
     relaxTime->addItems(sl2);
    mChangeConfirm->setText("确定");
    mChangeConfirm->setStyleSheet(
        "QPushButton{"                             // 正常状态样式
        "background-color: rgb(0, 250, 154);"       // 背景色（也可以设置图片）
        "color: white;"                            // 字体颜色
        "font: bold 13px;"                         // 字体: 加粗 大小
        "border-radius: 5px;"                      // 边框圆角半径像素
        "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
        "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
        "text-align: center;"                        // 文本：左对齐
        "}"

        "QPushButton:focus{"                       // 聚焦样式
        "background-color: rgb(0, 250, 154);"
        "color: white;"
        "border-radius: 5px;"
        "border: 2px solid white;"
        "border-style:outset;"
        "font:bold 13px;"
        "text-align: center;"
        "}");
    mChangeConfirm->setMinimumSize(QSize(50,0));   //width height
   mChangeConfirm->setMaximumSize(QSize(50,100));

    mChangeCancel->setText("取消");
    mChangeCancel->setStyleSheet(
        "QPushButton{"                             // 正常状态样式
        "background-color: rgb(205, 92, 92);"       // 背景色（也可以设置图片）
        "color: white;"                            // 字体颜色
        "font: bold 13px;"                         // 字体: 加粗 大小
        "border-radius: 5px;"                      // 边框圆角半径像素
        "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
        "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
        "text-align: center;"                        // 文本：左对齐
        "}"

        "QPushButton:focus{"                       // 聚焦样式
        "background-color: rgb(205, 92, 92);"
        "color: white;"
        "border-radius: 5px;"
        "border: 2px solid white;"
        "border-style:outset;"
        "font:bold 13px;"
        "text-align: center;"
        "}");
    mChangeCancel->setMinimumSize(QSize(50,0));   //width height
    mChangeCancel->setMaximumSize(QSize(50,100));

     mBegin->setText("开始");
     mBegin->setStyleSheet(
        "QPushButton{"                             // 正常状态样式
        "background-color: rgb(0, 250, 154);"       // 背景色（也可以设置图片）
        "color: white;"                            // 字体颜色
        "font: bold 13px;"                         // 字体: 加粗 大小
        "border-radius: 5px;"                      // 边框圆角半径像素
        "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
        "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
        "text-align: center;"                        // 文本：左对齐
        "}"

        "QPushButton:focus{"                       // 聚焦样式
        "background-color: rgb(0, 250, 154);"
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
         "background-color: rgb(30, 144, 255);"       // 背景色（也可以设置图片）
         "color: white;"                            // 字体颜色
         "font: bold 13px;"                         // 字体: 加粗 大小
         "border-radius: 5px;"                      // 边框圆角半径像素
         "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
         "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
         "text-align: center;"                        // 文本：左对齐
         "}"

         "QPushButton:focus{"                       // 聚焦样式
         "background-color:rgb(30, 144, 255);"
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
        "background-color: rgb(205, 92, 92);"       // 背景色（也可以设置图片）
        "color: white;"                            // 字体颜色
        "font: bold 13px;"                         // 字体: 加粗 大小
        "border-radius: 5px;"                      // 边框圆角半径像素
        "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
        "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
        "text-align: center;"                        // 文本：左对齐
        "}"

        "QPushButton:focus{"                       // 聚焦样式
        "background-color:rgb(205, 92, 92);"
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
        "background-color: transparent;"       // 背景色（也可以设置图片）
        "color: white;"                            // 字体颜色
        "font: bold 13px;"                         // 字体: 加粗 大小
        "border-radius: 5px;"                      // 边框圆角半径像素
        "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
        "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
        "text-align: center;"                        // 文本：左对齐
        "}"

        "QPushButton:focus{"                       // 聚焦样式
        "background-color:transparent;"
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
    connect(this->mChange,&QPushButton::clicked,this,&MissionPushButton::change_clicked);
    connect(this->mChangeCancel,&QPushButton::clicked,this,&MissionPushButton::cancelChange);
     connect(this->mChangeConfirm,&QPushButton::clicked,this,&MissionPushButton::confirmChange);
}

MissionPushButton::~MissionPushButton()
{
    delete ui;
    delete pBtn;
    delete hBlt;
    delete mBegin;
    delete mChange;
    delete mDelete;
   delete mChangeConfirm;
   delete mChangeCancel;
    delete workTime;
    delete relaxTime;
    delete mName;
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

    emit beginMission();

}

void MissionPushButton::change_clicked(){
    pBtn->hide();
    mBegin->hide();
    mChange->hide();
    mDelete->hide();

    name.clear();
    name.setText("任务名:");

    wT.clear();
    wT.setText("工作时间:");

    rT.clear();
    rT.setText("休息时间:");
    hBlt->addWidget(&name,1);
    hBlt->addWidget(mName,1);
     hBlt->addWidget(&wT,1);
    hBlt->addWidget(workTime,1);

      hBlt->addWidget(&rT,1);
    hBlt->addWidget(relaxTime,1);

     hBlt->addWidget(mChangeConfirm);
     hBlt->addWidget(mChangeCancel);
     mChangeConfirm->show();
     mChangeCancel->show();
     workTime->show();
     relaxTime->show();
     mName->show();
     name.show();
     wT.show();
     rT.show();
}

void MissionPushButton::cancelChange(){
     mChangeConfirm->hide();
     mChangeCancel->hide();
    workTime->hide();
     relaxTime->hide();
     mName->hide();
      name.hide();
      wT.hide();
     rT.hide();
      pBtn->show();
      mBegin->show();
      mChange->show();
      mDelete->show();

}
void MissionPushButton::confirmChange(){
      Mission mi;
      mi.setName(mName->text());
      mi.setWorkTime(QTime(0,workTime->currentText().toInt(),0));
      mi.setRelaxTime(QTime(0,relaxTime->currentText().toInt(),0));

      mChangeConfirm->hide();
      mChangeCancel->hide();
      workTime->hide();
      relaxTime->hide();
      mName->hide();
      name.hide();
      wT.hide();
      rT.hide();
      pBtn->show();
      mBegin->show();
      mChange->show();
      mDelete->show();
       QString mmmmm=mi.getName()+"   "+mi.getWorkTime().toString()+"  "+mi.getRelaxTime().toString();
      pBtn->setText(mmmmm);
       qDebug()<<mmmmm<<"拉拉";
      emit sentChange(mi);
}
