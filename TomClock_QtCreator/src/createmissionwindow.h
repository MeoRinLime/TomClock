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
signals:
    void sentAndJump(Mission mission);
private:
    Ui::CreateMissionWindow *ui;
    Mission mi;
    int countID = 0;
private slots:
    void toCreate();
    void on_cancel_clicked();
    void on_comfirm_clicked();
};

#endif // CREATEMISSIONWINDOW_H
