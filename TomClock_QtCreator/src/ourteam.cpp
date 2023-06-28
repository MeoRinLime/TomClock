#include "ourteam.h"
#include "ui_ourteam.h"

OurTeam::OurTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OurTeam)
{
    ui->setupUi(this);
    this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");
}

OurTeam::~OurTeam()
{
    delete ui;
}

void OurTeam::AbouttoTeam()
{
    this->show();
}


void OurTeam::on_backToAbout_clicked()
{
    this->hide();
    emit BacktoAbout();
}

