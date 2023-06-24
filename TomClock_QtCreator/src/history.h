#ifndef HISTORY_H
#define HISTORY_H
#include<QString>
#include<QDate>
class History
{
private:
    QDate date;
    QString name;
    int numOfTomato;
    QTime totalTime;
public:
    History();
    void setDate(QDate Date);//设置日期
    void setName(QString name);//编写任务名
    void setNumOfTomato(int n);//记录番茄数
    void setTotalTime(QTime t);//记录总时长
    QDate getDate();//获取日期
    QString getName();//获取任务名
    int getNumOfTomato();//获取番茄数
    QTime getTotalTime();//获取总时长
};

#endif // HISTORY_H
