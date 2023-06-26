#include "mission.h"

Mission::Mission()
{
    setId(0);
    setName("");
    setWorkTime(QTime());
    setRelaxTime(QTime());
    setCreateTime(QDate());
}

Mission::Mission(int id, const QString &name, const QTime &wtime, const QTime &rtime, const QDate &ctime)
{
    setId(id);
    setName(name);
    setWorkTime(wtime);
    setRelaxTime(rtime);
    setCreateTime(ctime);
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
