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
    explicit AchievementWindow(/*const QVector<Achievement> &achievementList, */QWidget *parent = nullptr);
//    AchievementWindow(QWidget *parent = nullptr);
    ~AchievementWindow();
    void changeTomatoNum(int tomatoNum);                                //改变番茄数
    void updateAchievementState(int indexOfAchievement, bool newState); //更新成就的状态
    void changeEvent(QEvent *event);
signals:
    void JumptoMain();

private:
    Ui::AchievementWindow *ui;
    //成就图片的路径，目前仅为示例
    QList<QString> imagePathList = {"resourse/images/achievement/a_tomato.png", \
                                    "resourse/images/achievement/b_tomato.png", \
                                    "resourse/images/achievement/c_tomato.png", \
                                    "resourse/images/achievement/small.png", \
                                    "resourse/images/achievement/big.png", \
                                    "resourse/images/achievement/pause.png", \
                                    "resourse/images/achievement/stop.png", \
                                    "resourse/images/achievement/rest1.png", \
                                    "resourse/images/achievement/rest2.png", \
                                    "resourse/images/achievement/rest3.png"};

    //实现自适应窗口大小
    QList<QWidget*> allChildWidgets;       //储存所有子控件
    QMap<QWidget*, QRect> allWidgetRect;   //保存所有子控件的初始大小

    void resizeEvent(QResizeEvent *event); //重写resizeEvent
    void closeEvent(QCloseEvent *event);

private slots:
    void MaintoAchievement(QVector<Achievement> achieveList);
    void on_backBtn_clicked();
};

#endif // ACHIEVEMENTWINDOW_H
