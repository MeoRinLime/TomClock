#include "createmissionwindow.h"
#include "ui_createmissionwindow.h"

CreateMissionWindow::CreateMissionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateMissionWindow)
{
    ui->setupUi(this);
}

CreateMissionWindow::~CreateMissionWindow()
{
    delete ui;
}

void CreateMissionWindow::MaintoCreate()
{
    this->show();
}
