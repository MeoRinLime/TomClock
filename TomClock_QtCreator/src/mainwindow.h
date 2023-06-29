#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "achievement.h"
#include "history.h"
#include <QMainWindow>
#include <QFrame>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QVector<History> &historyList, QWidget *parent = nullptr);
    ~MainWindow();

    void setRatio(int width, int height);
    QWidget* widget;



signals:
    void JumptoAchievement(/*const QVector<Achievement> &newAchieveList*/);//跳转至成就界面
    void JumptoHistory(QVector<History> historyList);//跳转至历史记录界面
    //void JumptoMissionCreate();//跳转至创建任务界面
    void JumptoMissionList();//点击开始或者图标后跳转至任务列表界面
    void JumptoSettings();//跳转至设置界面
    void JumptoAbout();//跳转至关于界面

private:
    Ui::MainWindow *ui;
    int width_ratio;
    int height_ratio;
    QWidget* center_widget;
    QVector<History> *historyListPtr;

private slots:
    void on_historyData_clicked();
    void on_personalAchievement_clicked();
    void on_missionList_clicked();
    void on_startIcon_clicked();
    void on_startText_clicked();
    void on_settings_clicked();
    void on_aboutTeam_clicked();

    void SettingstoMain();
    void HistorytoMain();
    void RuntoMain();
    void AchievetoMain();
    void AbouttoMain();
    void ListtoMain();
    void OthertoMain();
};
#endif // MAINWINDOW_H
