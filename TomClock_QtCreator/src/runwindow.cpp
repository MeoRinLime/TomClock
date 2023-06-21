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
