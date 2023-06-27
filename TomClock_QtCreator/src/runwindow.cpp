#include "runwindow.h"
#include "ui_runwindow.h"

RunWindow::RunWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunWindow)
{
    ui->setupUi(this);
}

RunWindow::~RunWindow()
{
    delete ui;
}
void RunWindow::beginRun(Mission mission){
    this->show();
    qDebug()<<mission.getName()<<"  "<<mission.getWorkTime().toString()<<"  "<<mission.getRelaxTime().toString();
}
