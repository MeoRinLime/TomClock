#include "runwindow.h"
#include "ui_runwindow.h"

RunWindow::RunWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("RunWindow {border-image:url(:/images/resourse/images/background/bg3.png);}");
}

RunWindow::~RunWindow()
{
    delete ui;
}
