#include "tomclockdatabase.h"
#include <QSqlError>
#include <QStringList>
#include <QDebug>
#include <QString>

enum SqlError{
    SqlConnectionError,
    SqlCreateTableError,
    SqlCreateError,
    SqlDeleteError,
    SqlUpdateError,
    SqlQueryError
};

TomClockDatabase::TomClockDatabase()
{
    //连接数据库
    database = QSqlDatabase::addDatabase("QSQLITE", "tomclock_connect");
    database.setDatabaseName("TomClock.db");

    //尝试 打开数据库
    try{
        if (!database.open()) {
            throw SqlConnectionError;
        }
        else {
            qDebug("Successfully connect database.");
        }
    }
    catch(SqlError e){
        if (e == SqlConnectionError){
            qDebug("Failed to connect database.");
        }
    }

    //绑定query和数据库
    query = QSqlQuery(database);

    //若表不存在，则创建表
    if (!tablesExist()){
        createTables();
    }
    else {
        qDebug("Tables already exist.");
    }
}

bool TomClockDatabase::tablesExist()
{
    QStringList tableList = database.tables();
    if (tableList.contains("MissionTable") && \
        tableList.contains("HistoryTable") && \
        tableList.contains("AchievementTable"))
        return true;
    else return false;
}

void TomClockDatabase::createTables()
{
    sqlStr = QString("create table MissionTable(\
                        id int not null primary key,\
                        name text null,\
                        worktime time null,\
                        relaxtime time null,\
                        createtime date null);");
    //抛出异常
    try {
        if (!query.exec(sqlStr)){
            throw SqlCreateTableError;
        }
        else {
            qDebug("Successfully create MissionTable.");
        }
    } catch (SqlError e) {
        if (e == SqlCreateTableError){
            qDebug("Failed to create MissionTable.");
        }
    };
    sqlStr = QString("create table HistoryTable(\
                        id int not null primary key,\
                        date date null,\
                        name text null,\
                        numoftomato int null,\
                        totaltime time null);");
    //抛出异常
    try {
        if (!query.exec(sqlStr)){
            throw SqlCreateTableError;
        }
        else {
            qDebug("Successfully create HistoryTable.");
        }
    } catch (SqlError e) {
        if (e == SqlCreateTableError){
            qDebug("Failed to create HistoryTable.");
        }
    };
    sqlStr = QString("create table AchievementTable(\
                        name text not null primary key,\
                        state boolean null,\
                        howtoachieve text null);");
    //抛出异常
    try {
        if (!query.exec(sqlStr)){
            throw SqlCreateTableError;
        }
        else {
            qDebug("Successfully create AchievementTable.");
        }
    } catch (SqlError e) {
        if (e == SqlCreateTableError){
            qDebug("Failed to create AchievementTable.");
        }
    };
}

//Mission增删改查
void TomClockDatabase::createMission(const Mission &mission)
{
    sqlStr = QString("insert into MissionTable (id, name, worktime, relaxtime, createtime) \
                        values(:id, :name, :worktime, :relaxtime, :createtime);");
    query.prepare(sqlStr);
    query.bindValue(":id", mission.getId());
    query.bindValue(":name", mission.getName());
    query.bindValue(":worktime", mission.getWorkTime());
    query.bindValue(":relaxtime", mission.getRelaxTime());
    query.bindValue(":createtime", mission.getCreateTime());
    try{
        if (!query.exec()){
            throw SqlCreateError;
        }
        else {
            qDebug("Successfully create mission.");
        }
    }
    catch(SqlError e){
        if (e == SqlCreateError){
            qDebug("Failed to create mission.");
        }
    }
}

void TomClockDatabase::deleteMission(int id)
{
    //删除单个mission
    sqlStr = QString("delete from MissionTable where id = %1;").arg(id);
    try {
        if (!query.exec(sqlStr)){
            throw SqlDeleteError;
        }
        else {
            qDebug("Successfully delete mission.");
        }
    } catch (SqlError e) {
        if (e == SqlDeleteError){
            qDebug("Failed to delete mission.");
        }
    }
}

void TomClockDatabase::updateMission(int listSize, Mission *missionList)
{
    /*
     * 按照id从1到listSize,更新整个MissionTable
     * 先删除，再插入
    */
    sqlStr = QString("delete from MissionTable;");
    //尝试删除
    try {
        if (!query.exec(sqlStr)){
            throw SqlUpdateError;
        }
        else {
            qDebug("UpdataMission: Successfully delete MissionTable.");
        }
    } catch (SqlError e) {
        if (e == SqlUpdateError){
            qDebug("UpdataMission: Failed to delete MissionTable.");
        }
    };

    for (int i = 0; i < listSize; ++i) {
        sqlStr = QString("insert into MissioinTable (id, name, worktime, relaxtime, createtime) \
                            values(:id, :name, :worktime, :relaxtime, :createtime);");
        query.prepare(sqlStr);
        query.bindValue(":id", missionList[i].getId());
        query.bindValue(":name", missionList[i].getName());
        query.bindValue(":worktime", missionList[i].getWorkTime());
        query.bindValue(":relaxtime", missionList[i].getRelaxTime());
        query.bindValue(":createtime", missionList[i].getCreateTime());
        //尝试插入
        try {
            if (!query.exec()){
                throw SqlUpdateError;
            }
            else {
                qDebug("UpdataMission: Successfully update mission.");
            }
        } catch (SqlError e) {
            if (e == SqlUpdateError)
                qDebug("UpdataMission: Failed to insert into MissionTable.");
        }
    }
}

Mission *TomClockDatabase::queryMission()
{
    sqlStr = QString("select * from MissionTable;");
    //尝试query
    try {
        if (!query.exec(sqlStr)){
            throw SqlQueryError;
        }
        else {
            qDebug("Successfully query mission.");
        }
    } catch (SqlError e) {
        if (e == SqlQueryError){
            qDebug("Failed to query mission.");
        }
    }
    Mission *missionList = new Mission[query.size()]; //这里query.size()为-1，导致bad_alloc  可以使用QSqlQueryModel类
    for (int i = 0; query.next(); ++i) {
        missionList[i].setId(query.value("id").toInt());
        missionList[i].setName(query.value("name").toString());
        missionList[i].setWorkTime(query.value("worktime").toTime());
        missionList[i].setRelaxTime(query.value("relaxtime").toTime());
        missionList[i].setCreateTime(query.value("createtime").toDate());
    }
    query.clear();
    return missionList;
}

//History增加、查询
void TomClockDatabase::addHistory(const History &history)
{
    sqlStr = QString("insert into HistoryTable (id, date, name, numoftomato, totaltime) \
        values(:id, :date, :name, :numoftomato, :totaltime);");
    query.prepare(sqlStr);
    query.bindValue(":id", history.getId());
    query.bindValue(":date", history.getName());
    query.bindValue(":name", history.getName());
    query.bindValue(":numoftomato", history.getNumOfTomato());
    query.bindValue(":totaltime", history.getTotalTime());
    //尝试create
    try{
        if (!query.exec()){
            throw SqlCreateError;
        }
        else {
            qDebug("Successfully add history.");
        }
    }
    catch(SqlError e){
        if (e == SqlCreateError){
            qDebug("Failed to add history.");
        }
    }
}

History *TomClockDatabase::queryHistory()
{
    sqlStr = QString("select * from HistoryTable;");
    //尝试query
    try {
        if (!query.exec(sqlStr)){
            throw SqlQueryError;
        }
        else {
            qDebug("Successfully query history.");
        }
    } catch (SqlError e) {
        if (e == SqlQueryError){
            qDebug("Failed to query history.");
        }
    }
    History *historyList = new History[query.size()];
    for (int i = 1; query.next(); ++i) {
        historyList[i].setId(query.value("id").toInt());
        historyList[i].setDate(query.value("date").toDate());
        historyList[i].setName(query.value("name").toString());
        historyList[i].setNumOfTomato(query.value("numoftomato").toInt());
        historyList[i].setTotalTime(query.value("totaltime").toTime());
    }
    query.clear();
    return historyList;
}

void TomClockDatabase::initAchievement(int listSize, Achievement *achievementList)
{
    //判断是否为空
    //若无内容，则插入整个achievement数组
    sqlStr = QString("select * from AchievementTable;");
    //尝试query
    try {
        if (!query.exec(sqlStr)){
            throw SqlUpdateError;
        }
        else {
            qDebug("Initialize Achievement: Successfully query achievement.");
        }
    } catch (SqlError e) {
        if (e == SqlUpdateError){
            qDebug("Initialize Achievement: Failed to query achievement.");
        }
    }
    if (query.size() == 0){ //AchievementTable为空
        for (int i = 0; i < listSize; ++i) {
            sqlStr = QString("insert into AchievementTable (name, state, howtoachieve) \
                              values(:name, :state, :howtoachieve);");
            query.prepare(sqlStr);
            query.bindValue(":name", achievementList[i].getName());
            query.bindValue(":state", achievementList[i].getState());
            query.bindValue(":howtoachieve", achievementList[i].getHowToAchieve());
            //尝试insert
            try {
                if (!query.exec()){
                    throw SqlUpdateError;
                }
            } catch (SqlError e) {
                if (e == SqlUpdateError)
                    qDebug("Initialize Achievement: Failed to insert into AchievementTable.");
            }
        }
        qDebug("Successfully initialize achievement.");
    }
    else { //AchievementTable不为空
        return;
    }
}

//Achievements更新、查询
void TomClockDatabase::updateAchievement(const QString &name)
{
    /*
     * 不删除整个表，仅修改name对应的行
    */
    sqlStr = QString("update AchievementTable set state = true where name = %1;").arg(name);
    //尝试update
    try {
        if (!query.exec(sqlStr)){
            throw SqlUpdateError;
        }
        else {
            qDebug("UpdateAchievement: Successfully update achievement.");
        }
    } catch (SqlError e) {
        if (e == SqlUpdateError){
            qDebug("UpdateAchievement: Failed to update achievement.");
        }
    }
}

Achievement * TomClockDatabase::queryAchievement()
{
    sqlStr = QString("select * from AchievementTable;");
    //尝试query
    try {
        if (!query.exec(sqlStr)){
            throw SqlQueryError;
        }
        else {
            qDebug("Successfully query achievement.");
        }
    } catch (SqlError e) {
        if (e == SqlQueryError){
            qDebug("Failed to query achievement.");
        }
    }
    Achievement *achievementList = new Achievement[query.size()];
    for (int i = 0; query.next(); ++i) {
        achievementList[i].setName(query.value("name").toString());
        achievementList[i].setState(query.value("state").toBool());
        achievementList[i].setHowToAchieve(query.value("howtoachieve").toString());
    }
    query.clear();
    return achievementList;
}
