#ifndef MISSION_H
#define MISSION_H
#include<QString>
#include<QTime>
#include<QDate>
class Mission
{
private:
    int id;
    QString name;
    QTime workTime;
    QTime relaxTime;
    QDate createTime;


public:
    Mission();
    int getId();//获取id

    QString getName();//获取任务名

    QTime getWorkTime();//获取工作时间

    QTime getRelaxTime();//获取休息时间

    QDate getCreateTime();//获取创建时间

    void setId(int ID);//编写ID

    void setName(QString Name);//编写任务名

    void setWorkTime(QTime WorkTime);//编写工作时间

    void setRelaxTime(QTime RelaxTime);//编写休息时间

    void setCreateTime(QDate CreateTime);//编写创建任务日期

};

#endif // MISSION_H
