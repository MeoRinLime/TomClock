#include "about.h"
#include "ui_about.h"
#include<QDesktopServices>
#include <QResizeEvent>
#include <QPalette>

about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");
}

about::~about()
{
    delete ui;
}

void about::MaintoAbout()
{
    this->show();
}

void about::on_backToMain_clicked()
{
    this->hide();
    emit BacktoMain();
}


void about::on_ourTeam_clicked()
{
    this->hide();
    emit AbouttoTeam();
}


void about::on_github_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/MeoRinLime/TomClock")));
}

void about::TeamtoAbout()
{
    this->show();
}

void about::closeEvent(QCloseEvent *event)
{
    emit BacktoMain();
    QWidget::closeEvent(event);
}

void about::changeEvent(QEvent *event)
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
