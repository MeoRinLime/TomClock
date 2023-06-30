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
    ui->PauseResumeButton->setStyleSheet("QPushButton{\
                                        background-color: rgb(225, 225, 225);\
                                        border:2px groove gray;\
                                        border-radius:10px;\
                                        padding:2px 4px;\
                                        border-style: outset;\
                                        }\
                                        \
                                        QPushButton:hover{\
                                        background-color:rgb(229, 241, 251); \
                                        color: black;\
                                        }\
                                        \
                                        QPushButton:pressed{\
                                        background-color:rgb(204, 228, 247);\
                                        border-style: inset;\
                                        }");
    ui->AbortButton->setStyleSheet("QPushButton{\
                                        background-color: rgb(225, 225, 225);\
                                        border:2px groove gray;\
                                        border-radius:10px;\
                                        padding:2px 4px;\
                                        border-style: outset;\
                                        }\
                                        \
                                        QPushButton:hover{\
                                        background-color:rgb(229, 241, 251); \
                                        color: black;\
                                        }\
                                        \
                                        QPushButton:pressed{\
                                        background-color:rgb(204, 228, 247);\
                                        border-style: inset;\
                                        }");
    connect(this, &RunWindow::isPaused, this, [=](){
        isPausedForAchieve = true;
    });
}

RunWindow::~RunWindow()
{
    delete ui;
}

void RunWindow::closeEvent(QCloseEvent *event)
{
    //只有单个mission时，可以正常delete
//    delete secTimer;
//    delete periodTimer;
    secTimer->stop();
    periodTimer->stop();
    emit JumptoMain();
    QMainWindow::closeEvent(event);
    //下面会导致重复调用closeEvent，重复弹出提示框
//    //跳出确认提示框
//    //此时计时停止
//    secTimer->stop();
//    periodTimer->stop();
//    QMessageBox *abortConfirmMsgBox = new QMessageBox(this);
//    abortConfirmMsgBox->setWindowTitle("注意");
//    abortConfirmMsgBox->setText("确定结束本次任务吗？");
//    abortConfirmMsgBox->setInformativeText(QString("本次任务获得番茄总数为%1").arg(addNumOfTomato));
//    abortConfirmMsgBox->addButton(QMessageBox::Ok)->setText("确定");
//    abortConfirmMsgBox->addButton(QMessageBox::Cancel)->setText("取消");
//    abortConfirmMsgBox->setDefaultButton(QMessageBox::Cancel);

//    connect(abortConfirmMsgBox, &QDialog::accepted, this, [=](){
//        //同closeEvent的情况
////        delete secTimer;
////        delete periodTimer;
//       // emit noTomato(); //无番茄
//        //跳转到主窗口
//        //记录保存
//        history.setDate(QDate::currentDate());
//        history.setNumOfTomato(addNumOfTomato);
//        int s = 60 - displayedTime.second();
//        int m = curMission.getWorkTime().minute() * addNumOfTomato + (curMission.getWorkTime().minute() - displayedTime.minute() - 1);
//        int h = m / 60;
//        m = m % 60;
//        history.setTotalTime(QTime(h,m,s));
//        history.setName(curMission.getName());
//        //发送到历史记录
//        emit sentHistory(history);
//        emit toJudgeAchieve();
//        emit JumptoMain();
//        this->close();
//    });
//    connect(abortConfirmMsgBox, &QDialog::rejected, this, [=](){
//        //恢复计时
//        secTimer->start(1000);
//        periodTimer->start(whichPeriod%2==0 ? 1000 * QTime(0,0,0).secsTo(curMission.getWorkTime()) : 1000 * QTime(0,0,0).secsTo(curMission.getRelaxTime()));
//        abortConfirmMsgBox->close(); //无事发生，继续计时
//    });
//    abortConfirmMsgBox->exec();
}

void RunWindow::ListtoRun(const Mission &mission)
{


    ui->PauseResumeButton->setText(tr("暂停"));
    addNumOfTomato=0;
    curMission=mission;
        //参数初始化
    displayedTime = curMission.getWorkTime();            //显示的时间 工作时间

    ui->MissionNameLabel->setText(curMission.getName()); //显示 任务名
    ui->TimeDisplay->setText(displayedTime.toString());  //显示 时间
    this->show();
    addNumOfTomato=0;//    番茄数重零计时
    whichPeriod = 0;    //表示处于 第一个工作时间
    numOfRelax=0;
    oncePaused = false; //表示 从未暂停过
    secTimer = new QTimer(this);                            //创建 每秒计时器
    periodTimer = new QTimer(this);                         //创建 每段计时器
    connect(secTimer, SIGNAL(timeout()), this, SLOT(processTimeout()));
    connect(periodTimer, SIGNAL(timeout()), this, SLOT(nextPeriod()));
    secTimer->start(1000);                                  //开始计时，间隔1000毫秒
    periodTimer->start(1000 * QTime(0,0,0).secsTo(curMission.getWorkTime()));//开始计时，间隔为一个workTime
}

void RunWindow::processTimeout()
{
    displayedTime = displayedTime.addSecs(-1);          //-1s
    ui->TimeDisplay->setText(displayedTime.toString()); //显示 时间
    update();  //更新画面
}

void RunWindow::nextPeriod()
{
    int secRelaxTime = QTime(0,0,0).secsTo(curMission.getRelaxTime());
    int h = (4 * secRelaxTime) / 3600;
    int m = ((4 * secRelaxTime) % 3600) / 60;
    int s = ((4 * secRelaxTime) % 3600) % 60;
    QString sh = h > 9 ? QString::number(h) : QString("0%1").arg(h);
    QString sm = m > 9 ? QString::number(m) : QString("0%1").arg(m);
    QString ss = s > 9 ? QString::number(s) : QString("0%1").arg(s);

    switch (whichPeriod%8) {
    case 0:
        //进入第一个 休息时间段
        if (!oncePaused){
            addNumOfTomato++;
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("获得一个番茄");
            msgBox->setInformativeText("");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
        numOfRelax++;
        whichPeriod++;//1
        displayedTime = curMission.getRelaxTime();
        ui->MissionNameLabel->setText(tr("休息时间"));
        periodTimer->setInterval(1000 * QTime(0,0,0).secsTo(curMission.getRelaxTime()));
        update();
        break;
    case 1:
        //进入第二个 工作时间段
        oncePaused = false;
        whichPeriod++;//2
        displayedTime = curMission.getWorkTime();
        ui->MissionNameLabel->setText(curMission.getName());
        periodTimer->setInterval(1000 * QTime(0,0,0).secsTo(curMission.getWorkTime()));
        update();
        break;
    case 2:
        //进入第二个 休息时间段
        if (!oncePaused){
            addNumOfTomato++;
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("获得一个番茄");
            msgBox->setInformativeText("");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
        numOfRelax++;
        whichPeriod++;//3
        displayedTime = curMission.getRelaxTime();
        ui->MissionNameLabel->setText(tr("休息时间"));
        periodTimer->setInterval(1000 * QTime(0,0,0).secsTo(curMission.getRelaxTime()));
        update();
        break;
    case 3:
        //进入第三个 工作时间段
        oncePaused = false;
        whichPeriod++;//4
        displayedTime = curMission.getWorkTime();
        ui->MissionNameLabel->setText(curMission.getName());
        periodTimer->setInterval(1000 * QTime(0,0,0).secsTo(curMission.getWorkTime()));
        update();
        break;
    case 4:
        //进入第三个 休息时间段
        if (!oncePaused){
            addNumOfTomato++;
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("获得一个番茄");
            msgBox->setInformativeText("");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
        numOfRelax++;
        whichPeriod++;//5
        displayedTime = curMission.getRelaxTime();
        ui->MissionNameLabel->setText(tr("休息时间"));
        periodTimer->setInterval(1000 * QTime(0,0,0).secsTo(curMission.getRelaxTime()));
        update();
        break;
    case 5:
        //进入第四个 工作时间段
        oncePaused = false;
        whichPeriod++;//6
        displayedTime = curMission.getWorkTime();
        ui->MissionNameLabel->setText(curMission.getName());
        periodTimer->setInterval(1000 * QTime(0,0,0).secsTo(curMission.getWorkTime()));
        update();
        break;
    case 6:
        //进入第四个 长休息时间段
        if (!oncePaused){
            addNumOfTomato++;
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("获得一个番茄");
            msgBox->setInformativeText("");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
        numOfRelax++;
        whichPeriod++;//7
        displayedTime = QTime().fromString(QString("%1:%2:%3").arg(sh, sm, ss), "hh:mm:ss");
        ui->MissionNameLabel->setText(tr("长休息时间"));
        periodTimer->setInterval(1000 * 4 * secRelaxTime);
        update();
        break;
    case 7:
        //重新进入第1个 工作时间段
        oncePaused = false;
        whichPeriod++;//1
        displayedTime = curMission.getWorkTime();
        ui->MissionNameLabel->setText(curMission.getName());
        periodTimer->setInterval(1000 * QTime(0,0,0).secsTo(curMission.getWorkTime()));
        update();
        break;
    default:
        qDebug("whichPeriod error. Unknown state.");
        break;
    }
}

void RunWindow::on_PauseResumeButton_clicked()
{
    emit isPaused();
    oncePaused = true; //表示 曾经暂停过
    //停止/继续计时器
    if (secTimer->isActive()){
        secTimer->stop();
        periodTimer->stop();
        ui->PauseResumeButton->setText("继续");
        update();
    }
    else {
        secTimer->start(1000);
        periodTimer->start(whichPeriod%2==0 ? 1000 * QTime(0,0,0).secsTo(curMission.getWorkTime()) : 1000 * QTime(0,0,0).secsTo(curMission.getRelaxTime()));
        ui->PauseResumeButton->setText("暂停");
        update();
    }
}

void RunWindow::on_AbortButton_clicked()
{
    //跳出确认提示框
    //此时计时停止
    secTimer->stop();
    periodTimer->stop();
    QMessageBox *abortConfirmMsgBox = new QMessageBox(this);
    abortConfirmMsgBox->setWindowTitle(tr("注意"));
    abortConfirmMsgBox->setText(tr("确定结束本次任务吗？"));
    abortConfirmMsgBox->setInformativeText(tr("本次任务获得番茄总数为%1").arg(addNumOfTomato));
    abortConfirmMsgBox->addButton(QMessageBox::Ok)->setText(tr("确定"));
    abortConfirmMsgBox->addButton(QMessageBox::Cancel)->setText(tr("取消"));
    abortConfirmMsgBox->setDefaultButton(QMessageBox::Cancel);

    connect(abortConfirmMsgBox, &QDialog::accepted, this, [=](){
        //同closeEvent的情况
//        delete secTimer;
//        delete periodTimer;
       // emit noTomato(); //无番茄
        //跳转到主窗口
        //记录保存
        history.setDate(QDate::currentDate());
        history.setNumOfTomato(addNumOfTomato);
        int s ;
        int m;
        if( whichPeriod%2==0){
         m = curMission.getWorkTime().minute() * numOfRelax + (curMission.getWorkTime().minute() - displayedTime.minute() - 1);
          s = 60 - displayedTime.second();
        }
        else{
         m = curMission.getWorkTime().minute() * numOfRelax ;
         s = 0;
        }
        int h = m / 60;
        m = m % 60;
        history.setTotalTime(QTime(h,m,s));
        history.setName(curMission.getName());
        //发送到历史记录
        emit sentHistory(history);
        emit toJudgeAchieve();
        emit toJudgeAchieve(isPausedForAchieve);
        emit JumptoMain();
        this->close();
    });
    connect(abortConfirmMsgBox, &QDialog::rejected, this, [=](){
        //恢复计时
        secTimer->start(1000);
        periodTimer->start(whichPeriod%2==0 ? 1000 * QTime(0,0,0).secsTo(curMission.getWorkTime()) : 1000 * QTime(0,0,0).secsTo(curMission.getRelaxTime()));
        abortConfirmMsgBox->close(); //无事发生，继续计时
    });
    abortConfirmMsgBox->exec();
}

void RunWindow::changeEvent(QEvent *event)
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

Mission RunWindow::getCurMission() const
{
    return curMission;
}

void RunWindow::setCurMission(const Mission &newCurMission)
{
    curMission = newCurMission;
}
