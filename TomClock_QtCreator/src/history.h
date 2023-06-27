#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <QDate>
#include <QTime>

class History
{
public:
    History();
    History(int id, const QDate &date, const QString &name, int numOfTomato, const QTime &totaltime);
    QDate getDate() const;
    void setDate(const QDate &newDate);
    QString getName() const;
    void setName(const QString &newName);
    int getNumOfTomato() const;
    void setNumOfTomato(int newNumOfTomato);
    QTime getTotalTime() const;
    void setTotalTime(const QTime &newTotalTime);

    int getId() const;
    void setId(int newId);

private:
    int id;
    QDate date;
    QString name;
    int numOfTomato;
    QTime totalTime;
};

#endif // HISTORY_H
