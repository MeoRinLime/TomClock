#ifndef CREATEMISSIONWINDOW_H
#define CREATEMISSIONWINDOW_H

#include <QWidget>
#include"mission.h"
namespace Ui {
class CreateMissionWindow;
}

class CreateMissionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateMissionWindow(QWidget *parent = nullptr);
    ~CreateMissionWindow();
    void changeEvent(QEvent *event);

signals:
    void sentAndJump(Mission mission);//发送创建任务的信号和任务信息

private:
    Ui::CreateMissionWindow *ui;
    Mission mi;//创建的任务

private slots:
    void toCreate();//从其他界面来到创建任务界面
    void on_cancel_clicked();//取消创建新任务
    void on_comfirm_clicked();//确定创建新任务
};

#endif // CREATEMISSIONWINDOW_H
