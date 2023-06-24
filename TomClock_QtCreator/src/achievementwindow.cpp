#include "achievementwindow.h"
#include "ui_achievementwindow.h"
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QPixmap>

AchievementWindow::AchievementWindow(int achievementNum, Achievement *achievementList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AchievementWindow)
{
    ui->setupUi(this);

    QWidget *backdrop = new QWidget;                 //创建滚动显示区域幕布
    QHBoxLayout *layout = new QHBoxLayout(backdrop); //创建布局

    //成就图片的文件名，目前仅为实例
    QList<QString>imageList;
    imageList << QString("MainIcon.png")  //0
              << QString("resources/images/Icons/Main_Color/tomato1.png"); //1

    for(int i = 0; i < achievementNum; i++){
        QWidget *tmpWidgetPtr = new QWidget();                  //当前的成就的widget
        QVBoxLayout *tmpLayout = new QVBoxLayout(tmpWidgetPtr); //每个成就内部的布局

        QLabel *imageLabel = new QLabel();                                        //当前成就的图片
        imageLabel->setPixmap(QPixmap(QString(":/images/%1").arg(imageList[i]))); //设置图片路径
        QLabel *achievementName = new QLabel(achievementList[i].getName());       //当前成就的名字
        QLabel *howToAchieve = new QLabel(achievementList[i].getHowToAchieve());  //当前成就达成条件

        tmpLayout->addWidget(imageLabel);      //将图片放入当前成就的布局
        tmpLayout->addWidget(achievementName); //将成就名放入当前成就的布局
        tmpLayout->addWidget(howToAchieve);    //将成就达成条件放入当前布局

        layout->addWidget(tmpWidgetPtr);       //将每个成就的widget放入layout
    }

    //将幕布放入scrollArea
    ui->scrollArea->setWidget(backdrop);
}

AchievementWindow::~AchievementWindow()
{
    delete ui;
}
