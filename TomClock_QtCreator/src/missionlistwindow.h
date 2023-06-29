#ifndef MISSIONLISTWINDOW_H
#define MISSIONLISTWINDOW_H

#include <QWidget>
#include<QGridLayout>
#include<QVector>
#include<QMessageBox>
#include "mission.h"
#include"missionpushbutton.h"
#include"tomclockdatabase.h"
namespace Ui {
class MissionListWindow;
}

class MissionListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MissionListWindow(QWidget *parent = nullptr);
    ~MissionListWindow();

signals:
    void jumpToRunWindows(Mission mission);//传送任务信息并前往计时界面
    void create();//创建新任务信号
    void BacktoMain();//返回主菜单信号

private slots:
    void MaintoList();//主界面来到任务列表界面
    void disapearChoice();//掩盖选项按钮
    void deleteMission();//删除任务
    void beginMission();//开始任务
    void recieveMission(Mission mission);//获取新创建的任务
    void on_backtoMain_clicked();//返回主界面
    void on_create_clicked();//创建新任务
    void changeMission(Mission mi);//改变已有任务信息
private:
    Ui::MissionListWindow *ui;
    QVector<Mission>missions;//任务容器
    QGridLayout* gL;//网格布局
    QVector<MissionPushButton*>MPBTS;//任务选项容器


};


#endif // MISSIONLISTWINDOW_H
