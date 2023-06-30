#include "tomclock.h"

TomClock::TomClock()
{
    tcDatabase = new TomClockDatabase();
//    achievementW = new AchievementWindow();
    createW = new CreateMissionWindow();
    historyW= new HistoryWindow();
    runW = new RunWindow();
    settingW = new Settings();
    aboutW = new about();
    teamW = new OurTeam();


    initAchieveWindow();
    initHistoryWindow();
    initMissionListWindow();
    //更新totalTime和totalTomato
    totalTomato = historyW->caculateTotalTomato();
    totalTime.fromString(historyW->caculateTotalTime());

    mainW = new MainWindow(achieveList,historyList);

    qRegisterMetaType<QVector<History>>("QVector<History>");
    qRegisterMetaType<QVector<Achievement>>("QVector<Achievement>");

    //各页面之间进行跳转的实现
    connect(mainW, SIGNAL(JumptoAchievement(QVector<Achievement>)), achievementW, SLOT(MaintoAchievement(QVector<Achievement>)));
    connect(mainW, SIGNAL(JumptoHistory(QVector<History>)), historyW, SLOT(MaintoHistory(QVector<History>)));

    connect(mainW, SIGNAL(JumptoMissionList()), missionListW, SLOT(MaintoList()));
    connect(mainW, SIGNAL(JumptoSettings()), settingW, SLOT(MaintoSettings()));
    connect(mainW, SIGNAL(JumptoAbout()), aboutW, SLOT(MaintoAbout()));

    connect(historyW, SIGNAL(BacktoMain()), mainW, SLOT(HistorytoMain()));

    connect(aboutW, SIGNAL(AbouttoTeam()), teamW, SLOT(AbouttoTeam()));
    connect(aboutW, SIGNAL(BacktoMain()), mainW, SLOT(AbouttoMain()));

    connect(missionListW,SIGNAL(jumpToRunWindows(Mission)),runW,SLOT(ListtoRun(Mission)));
    connect(missionListW,SIGNAL(create()),createW,SLOT(toCreate()));
    connect(missionListW, SIGNAL(BacktoMain()), mainW, SLOT(ListtoMain()));

    connect(teamW, SIGNAL(BacktoAbout()), aboutW, SLOT(TeamtoAbout()));
    connect(settingW, SIGNAL(BacktoMain()), mainW, SLOT(SettingstoMain()));
    connect(runW, SIGNAL(JumptoMain()), mainW, SLOT(RuntoMain()));
    connect(achievementW, SIGNAL(JumptoMain()), mainW, SLOT(AchievetoMain()));

    connect(createW,SIGNAL(sentAndJump(Mission)),missionListW,SLOT(recieveMission(Mission)));

    connect(missionListW,SIGNAL(updateDatabase()),this,SLOT(updataMissionDatabase()));
    connect(runW,SIGNAL(sentHistory(History)),this,SLOT(updataHistoryDatabase(History)));
    connect(runW, SIGNAL(toJudgeAchieve()), this, SLOT(judgeAchieve()));
    connect(this, SIGNAL(updateHistory(QVector<History>)), historyW, SLOT(MaintoHistory(QVector<History>)));
    connect(runW, SIGNAL(toJudgeAchieve(bool)), this, SLOT(judgeAchieve(bool)));
}

TomClock::~TomClock()
{
    delete tcDatabase;
    delete mainW;
    delete achievementW;
    delete createW;
    delete historyW;
    delete missionListW;
    delete runW;
    delete settingW;
    delete aboutW;
    delete teamW;
}

void TomClock::initAchieveWindow()
{
    tcDatabase->initAchievement();       //若表为空则初始化，否则不做操作
    tcDatabase->queryAchievement(achieveList);      //从数据库获取成就数据
    achievementW = new AchievementWindow();
}

void TomClock::initMissionListWindow()
{
    tcDatabase->queryMission(missionList);
    //将missionList传给missionListW
    missionListW = new MissionListWindow(missionList);
}

void TomClock::initHistoryWindow()
{
    tcDatabase->queryHistory(historyList);
}

void TomClock::showWindow()
{
    mainW->show();
}

void TomClock::judgeAchieve(bool paused){
    emit updateHistory(historyList);
    historyW->hide();
    totalTomato = historyW->caculateTotalTomato();
    achievementW->changeTomatoNum(totalTomato);
    totalTime = historyW->calculateNumTotalTime();
    if (paused){
        //记录原先的成就状态
        bool originAchieveState = achieveList[5].getState();
        tcDatabase->updateAchievement(achieveList[5]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：世界");
            msgBox->setInformativeText("暂停1次时间");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }
    tcDatabase->queryAchievement(achieveList);//更新程序中的achieveList
}

void TomClock::judgeAchieve()
{
    emit updateHistory(historyList);
    historyW->hide();
    totalTomato = historyW->caculateTotalTomato();
    achievementW->changeTomatoNum(totalTomato);
    totalTime = historyW->calculateNumTotalTime();
    /* if (成就1条件){
     *  tcDatabase->updateAchievement(achieveList[0]);
     * }
     * if (成就2条件){
     *  tcDatabase->updateAchievement(achieveList[1]);
     * }
     * ...
     * ...
    */
    if (totalTomato >= 1){
        //记录原先的成就状态
        bool originAchieveState = achieveList[0].getState();
        tcDatabase->updateAchievement(achieveList[0]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：番茄小子");
            msgBox->setInformativeText("获得你的第1个番茄");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }
    if (totalTomato >= 10){
        //记录原先的成就状态
        bool originAchieveState = achieveList[1].getState();
        tcDatabase->updateAchievement(achieveList[1]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：番茄达人");
            msgBox->setInformativeText("累计获得10个番茄");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }
    if (totalTomato >= 100){
        //记录原先的成就状态
        bool originAchieveState = achieveList[2].getState();
        tcDatabase->updateAchievement(achieveList[2]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：番茄狂魔");
            msgBox->setInformativeText("累计获得100个番茄");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }
    if (runW->getCurMission().getWorkTime() <= QTime(0,15,0)){
        //记录原先的成就状态
        bool originAchieveState = achieveList[3].getState();
        tcDatabase->updateAchievement(achieveList[3]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：速战速决");
            msgBox->setInformativeText("设置1个工作时间短的任务");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }
    if (runW->getCurMission().getWorkTime() >= QTime(0,50,0)){
        //记录原先的成就状态
        bool originAchieveState = achieveList[4].getState();
        tcDatabase->updateAchievement(achieveList[4]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：长线作战");
            msgBox->setInformativeText("设置1个工作时间长的任务");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }

    if (true){ //必定触发
        //记录原先的成就状态
        bool originAchieveState = achieveList[6].getState();
        tcDatabase->updateAchievement(achieveList[6]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：就到这里吧");
            msgBox->setInformativeText("终止1次任务");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }
    if (historyList[historyList.size() == 0 ? 0 : historyList.size() - 1].getDate().daysTo(QDate::currentDate()) >= 1){
        //记录原先的成就状态
        bool originAchieveState = achieveList[7].getState();
        tcDatabase->updateAchievement(achieveList[7]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：偷个小懒");
            msgBox->setInformativeText("1天没有开始任务");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }
    if (historyList[historyList.size() == 0 ? 0 : historyList.size() - 1].getDate().daysTo(QDate::currentDate()) >= 5){
        //记录原先的成就状态
        bool originAchieveState = achieveList[8].getState();
        tcDatabase->updateAchievement(achieveList[8]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：浑水摸鱼");
            msgBox->setInformativeText("5天没有开始任务");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }
    if (historyList[historyList.size() == 0 ? 0 : historyList.size() - 1].getDate().daysTo(QDate::currentDate()) >= 15){
        //记录原先的成就状态
        bool originAchieveState = achieveList[9].getState();
        tcDatabase->updateAchievement(achieveList[9]);//只能变成达成状态
        //应当只有原本成就状态是未达成时才exec以下消息
        if (!originAchieveState){
            QMessageBox *msgBox = new QMessageBox(mainW);
            msgBox->setWindowTitle("恭喜！");
            msgBox->setText("达成成就：我就是咸鱼");
            msgBox->setInformativeText("15天没有开始任务");
            msgBox->addButton(QMessageBox::Ok)->setText("好的");
            connect(msgBox, &QDialog::accepted, this, [=](){
                msgBox->close();
            });
            msgBox->exec();
        }
    }

    //下面是示例
//    if (totalTime > QTime(0,0,0,1)){ //历史总时长大于1毫秒
//        //记录原先的成就状态
//        bool originAchieveState = achieveList[0].getState();
//        tcDatabase->updateAchievement(achieveList[0]);//只能变成达成状态
//        //应当只有原本成就状态是未达成时才exec以下消息
//        if (!originAchieveState){
//            QMessageBox *msgBox = new QMessageBox(mainW);
//            msgBox->setWindowTitle("恭喜！");
//            msgBox->setText("达成成就：聊胜于无");
//            msgBox->setInformativeText("你开始了一个任务，尽管时间可能很短");
//            msgBox->addButton(QMessageBox::Ok)->setText("好的");
//            connect(msgBox, &QDialog::accepted, this, [=](){
//                msgBox->close();
//            });
//            msgBox->exec();
//        }
//    }
    //示例结束
    tcDatabase->queryAchievement(achieveList);//更新程序中的achieveList
}

void TomClock::updataMissionDatabase(){
    missionList.clear();
    missionList = missionListW->getMission();
//    qDebug()<<"hhhhhh";
    tcDatabase->updateMission(missionList);
}

void TomClock::updataHistoryDatabase(History h){
    h.setId(historyList.size());
    historyList.push_back(h);
    tcDatabase->addHistory(h);
}
