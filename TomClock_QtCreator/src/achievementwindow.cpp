#include "achievementwindow.h"
#include "ui_achievementwindow.h"

AchievementWindow::AchievementWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AchievementWindow)
{
    ui->setupUi(this);
}

AchievementWindow::~AchievementWindow()
{
    delete ui;
}
