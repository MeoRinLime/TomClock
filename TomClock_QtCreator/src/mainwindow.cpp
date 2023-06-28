#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QResizeEvent>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("QMainWindow {border-image:url(:/images/resourse/images/background/bg3.png);}");
    //bg3是浅色，bg2是深色
}
//:/images/resourse/images/background/bg1.png
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_historyData_clicked()
{
    this->hide();
    emit JumptoHistory();
}

//点击跳转至历史数据界面

void MainWindow::on_personalAchievement_clicked()
{
    this->hide();
    emit JumptoAchievement();
}
//点击跳转至个人成就界面

void MainWindow::on_missionList_clicked()
{
    this->hide();
    emit JumptoMissionList();
}
//点击跳转至任务列表界面

void MainWindow::on_startIcon_clicked()
{
    this->hide();
    emit JumptoMissionList();
}
//点击跳转至任务列表界面


void MainWindow::on_startText_clicked()
{
    this->hide();
    emit JumptoMissionList();
}
//点击开始按钮或者中心图标跳转到任务列表界面进行选择

void MainWindow::on_settings_clicked()
{
    this->hide();
    emit JumptoSettings();
}
//点击跳转至设置界面

void MainWindow::on_aboutTeam_clicked()
{
    this->hide();
    emit JumptoAbout();
}
//点击跳转至关于界面

void MainWindow::SettingstoMain()
{
    this->show();
}
//设置界面跳转到主界面

void MainWindow::HistorytoMain()
{
    this->show();
}

void MainWindow::RuntoMain()
{
    this->show();
}

void MainWindow::AchievetoMain()
{
    this->show();
}
//历史记录跳转到主界面

void MainWindow::AbouttoMain()
{
    this->show();
}
//关于界面跳转到主界面

void  MainWindow::OthertoMain()
{
    this->show();
}
