#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QWidget>
#include"mission.h"
namespace Ui {
class RunWindow;
}

class RunWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RunWindow(QWidget *parent = nullptr);
    ~RunWindow();
private slots:
    void beginRun(Mission mission);
private:
    Ui::RunWindow *ui;

};

#endif // RUNWINDOW_H
