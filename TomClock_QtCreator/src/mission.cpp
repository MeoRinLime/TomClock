#include "mission.h"

Mission::Mission()
{


}
int Mission::getId(){
    return id;
}
QString Mission::getName(){
    return name;
}

QTime Mission::getWorkTime(){
    return workTime;
}

QTime Mission::getRelaxTime(){
    return relaxTime;
}

QDate Mission::getCreateTime(){
    return createTime;
}

void Mission::setId(int ID){
    id=ID;
}

void Mission::setName(QString Name){
    name=Name;
}

void Mission::setWorkTime(QTime WorkTime){
    workTime=WorkTime;
}

void Mission::setRelaxTime(QTime RelaxTime){
    relaxTime=RelaxTime;
}

void Mission::setCreateTime(QDate CreateTime){
    createTime=CreateTime;
}
