#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <QDate>
#include <QTime>

class History
{
public:
    History();
    QDate getDate() const;
    void setDate(const QDate &newDate);
    QString getName() const;
    void setName(const QString &newName);
    int getNumOfTomato() const;
    void setNumOfTomato(int newNumOfTomato);
    QTime getTotalTime() const;
    void setTotalTime(const QTime &newTotalTime);

private:
    QDate date;
    QString name;
    int numOfTomato;
    QTime totalTime;
};

#endif // HISTORY_H
