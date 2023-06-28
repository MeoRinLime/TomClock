#include "tomclockdatabase.h"
#include <QSqlError>
#include <QStringList>
#include <QDebug>
#include <QString>
#include <QVector>

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
            qDebug("Create Tables: Successfully create MissionTable.");
        }
    } catch (SqlError e) {
        if (e == SqlCreateTableError){
            qDebug("Create Tables: Failed to create MissionTable.");
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
            qDebug("Create Tables: Successfully create HistoryTable.");
        }
    } catch (SqlError e) {
        if (e == SqlCreateTableError){
            qDebug("Create Tables: Failed to create HistoryTable.");
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
            qDebug("Create Tables: Successfully create AchievementTable.");
        }
    } catch (SqlError e) {
        if (e == SqlCreateTableError){
            qDebug("Create Tables: Failed to create AchievementTable.");
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

void TomClockDatabase::updateMission(QVector<Mission> missionList)
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

    for (int i = 0; i < missionList.size(); ++i) {
        sqlStr = QString("insert into MissioinTable (id, name, worktime, relaxtime, createtime) \
                            values(:id, :name, :worktime, :relaxtime, :createtime);");
        query.prepare(sqlStr);
        query.bindValue(":id", missionList[i].getId());
        query.bindValue(":name", missionList[i].getName());
        query.bindValue(":worktime", missionList[i].getWorkTime().toString());
        query.bindValue(":relaxtime", missionList[i].getRelaxTime().toString());
        query.bindValue(":createtime", missionList[i].getCreateTime().toString());
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

QVector<Mission> TomClockDatabase::queryMission()
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
    QVector<Mission> missionList;
//    Mission *missionList = new Mission[query.size()]; //这里query.size()为-1，导致bad_alloc  可以使用QSqlQueryModel类
    for (/*int i = 0*/; query.next(); /*++i*/) {
        Mission tmpMission;
        tmpMission.setId(query.value("id").toInt());
        tmpMission.setName(query.value("name").toString());
        tmpMission.setWorkTime(QTime().fromString(query.value("worktime").toString()));
        tmpMission.setRelaxTime(QTime().fromString(query.value("relaxtime").toString()));
        tmpMission.setCreateTime(query.value("createtime").toDate());
        missionList.append(tmpMission);
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
    query.bindValue(":date", history.getDate().toString());
    query.bindValue(":name", history.getName());
    query.bindValue(":numoftomato", history.getNumOfTomato());
    query.bindValue(":totaltime", history.getTotalTime().toString());
    //尝试add
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

QVector<History> TomClockDatabase::queryHistory()
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
//    History *historyList = new History[query.size()];
    QVector<History> historyList;
    for (/*int i = 1*/; query.next(); /*++i*/) {
        History tmpHistory;
        tmpHistory.setId(query.value("id").toInt());
        tmpHistory.setDate(query.value("date").toDate());
        tmpHistory.setName(query.value("name").toString());
        tmpHistory.setNumOfTomato(query.value("numoftomato").toInt());
        tmpHistory.setTotalTime(QTime().fromString(query.value("totaltime").toString()));
        historyList.append(tmpHistory);
    }
    query.clear();
    return historyList;
}

void TomClockDatabase::initAchievement(QVector<Achievement> achievementList)
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
    QVector<Achievement> tmpAchievementList;
    while (query.next()) {
        Achievement tmpAchievement;
        tmpAchievementList.append(tmpAchievement);
    }
    if (tmpAchievementList.size() == 0){ //AchievementTable为空
        for (int i = 0; i < achievementList.size(); ++i) {
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
        qDebug("Initialize Achievement: Successfully initialize achievement.");
    }
    else { //AchievementTable不为空
        qDebug("Initialize Achievement: Achievement is not null, not need to init.");
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

QVector<Achievement> TomClockDatabase::queryAchievement()
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
//    Achievement *achievementList = new Achievement[query.size()];
    QVector<Achievement> achievementList;
    for (/*int i = 0*/; query.next(); /*++i*/) {
        Achievement tmpAchievement;
        tmpAchievement.setName(query.value("name").toString());
        tmpAchievement.setState(query.value("state").toBool());
        tmpAchievement.setHowToAchieve(query.value("howtoachieve").toString());
    }
    query.clear();
    return achievementList;
}
