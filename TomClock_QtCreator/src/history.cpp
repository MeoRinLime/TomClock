#include "history.h"

History::History()
{

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
