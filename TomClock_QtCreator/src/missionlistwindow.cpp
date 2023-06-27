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

void MissionListWindow::MaintoList()
{
    this->show();
}

void MissionListWindow::on_remove_clicked()
{
    //行列自动填充
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //灰色背景
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setStyleSheet("background-color:grey;");
    QTableWidget * table = new QTableWidget(this);
    table->setStyleSheet("QTableWidget{border-top:1px solid blue;"
    "border-left:1px solid black;"
    "border-right:1px solid black;"
    "border-bottom:1px dashed black;}");

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    int rowIndex = ui->tableWidget->currentRow();
    if (rowIndex!=-1)
    {
       ui->tableWidget->removeRow(rowIndex);
    }
}

