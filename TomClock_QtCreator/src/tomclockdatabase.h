#ifndef TOMCLOCKDATABASE_H
#define TOMCLOCKDATABASE_H

#include "mission.h"
#include "history.h"
#include "achievement.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>

class TomClockDatabase
{
public:
    TomClockDatabase(const QString &path);

    bool tablesExist();      //判断表是否存在
    void createTables();     //创建表

    //任务列表的增删改查
    void createMission(const Mission &mission);
    void deleteMission(int id);
    void updateMission(Mission *missionList);
    Mission * queryMission();

    //历史记录的增加和查询
    void addHistory(const History &history);
    History * queryHistory();

    //成就的更新和查询
    void updateAchievements(Achievement[]);
    Achievement * queryAchievementes();

private:
    QSqlDatabase database;   //被封装了一层
    QSqlQuery query;         //用于操作数据库
    QString sqlStr;          //用于存放具体的sql语句
};

#endif // TOMCLOCKDATABASE_H
