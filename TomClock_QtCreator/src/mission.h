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
    int id;           //每个mission的唯一标记 从1开始++
    QString name;     //任务名 varchar(20)
    QTime workTime;
    QTime relaxTime;
    QDate createTime; //创建日期
};

#endif // MISSION_H
