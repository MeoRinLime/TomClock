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

private:
    Ui::CreateMissionWindow *ui;

private slots:
    void MaintoCreate();
    void on_cancel_clicked();
    void on_comfirm_clicked();
};

#endif // CREATEMISSIONWINDOW_H
