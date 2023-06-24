#ifndef CREATEMISSIONWINDOW_H
#define CREATEMISSIONWINDOW_H

#include <QWidget>
#include"mainwindow.h"
#include"mission.h"
#include<QTime>
namespace Ui {
class CreateMissionWindow;
}

class CreateMissionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateMissionWindow(MainWindow *M,QWidget *parent = nullptr);
    ~CreateMissionWindow();

private slots:
    void on_comfirm_clicked();//点击添加列表按钮的槽

    void on_cancel_clicked();//点击取消按钮的槽

private:
    Ui::CreateMissionWindow *ui;
    MainWindow *m;
};

#endif // CREATEMISSIONWINDOW_H
