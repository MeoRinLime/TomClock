#ifndef CREATEMISSIONWINDOW_H
#define CREATEMISSIONWINDOW_H

#include <QWidget>

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
};

#endif // CREATEMISSIONWINDOW_H
