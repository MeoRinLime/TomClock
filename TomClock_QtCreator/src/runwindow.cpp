#include "runwindow.h"
#include "ui_runwindow.h"
#include <QTimer>
#include <QMessageBox>

RunWindow::RunWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("#frame {border-image:url(:/images/resourse/images/background/bg3.png);}");
}

RunWindow::RunWindow(const Mission &m, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunWindow)
{
    ui->setupUi(this);


}

RunWindow::~RunWindow()
{
    delete ui;
}

void RunWindow::ListtoRun(Mission mission)
{
    curMission=mission;
                                        //参数初始化
    displayedTime = curMission.getWorkTime();            //显示的时间 工作时间

    ui->MissionNameLabel->setText(curMission.getName()); //显示 任务名
    ui->TimeDisplay->setText(displayedTime.toString());  //显示 时间
    qDebug()<<"seccuess";
    this->show();
    whichPeriod = 0;    //表示处于 第一个工作时间
    oncePaused = false; //表示 从未暂停过
    secTimer = new QTimer(this);                            //创建 每秒计时器
    periodTimer = new QTimer(this);                         //创建 每段计时器
    connect(secTimer, SIGNAL(timeout()), this, SLOT(processTimeout()));
    connect(periodTimer, SIGNAL(timeout()), this, SLOT(nextPeriod()));
    secTimer->start(1000);                                  //开始计时，间隔1000毫秒
    periodTimer->start(1000 * (\
        curMission.getWorkTime().hour() * 3600 + \
        curMission.getWorkTime().minute() * 60 + \
        curMission.getWorkTime().second()));          //开始计时，间隔为一个workTime
}

void RunWindow::processTimeout()
{
    displayedTime = displayedTime.addSecs(-1);          //-1s
    ui->TimeDisplay->setText(displayedTime.toString()); //显示 时间
    update();  //更新画面
}

void RunWindow::nextPeriod()
{
    int secRelaxTime = curMission.getRelaxTime().hour() * 3600 \
        + curMission.getRelaxTime().minute() * 60 \
        + curMission.getRelaxTime().second();
    int h = (4 * secRelaxTime) / 3600;
    int m = ((4 * secRelaxTime) % 3600) / 60;
    int s = ((4 * secRelaxTime) % 3600) % 60;
    QString sh = h > 9 ? QString::number(h) : QString("0%1").arg(h);
    QString sm = m > 9 ? QString::number(m) : QString("0%1").arg(m);
    QString ss = s > 9 ? QString::number(s) : QString("0%1").arg(s);

    switch (whichPeriod) {
    case 0:
        //进入第一个 休息时间段
        whichPeriod++;//1
        displayedTime = curMission.getRelaxTime();
        ui->MissionNameLabel->setText(QString("休息时间"));
        periodTimer->setInterval(1000 * (\
            curMission.getRelaxTime().hour() * 3600 + \
            curMission.getRelaxTime().minute() * 60 + \
            curMission.getRelaxTime().second()));
        update();
        break;
    case 1:
        //进入第二个 工作时间段
        whichPeriod++;//2
        displayedTime = curMission.getWorkTime();
        ui->MissionNameLabel->setText(curMission.getName());
        periodTimer->setInterval(1000 * (\
            curMission.getWorkTime().hour() * 3600 + \
            curMission.getWorkTime().minute() * 60 + \
            curMission.getWorkTime().second()));
        update();
        break;
    case 2:
        //进入第二个 休息时间段
        whichPeriod++;//3
        displayedTime = curMission.getRelaxTime();
        ui->MissionNameLabel->setText(QString("休息时间"));
        periodTimer->setInterval(1000 * (\
            curMission.getRelaxTime().hour() * 3600 + \
            curMission.getRelaxTime().minute() * 60 + \
            curMission.getRelaxTime().second()));
        update();
        break;
    case 3:
        //进入第三个 工作时间段
        whichPeriod++;//4
        displayedTime = curMission.getWorkTime();
        ui->MissionNameLabel->setText(curMission.getName());
        periodTimer->setInterval(1000 * (\
            curMission.getWorkTime().hour() * 3600 + \
            curMission.getWorkTime().minute() * 60 + \
            curMission.getWorkTime().second()));
        update();
        break;
    case 4:
        //进入第三个 休息时间段
        whichPeriod++;//5
        displayedTime = curMission.getRelaxTime();
        ui->MissionNameLabel->setText(QString("休息时间"));
        periodTimer->setInterval(1000 * (\
            curMission.getRelaxTime().hour() * 3600 + \
            curMission.getRelaxTime().minute() * 60 + \
            curMission.getRelaxTime().second()));
        update();
        break;
    case 5:
        //进入第四个 工作时间段
        whichPeriod++;//6
        displayedTime = curMission.getWorkTime();
        ui->MissionNameLabel->setText(curMission.getName());
        periodTimer->setInterval(1000 * (\
            curMission.getWorkTime().hour() * 3600 + \
            curMission.getWorkTime().minute() * 60 + \
            curMission.getWorkTime().second()));
        update();
        break;
    case 6:
        //进入第四个 长休息时间段
        whichPeriod++;//7
        displayedTime = QTime().fromString(QString("%1:%2:%3").arg(sh, sm, ss), "hh:mm:ss");
        ui->MissionNameLabel->setText(QString("长休息时间"));
        periodTimer->setInterval(1000 * 4 * secRelaxTime);
        update();
        break;
    case 7:
        //整个任务结束
        if (oncePaused){ //若曾经暂停过，则无番茄
            emit noTomato();
        }
        else { //未暂停过，则番茄+1
            emit oneMoreTomato();
        }
        //跳转回主窗口
        /*
        emit RuntoMain();
        */
        this->close();
        break;
    default:
        qDebug("whichPeriod error. Unknown state.");
        break;
    }
}

void RunWindow::on_PauseResumeButton_clicked()
{
    oncePaused = true; //表示 曾经暂停过
    //停止/继续计时器
    if (secTimer->isActive()){
        secTimer->stop();
        ui->PauseResumeButton->setText("继续");
        update();
    }
    else {
        secTimer->start(1000);
        ui->PauseResumeButton->setText("暂停");
        update();
    }
}

void RunWindow::on_AbortButton_clicked()
{
    //跳出确认提示框
    //此时计时仍继续
    QMessageBox *abortConfirmMsgBox = new QMessageBox(this);
    abortConfirmMsgBox->setWindowTitle("注意");
    abortConfirmMsgBox->setText("确定终止本次任务吗？");
    abortConfirmMsgBox->setInformativeText("终止任务将无法获得番茄");
    abortConfirmMsgBox->addButton(QMessageBox::Ok)->setText("确定");
    abortConfirmMsgBox->addButton(QMessageBox::Cancel)->setText("取消");
    abortConfirmMsgBox->setDefaultButton(QMessageBox::Cancel);

    connect(abortConfirmMsgBox, &QDialog::accepted, this, [=](){
        emit noTomato(); //无番茄
        //跳转到主窗口
        /*
        emit RuntoMain();
        */
        this->close();
    });
    connect(abortConfirmMsgBox, &QDialog::rejected, this, [=](){
        abortConfirmMsgBox->close(); //无事发生，继续计时
    });
    abortConfirmMsgBox->exec();
}
