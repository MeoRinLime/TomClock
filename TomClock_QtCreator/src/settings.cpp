#include "settings.h"
#include "ui_settings.h"

#include <QLabel>

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("Settings {border-image:url(:/images/resourse/images/background/bg3.png);}");

}

Settings::~Settings()
{
    delete ui;
}

void Settings::MaintoSettings()
{
    this->show();
}

void Settings::on_themeChange_currentTextChanged(const QString &arg1)
{
    if(arg1 == QStringLiteral("夜色如墨"))
    {
        this->setStyleSheet("Settings {border-image:url(:/images/resourse/images/background/bg2.png);}");
        emit LightTheme();
    }

    else if(arg1 == QStringLiteral("晨曦微光"))
    {
        this->setStyleSheet("Settings {border-image:url(:/images/resourse/images/background/bg3.png);}");
        emit DarkTheme();
    }
}



void Settings::on_backToMain_clicked()
{
    this->hide();
    emit BackToMain();
}

void Settings::ChangeToLight()
{
    this->setStyleSheet("Settings {border-image:url(:/images/resourse/images/background/bg3.png);}");
}

void Settings::ChangeToDark()
{
    this->setStyleSheet("Settings {border-image:url(:/images/resourse/images/background/bg2.png);}");
}
