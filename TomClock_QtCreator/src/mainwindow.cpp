#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/resourse/images/Icons/Main_Color/tomato1.png");
    ui->start->setMask(pix.mask());
}

MainWindow::~MainWindow()
{
    delete ui;
}

