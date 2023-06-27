#include "history.h"

History::History()
{
    setId(-1);
    setDate(QDate());
    setName("");
    setNumOfTomato(-1);
    setTotalTime(QTime());
}

History::History(int id, const QDate &date, const QString &name, int numOfTomato, const QTime &totaltime)
{
    setId(id);
    setDate(date);
    setName(name);
    setNumOfTomato(numOfTomato);
    setTotalTime(totaltime);
}

QDate History::getDate() const
{
    return date;
}

void History::setDate(const QDate &newDate)
{
    date = newDate;
}

QString History::getName() const
{
    return name;
}

void History::setName(const QString &newName)
{
    name = newName;
}

int History::getNumOfTomato() const
{
    return numOfTomato;
}

void History::setNumOfTomato(int newNumOfTomato)
{
    numOfTomato = newNumOfTomato;
}

QTime History::getTotalTime() const
{
    return totalTime;
}

void History::setTotalTime(const QTime &newTotalTime)
{
    totalTime = newTotalTime;
}

int History::getId() const
{
    return id;
}

void History::setId(int newId)
{
    id = newId;
}
