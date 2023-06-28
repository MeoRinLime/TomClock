#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include "mission.h"
#include <QMainWindow>

namespace Ui {
class RunWindow;
}

class RunWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RunWindow(QWidget *parent = nullptr);
    ~RunWindow();

signals:
    void JumptoMain();   //界面跳转
    void noTomato();      //告知控制模块 本次任务无番茄
    void oneMoreTomato(); //告知控制模块 本次任务有番茄

private:
    Ui::RunWindow *ui;
    Mission curMission;  //当前的任务
    QTime displayedTime; //界面上显示的时间
    QTimer *secTimer;       //计时器 每秒一次
    QTimer *periodTimer;    //计时器 每段workTime/relaxTime一次 用于切换工作休息
    int whichPeriod;        //记录 当前处于哪一个番茄钟时间段 范围从0到7
    bool oncePaused;        //记录 曾经是否暂停过

    void closeEvent(QCloseEvent *event); //重写closeEvent，跳转回mainWindow

private slots:
    void ListtoRun(const Mission &mission);       //界面跳转
    void processTimeout();  //处理计时器信号
    void nextPeriod();      //进入下一个番茄钟时间段
    void on_PauseResumeButton_clicked();
    void on_AbortButton_clicked();
};

#endif // RUNWINDOW_H
