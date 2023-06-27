#ifndef MYPUSHBUTTOM_H
#define MYPUSHBUTTOM_H
#include<QPushButton>

class MyPushButtom:QPushButton
{
public:
    MyPushButtom();
   void setNum(int n);
    static int getAllnum();
   QPushButton* getQPb();
private:
   static int allNum;
    QPushButton* qPb;
     int num;
private slots:
   void setAllNum();
    friend class MissionListWindow;
};

#endif // MYPUSHBUTTOM_H
