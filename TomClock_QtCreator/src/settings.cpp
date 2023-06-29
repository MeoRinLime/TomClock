#include "settings.h"
#include "ui_settings.h"

#include <QLabel>
#include <QPalette>

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");

    connect(ui->themeChange, SIGNAL(currentIndexChanged(int)), this, SLOT(on_themeChange_currentIndexChanged(int)));

}

Settings::~Settings()
{
    delete ui;
}

void Settings::closeEvent(QCloseEvent *event)
{
    emit BacktoMain();
    QWidget::closeEvent(event);
}



void Settings::MaintoSettings()
{
    this->show();
}

void Settings::on_backToMain_clicked()
{
    this->hide();
    emit BacktoMain();
}

void Settings::on_themeChange_currentIndexChanged(int index)
{
    QString backgroundImage;
    switch (index)
    {
    case 0: // "晨雾微光"
        backgroundImage = ":/images/resourse/images/background/bg3.png";
        break;
    case 1: // "夜幕如墨"
        backgroundImage = ":/images/resourse/images/background/bg2.png";
        break;
    default:
        backgroundImage = ":/images/resourse/images/background/bg3.png";
        //默认浅色背景
        break;
    }

    // 修改所有界面的背景图片

    QList<QWidget*> windows = QApplication::topLevelWidgets();
    for (QWidget* window : windows)
    {
        QString windowObjectName = window->objectName();
        if(windowObjectName == "MainWindow")
        {
            window->setStyleSheet(windowObjectName + " { border-image: url(" + backgroundImage + ");}");
        }
        else
        {
            window->setStyleSheet("#frame { border-image: url(" + backgroundImage + ");}");
        }
    }
/* 有一个问题就是切换背景图片的时候会提示“Could not parse stylesheet of object QComboBoxPrivateContainer”
 * 同时需要加载2-3秒钟才可以完成切换，我暂时还没有找到解决办法。好像可以自定义事件，如果时间充裕再考虑写一下
 */
//    this->setStyleSheet("Settings {border-image:url(:/images/resourse/images/background/bg2.png);}");
//    "Data { background-image: url(/path/to/background/image.jpg);}"
}


