#include "missionlistwindow.h"
#include "ui_missionlistwindow.h"

MissionListWindow::MissionListWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MissionListWindow)
{
    QGridLayout* gL=new  QGridLayout();
    ui->setupUi(this);
    for(int i=0;i<20;i++){
        //测试部分

        MissionPushButton *mpb=new   MissionPushButton();

        mpb->setNum(i);
        MPBTS.push_back(mpb);
        gL->addWidget(mpb);
        connect(mpb->getPBtn(),&QPushButton::clicked,this,&MissionListWindow::disapearChoice);
         gL->setRowStretch(i+1,1);
    }
     ui->scrollArea->widget()->setLayout(gL);
}

MissionListWindow::~MissionListWindow()
{
    delete ui;
}

void MissionListWindow::MaintoList()
{
    this->show();
}

void MissionListWindow::disapearChoice(){
    for(int i=0;i<MPBTS.size();i++){
        MPBTS[i]->disapearChoice();
    }
}
