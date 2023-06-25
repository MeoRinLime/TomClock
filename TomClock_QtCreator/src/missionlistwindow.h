#ifndef MISSIONLISTWINDOW_H
#define MISSIONLISTWINDOW_H

#include <QWidget>

namespace Ui {
class MissionListWindow;
}

class MissionListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MissionListWindow(QWidget *parent = nullptr);
    ~MissionListWindow();

private:
    Ui::MissionListWindow *ui;

private slots:
    void MaintoList();
};

#endif // MISSIONLISTWINDOW_H
