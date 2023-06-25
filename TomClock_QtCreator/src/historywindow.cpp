#include "historywindow.h"
#include "ui_historywindow.h"

HistoryWindow::HistoryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void HistoryWindow::MaintoHistory()
{
    this->show();
}
