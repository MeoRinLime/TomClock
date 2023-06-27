#include "missionlistwindow.h"
#include "ui_missionlistwindow.h"

MissionListWindow::MissionListWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MissionListWindow)
{
     gL=new  QGridLayout();
    ui->setupUi(this);
    for(int i=0;i<20;i++){
        //测试部分
        Mission mmm;
        mmm.setName("nnn"+QString::number(i));
        mmm.setRelaxTime(QTime(0,10,0));
        mmm.setWorkTime(QTime(0,30,0));
        missions.push_back(mmm);
        QString mmmmm=mmm.getName()+"   "+mmm.getWorkTime().toString()+"  "+mmm.getRelaxTime().toString();
        MissionPushButton *mpb=new   MissionPushButton();
        mpb->getPBtn()->setText(mmmmm);
        mpb->setNum(i);
        MPBTS.push_back(mpb);
        gL->addWidget(mpb);
        connect(mpb->getPBtn(),&QPushButton::clicked,this,&MissionListWindow::disapearChoice);
        connect(mpb,&MissionPushButton::deleteMission,this,&MissionListWindow::deleteMission);
        connect(mpb,&MissionPushButton::beginMission,this,&MissionListWindow::beginMission);
         gL->setRowStretch(i+1,1);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(50*MPBTS.size());
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

void MissionListWindow::deleteMission(){




   MPBTS.erase( MPBTS.begin()+MissionPushButton::getallNum());

    gL=new  QGridLayout();
    for(int i=0;i<MPBTS.size();i++){
        MPBTS[i]->setNum(i);
        gL->addWidget(MPBTS[i]);
        gL->setRowStretch(i+1,1);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(50*MPBTS.size());
    ui->scrollArea->widget()->setLayout(gL);
    qDebug()<<MissionPushButton::getallNum()<<"  "<<gL->count()<<" "<<gL->rowCount();
}
void MissionListWindow::beginMission(){
    emit jumpToRunWindows(missions[MissionPushButton::getallNum()]);
    this->hide();


}
