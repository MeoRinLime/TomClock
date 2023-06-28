#ifndef MISSIONLISTWINDOW_H
#define MISSIONLISTWINDOW_H

#include <QWidget>
#include<QGridLayout>
#include<QVector>
#include<QMessageBox>
#include "mission.h"
#include"missionpushbutton.h"
namespace Ui {
class MissionListWindow;
}

class MissionListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MissionListWindow(QWidget *parent = nullptr);
    ~MissionListWindow();

signals:
    void jumpToRunWindows(Mission mission);
    void create();
    void BacktoMain();

private slots:
    void MaintoList();
    void disapearChoice();
    void deleteMission();
    void beginMission();
    void recieveMission(Mission mission);
    void on_backtoMain_clicked();
    void on_create_clicked();
    void changeMission(Mission mi);
private:
    Ui::MissionListWindow *ui;
    QVector<Mission>missions;
    QGridLayout* gL;
    QVector<MissionPushButton*>MPBTS;
    int choice;

};


#endif // MISSIONLISTWINDOW_H
