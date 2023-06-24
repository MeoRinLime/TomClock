#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <QDate>
#include <QTime>

class History
{
public:
    History();
    QDate getDate() const;//获取日期

    void setDate(const QDate &newDate);//设置日期

    QString getName() const;//获取姓名

    void setName(const QString &newName);//设置姓名

    int getNumOfTomato() const;//获取番茄数

    void setNumOfTomato(int newNumOfTomato);//设置番茄数

    QTime getTotalTime() const;//获取总时长

    void setTotalTime(const QTime &newTotalTime);//设置总时长

private:
    QDate date;
    QString name;
    int numOfTomato;
    QTime totalTime;
};

#endif // HISTORY_H
