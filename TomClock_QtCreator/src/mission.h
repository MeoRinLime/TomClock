#ifndef MISSION_H
#define MISSION_H

#include <QString>
#include <QTime>
#include <QDate>

class Mission
{
public:
    Mission();
    Mission(int id, const QString &name, const QTime &wtime, const QTime &rtime, const QDate &ctime);
    int getId() const;
    void setId(int newId);
    QString getName() const;
    void setName(const QString &newName);
    QTime getWorkTime() const;
    void setWorkTime(const QTime &newWorkTime);
    QTime getRelaxTime() const;
    void setRelaxTime(const QTime &newRelaxTime);
    QDate getCreateTime() const;
    void setCreateTime(const QDate &newCreateTime);

private:
    int id;
    QString name;
    QTime workTime;
    QTime relaxTime;
    QDate createTime;
};

#endif // MISSION_H
