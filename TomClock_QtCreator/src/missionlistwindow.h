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

signals:

private slots:
    void MaintoList();
    void on_remove_clicked();

private:
    Ui::MissionListWindow *ui;
};

#endif // MISSIONLISTWINDOW_H
