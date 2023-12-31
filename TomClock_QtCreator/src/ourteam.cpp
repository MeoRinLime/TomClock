#include "ourteam.h"
#include "ui_ourteam.h"

OurTeam::OurTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OurTeam)
{
    ui->setupUi(this);
    this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");
    ui->scrollArea->viewport()->setStyleSheet(".QWidget{background-color:transparent;}");
}

OurTeam::~OurTeam()
{
    delete ui;
}

void OurTeam::AbouttoTeam()
{
    this->show();
}

void OurTeam::closeEvent(QCloseEvent *event)
{
    emit BacktoAbout();
    QWidget::closeEvent(event);
}


void OurTeam::on_backToAbout_clicked()
{
    this->hide();
    emit BacktoAbout();
}

void OurTeam::changeEvent(QEvent *event)
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
