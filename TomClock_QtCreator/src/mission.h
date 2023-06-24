#ifndef MISSION_H
#define MISSION_H

#include <QString>
#include <QTime>
#include <QDate>

class Mission
{
public:
    Mission();
    int getId() const;//获取id

    void setId(int newId);//设置id

    QString getName() const;//获取任务名

    void setName(const QString &newName);//编写任务名

    QTime getWorkTime() const;//获取工作时长

    void setWorkTime(const QTime &newWorkTime);//设置工作时长

    QTime getRelaxTime() const;//获取休息时长

    void setRelaxTime(const QTime &newRelaxTime);//设置休息时长

    QDate getCreateTime() const;//获取创建日期

    void setCreateTime(const QDate &newCreateTime);//设置创建日期

private:
    int id;
    QString name;
    QTime workTime;
    QTime relaxTime;
    QDate createTime;
};

#endif // MISSION_H
