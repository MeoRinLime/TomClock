#ifndef MISSIONLISTWINDOW_H
#define MISSIONLISTWINDOW_H

#include <QWidget>
#include<QGridLayout>
#include<QVector>
#include<QMessageBox>

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

private slots:
    void MaintoList();
    void disapearChoice();

private:
    Ui::MissionListWindow *ui;
    QVector<Mission>missions;

    QVector<MissionPushButton*>MPBTS;
    int choice;
};


#endif // MISSIONLISTWINDOW_H
