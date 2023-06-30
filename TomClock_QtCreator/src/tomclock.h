#ifndef TOMCLOCK_H
#define TOMCLOCK_H

#include "mainwindow.h"
#include "achievementwindow.h"
#include "createmissionwindow.h"
#include "historywindow.h"
#include "missionlistwindow.h"
#include "runwindow.h"
#include "settings.h"
#include "about.h"
#include "ourteam.h"
#include "tomclockdatabase.h"
#include <QString>
#include <QTranslator>

class TomClock : QObject
{
    Q_OBJECT
public:
    TomClock();
    ~TomClock();

    //初始化成就窗口，并连接
    void initAchieveWindow();
    //初始化任务列表窗口，并连接
    void initMissionListWindow();
    //初始化历史窗口，并连接
    void initHistoryWindow();
    void showWindow(); //显示主窗口
    int numOfTomato;
    void changeEvent(QEvent *event);

private:
    TomClockDatabase *tcDatabase;
    //先创建所有窗口，跳转页面就是隐藏和显示不同的窗口
    MainWindow *mainW;
    AchievementWindow *achievementW;
    CreateMissionWindow *createW;
    HistoryWindow *historyW;
    MissionListWindow *missionListW;
    RunWindow *runW;
    Settings *settingW;
    about *aboutW;
    OurTeam *teamW;

    QVector<Mission> missionList;
    QVector<History> historyList;
    QVector<Achievement> achieveList;

    int totalTomato;
    QTime totalTime;

private slots:
    void judgeAchieve();
    void updataMissionDatabase();
    void updataHistoryDatabase(History h);
};

#endif // TOMCLOCK_H
