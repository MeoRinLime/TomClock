#include "createmissionwindow.h"
#include "ui_createmissionwindow.h"

CreateMissionWindow::CreateMissionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateMissionWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("CreateMissionWindow {border-image:url(:/images/resourse/images/background/bg3.png);}");
}

CreateMissionWindow::~CreateMissionWindow()
{
    delete ui;
}

void CreateMissionWindow::MaintoCreate()
{
    this->show();
}

void CreateMissionWindow::on_cancel_clicked()
{
    this->hide();
}


void CreateMissionWindow::on_comfirm_clicked()
{
   Mission mi;//新建一个任务对象来记录新创建的任务的信息

    mi.setName( ui->nameOfMission->text());//获取用户输入的任务名

    QTime ti;

    //获取新任务的工作时间
    ti.setHMS(0,ui->workTime->currentIndex(),0);
    mi.setWorkTime(ti);

    //获取新任务的休息时间
    ti.setHMS(0,ui->relaxTime->currentIndex(),0);
    mi.setWorkTime(ti);

    mi.setCreateTime(QDate::currentDate());

    this->close();
}

