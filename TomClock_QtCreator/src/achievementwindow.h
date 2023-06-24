#ifndef ACHIEVEMENTWINDOW_H
#define ACHIEVEMENTWINDOW_H

#include "achievement.h"
#include <QWidget>

namespace Ui {
class AchievementWindow;
}

class AchievementWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AchievementWindow(int achievementNum, Achievement *AchievementList, QWidget *parent = nullptr);
    ~AchievementWindow();

private:
    Ui::AchievementWindow *ui;
};

#endif // ACHIEVEMENTWINDOW_H
