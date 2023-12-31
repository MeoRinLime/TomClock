#ifndef TOMCLOCKDATABASE_H
#define TOMCLOCKDATABASE_H

#include "mission.h"
#include "history.h"
#include "achievement.h"
#include <QtSql/QSqlQuery>

/*
 * 用于处理数据库，对象构造时会确保表的存在
 * 程序的其他模块应当有临时数据的存放，不应当直接将数据库数据用于显示
 * 例如 用一个数组存放所有mission，这个数组用于显示
 * createMission 接收一个Mission对象，添加单个mission
 * deleteMission 根据id删除单个mission
 * updateMission 删除整个表，然后插入数组的所有mission
 * queryMission  返回一个堆上的mission数组
*/

class TomClockDatabase : public QObject
{
    Q_OBJECT
public:
    TomClockDatabase();

public slots:
    //任务列表的增删改查
    void createMission(const Mission &mission);
    void deleteMission(int id);
    void updateMission(const QVector<Mission> &missionList);
    void queryMission(QVector<Mission> &missioinList);

    //历史记录的增加,查询,删除
    void addHistory(const History &history);
    void queryHistory(QVector<History> &historyList);
    void deleteAllHistory();

    //成就的更新和查询
    void initAchievement(/*const QVector<Achievement> &achievementList*/);
    void updateAchievement(const Achievement &achievement); //仅修改name对应的state，由0变1
    void queryAchievement(QVector<Achievement> &achievementList);

private:
    bool tablesExist();      //判断表是否存在
    void createTables();     //创建表

    QSqlDatabase database;   //被封装了一层
    QSqlQuery query;         //用于操作数据库
    QString sqlStr;          //用于存放具体的sql语句
    QVector<Achievement> achievementList;//用于init AchievementTable
};

#endif // TOMCLOCKDATABASE_H
