#ifndef ACHIEVEMENTWINDOW_H
#define ACHIEVEMENTWINDOW_H

#include "achievement.h"
#include <QMainWindow>

namespace Ui {
class AchievementWindow;
}

class AchievementWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AchievementWindow(const QVector<Achievement> &achievementList, QWidget *parent = nullptr);
    AchievementWindow(QWidget *parent = nullptr);
    ~AchievementWindow();
    void changeTomatoNum(int tomatoNum);                                //改变番茄数
    void updateAchievementState(int indexOfAchievement, bool newState); //更新成就的状态

signals:
    void JumptoMain();

private:
    Ui::AchievementWindow *ui;
    //实现自适应窗口大小
    QList<QWidget*> allChildWidgets;       //储存所有子控件
    QMap<QWidget*, QRect> allWidgetRect;   //保存所有子控件的初始大小
    void resizeEvent(QResizeEvent *event); //重写resizeEvent
    void closeEvent(QCloseEvent *event);

private slots:
    void MaintoAchievement();
};

#endif // ACHIEVEMENTWINDOW_H
