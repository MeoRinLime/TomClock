#include "missionlistwindow.h"
#include "ui_missionlistwindow.h"

MissionListWindow::MissionListWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MissionListWindow)
{

    ui->setupUi(this);
    //设置界面布局和展示界面
    this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");
    gL=new  QGridLayout();
    ui->scrollArea->viewport()->setStyleSheet(".QWidget{background-color:transparent;}");

    for(int i=0;i<missions.size();i++){
        QString mmmmm=missions[i].getName()+"   "+missions[i].getWorkTime().toString()+"  "+missions[i].getRelaxTime().toString();
        MissionPushButton *mpb=new   MissionPushButton();
        mpb->getPBtn()->setText(mmmmm);
        mpb->setNum(i);

        gL->addWidget(mpb);
        connect(mpb->getPBtn(),&QPushButton::clicked,this,&MissionListWindow::disapearChoice);
        connect(mpb,&MissionPushButton::deleteMission,this,&MissionListWindow::deleteMission);
        connect(mpb,&MissionPushButton::beginMission,this,&MissionListWindow::beginMission);
        connect(mpb,SIGNAL(sentChange(Mission)),this,SLOT(changeMission(Mission)));
         gL->setRowStretch(i+1,1);
        MPBTS.push_back(mpb);
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

    //删除任务并刷新界面显示
    delete MPBTS[MissionPushButton::getallNum()];
    missions.erase( missions.begin()+MissionPushButton::getallNum());
    MPBTS.erase( MPBTS.begin()+MissionPushButton::getallNum());
    delete gL;
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
    //发送开始信号和选中的任务
    emit jumpToRunWindows(missions[MissionPushButton::getallNum()]);
    this->hide();


}

void MissionListWindow::recieveMission(Mission mission){
    //获取新创建任务信息并刷新界面显示
    missions.push_back(mission);

    delete gL;
    gL = new  QGridLayout();

    QString m = mission.getName()+"   "+mission.getWorkTime().toString()+"  "+mission.getRelaxTime().toString();

    MissionPushButton *mpb = new MissionPushButton();
    mpb->getPBtn()->setText(m);
    mpb->setNum(missions.size()-1);
    connect(mpb->getPBtn(),&QPushButton::clicked,this,&MissionListWindow::disapearChoice);
    connect(mpb,&MissionPushButton::deleteMission,this,&MissionListWindow::deleteMission);
    connect(mpb,&MissionPushButton::beginMission,this,&MissionListWindow::beginMission);
    connect(mpb,SIGNAL(sentChange(Mission)),this,SLOT(changeMission(Mission)));
    MPBTS.push_back(mpb);
    for(int i=0;i<missions.size();i++){
        gL->addWidget(MPBTS[i]);

        gL->setRowStretch(i+1,1);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(50*MPBTS.size());
    ui->scrollArea->widget()->setLayout(gL);
}


void MissionListWindow::on_backtoMain_clicked()
{
    this->hide();
    emit BacktoMain();
}


void MissionListWindow::on_create_clicked()
{
    emit create();
}
void MissionListWindow::changeMission(Mission mi){
  //改变任务信息
    missions[MissionPushButton::getallNum()].setName(mi.getName());
    missions[MissionPushButton::getallNum()].setWorkTime(mi.getWorkTime());
    missions[MissionPushButton::getallNum()].setRelaxTime(mi.getRelaxTime());
    QString m=mi.getName()+"   "+mi.getWorkTime().toString()+"  "+mi.getRelaxTime().toString();
    MPBTS[MissionPushButton::getallNum()]->getPBtn()->setText(m);


}
