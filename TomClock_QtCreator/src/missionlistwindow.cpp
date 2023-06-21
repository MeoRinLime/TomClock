#include "missionlistwindow.h"
#include "ui_missionlistwindow.h"

MissionListWindow::MissionListWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MissionListWindow)
{
    ui->setupUi(this);
}

MissionListWindow::~MissionListWindow()
{
    delete ui;
}
