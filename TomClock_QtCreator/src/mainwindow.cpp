#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

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
