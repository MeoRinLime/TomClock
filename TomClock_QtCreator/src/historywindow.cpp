#include "historywindow.h"
#include "ui_historywindow.h"

HistoryWindow::HistoryWindow( QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryWindow)
{
    ui->setupUi(this);
    ui->scrollArea->viewport()->setStyleSheet(".QWidget{background-color:transparent;}");
    pLayout = new QGridLayout();//网格布局

   this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");

}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void HistoryWindow::MaintoHistory(QVector<History> histories)
{
    this->histories = histories;
    delete pLayout;
    pLayout = new QGridLayout();//网格布局
    for(int i = 0; i < histories.size(); i++)
    {
        QPushButton *pBtn = new QPushButton();
        pBtn->setText(historyRecord(histories[i]));
        pBtn->setStyleSheet(
            "QPushButton{"                             // 正常状态样式
            "background-color: transparent;"       // 背景色（也可以设置图片）
            "color: white;"                            // 字体颜色
            "font: bold 13px;"                         // 字体: 加粗 大小
            "border-radius: 5px;"                      // 边框圆角半径像素
            "border: 2px solid rgb(50, 50, 50);"       // 边框样式：border-width border-style border-color
            "border-style:outset;"                     // 定义一个3D突出边框，inset与之相反
            "text-align: center;"                        // 文本：左对齐
            "}"

            "QPushButton:focus{"                       // 聚焦样式
            "background-color:rgb(255, 128, 64);"
            "color: white;"
            "border-radius: 5px;"
            "border: 2px solid white;"
            "border-style:outset;"
            "font:bold 13px;"
            "text-align: center;"
            "}");
        pBtn->setMinimumSize(QSize(750,40));   //width height
        pBtn->setMaximumSize(QSize(750,50));

        pLayout->addWidget(pBtn);//把按钮添加到布局控件中
        pLayout->setRowStretch(i+1,1);
    }
    ui->numOfTotal->setText(QString::number(histories.size()));//把任务记录数显示出来
    ui->totalTime->setText(caculateTotalTime());//显示总时长
    ui->totalTomato->setText(QString::number(caculateTotalTomato()));
     ui->scrollAreaWidgetContents->setFixedHeight(52*histories.size());
    ui->scrollArea->widget()->setLayout(pLayout);//把布局放置到QScrollArea的内部QWidget中
    this->show();
}

QString HistoryWindow::caculateTotalTime(){
    //计算总时长
    int h=0 ;
    int m=0;
    int s=0;
    for(int i = 0; i < histories.size(); i++){
        h += histories[i].getTotalTime().hour();
        m += histories[i].getTotalTime().minute();
        s += histories[i].getTotalTime().second();
    }
    m+=s/60;
    s=s%60;
    h+=m/60;
    m=m%60;

    QString t=QString::number(h)+"小时"+QString::number(m)+"分钟"+QString::number(s)+"秒";
    return t;
}

QString HistoryWindow::historyRecord(History h){
    QString hi=h.getDate().toString("dd.MM.yyyy")+"              "+h.getName()+"                  番茄数："+QString::number(h.getNumOfTomato())
+"        学习时长"+h.getTotalTime().toString();
    return hi;
}

void HistoryWindow::on_backToMain_clicked()
{
    this->hide();
    emit BacktoMain();
}

int HistoryWindow::caculateTotalTomato(){
    int total=0;
    for(int i=0;i<histories.size();i++){
        total=total+histories[i].getNumOfTomato();
    }
    return total;
}

void HistoryWindow::closeEvent(QCloseEvent *event)
{
    emit BacktoMain();
    QWidget::closeEvent(event);
}

void HistoryWindow::changeEvent(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;

    }
}
