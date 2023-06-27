#include "tomclockdatabase.h"
#include <QSqlError>
#include <QStringList>
#include <QDebug>
#include <QString>

TomClockDatabase::TomClockDatabase(const QString &path)
{
    //打开数据库
    database = QSqlDatabase::addDatabase("QSQLITE", path + "/tomclock.db");
    database.setDatabaseName("TomClock.db");

    //异常处理
    try{
        if (!database.open()) {
            throw QSqlError::ConnectionError;
        }
        else{
            qDebug("Successfully opened database");
        }
    }
    catch(QSqlError){
        qDebug("connection error, open database failed");
    }

    //绑定query和数据库
    query = QSqlQuery(database);
}

bool TomClockDatabase::tablesExist()
{
    QStringList tableList = database.tables();
    if (tableList.contains("MissionTable") && \
        tableList.contains("HistoryTable") && \
        tableList.contains("AchievementsTable"))
        return true;
    else return false;
}

void TomClockDatabase::createTables()
{
    sqlStr = QString("create table MissionTable(\
                        mid int not null primary key,\
                        mname varchar(20) null,\
                        worktime time )");
}

//Mission增删改查
void TomClockDatabase::createMission(const Mission &mission)
{
    sqlStr = QString(
        "insert into MissionTable (id, name, worktime, relaxtime, createtime) \
        values(:id, :name, :worktime, :relaxtime, :createtime)");
    query.prepare(sqlStr);
    query.bindValue(":id", mission.getId());
    query.bindValue(":name", mission.getName());
    query.bindValue(":worktime", mission.getWorkTime());
    query.bindValue(":relaxtime", mission.getRelaxTime());
    query.bindValue(":createtime", mission.getCreateTime());
    try{
        if (!query.exec()){
            throw QSqlError::TransactionError;
        }
        else{
            qDebug("Successfully created mission");
        }
    }
    catch(QSqlError){
        qDebug("create mission failed");
    }
}

void TomClockDatabase::deleteMission(int id)
{

}

void TomClockDatabase::updateMission(Mission *missionList)
{

}

Mission *TomClockDatabase::queryMission()
{
return nullptr;
}

//History增加、查询
void TomClockDatabase::addHistory(const History &history)
{

}

History *TomClockDatabase::queryHistory()
{
return nullptr;
}

//Achievements更新、查询
void TomClockDatabase::updateAchievements(Achievement *achievements)
{

}

Achievement * TomClockDatabase::queryAchievementes()
{
return nullptr;
}
