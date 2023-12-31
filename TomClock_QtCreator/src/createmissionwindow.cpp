#include "createmissionwindow.h"
#include "ui_createmissionwindow.h"

CreateMissionWindow::CreateMissionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateMissionWindow)
{
    ui->setupUi(this);

    //设置窗口样式
    this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");
}

CreateMissionWindow::~CreateMissionWindow()
{
    delete ui;
}

void CreateMissionWindow::toCreate()
{
    this->show();
}

void CreateMissionWindow::on_cancel_clicked()
{
    this->hide();
}


void CreateMissionWindow::on_comfirm_clicked()
{


    mi.setName( ui->nameOfMission->text());//获取用户输入的任务名
    qDebug()<<ui->nameOfMission->text();
    QTime ti;
    //只有分钟的选项可选，小时和秒默认都是0
    //获取新任务的工作时间
    ti.setHMS(0,ui->workTime->currentText().toInt(),0);
    mi.setWorkTime(ti);
    qDebug()<<ti.toString();
        //获取新任务的休息时间
    ti.setHMS(0,ui->relaxTime->currentText().toInt(),0);
    mi.setRelaxTime(ti);
    qDebug()<<ti.toString();
    mi.setCreateTime(QDate::currentDate());
    emit sentAndJump(mi);
    this->close();
}

void CreateMissionWindow::changeEvent(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
