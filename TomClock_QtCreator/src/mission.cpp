#include "mission.h"

Mission::Mission()
{

}

int Mission::getId() const
{
    return id;
}

void Mission::setId(int newId)
{
    id = newId;
}

QString Mission::getName() const
{
    return name;
}

void Mission::setName(const QString &newName)
{
    name = newName;
}

QTime Mission::getWorkTime() const
{
    return workTime;
}

void Mission::setWorkTime(const QTime &newWorkTime)
{
    workTime = newWorkTime;
}

QTime Mission::getRelaxTime() const
{
    return relaxTime;
}

void Mission::setRelaxTime(const QTime &newRelaxTime)
{
    relaxTime = newRelaxTime;
}

QDate Mission::getCreateTime() const
{
    return createTime;
}

void Mission::setCreateTime(const QDate &newCreateTime)
{
    createTime = newCreateTime;
}
