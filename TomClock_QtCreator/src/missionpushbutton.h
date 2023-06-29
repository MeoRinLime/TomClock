#ifndef MISSIONPUSHBUTTON_H
#define MISSIONPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include "mission.h"
namespace Ui
{
    class MissionPushButton;
}

class MissionPushButton : public QWidget
{
    Q_OBJECT

public:
    explicit MissionPushButton(QWidget *parent = nullptr);
    ~MissionPushButton();
    void setNum(int n);//设置该任务的数字编号
    static int getallNum();//获取选中的任务编号
    QHBoxLayout *getHBlt();//获取水平布局
    QPushButton *getPBtn();//获取任务按键
    void disapearChoice();//隐藏选项
    static void setAN(int n);//设置选中的任务编号

private:
    Ui::MissionPushButton *ui;
    int num;

    static int allNum;//选中的任务编号
    QPushButton *pBtn;//任务按钮
    QPushButton *mBegin;//开始按钮
    QPushButton *mChange;//修改按钮
    QPushButton *mDelete;//删除按钮
    QHBoxLayout *hBlt;//水平布局
    QPushButton *mChangeConfirm;//确认修改按钮
    QPushButton *mChangeCancel;//取消修改按钮
    QComboBox *workTime;//工作时间
    QComboBox *relaxTime;//休息时间
    QLineEdit *mName;//任务名
    QLabel name;
    QLabel wT;
    QLabel rT;
signals:
    void deleteMission();//删除任务信号
    void beginMission();//开始任务信号
    void sentChange(Mission mi);//修改任务信号
private slots:
    void setAllNum();//设置成所点击的任务的编号
    void change_clicked();//点击修改按钮
    void sentDelete();//发送删除信号
    void sentBegin();//发送开始信号
    void cancelChange();//取消修改
    void confirmChange();//确定修改
};

#endif // MISSIONPUSHBUTTON_H
