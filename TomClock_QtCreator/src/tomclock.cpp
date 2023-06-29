#include "tomclock.h"

TomClock::TomClock()
{
    tcDatabase = new TomClockDatabase();
    mainW = new MainWindow();
//    achievementW = new AchievementWindow();
    createW = new CreateMissionWindow();
    historyW = new HistoryWindow();
    missionListW = new MissionListWindow();
    runW = new RunWindow();
    settingW = new Settings();
    aboutW = new about();
    teamW = new OurTeam();

    //achieve test
    Achievement a1("第1个番茄", 0, "获得你的第1个番茄");
    Achievement a2("第5个番茄", 0, "累计获得5个番茄");
    Achievement a3("第10个番茄", 0, "累计获得10个番茄");
    Achievement a4("第100个番茄", 0, "累计获得100个番茄");
    Achievement a5("第150个番茄", 0, "累计获得150个番茄");
    achieveList.append(a1);
    achieveList.append(a2);
    achieveList.append(a3);
    achieveList.append(a4);
    achieveList.append(a5);
    a1.setState(1);
    tcDatabase->updateAchievement(a1);
    //achieve test end

    initAchieveWindow();

    //各页面之间进行跳转的实现
    connect(mainW, SIGNAL(JumptoAchievement()), achievementW, SLOT(MaintoAchievement()));
    connect(mainW, SIGNAL(JumptoHistory()), historyW, SLOT(MaintoHistory()));
//    connect(&mainW, SIGNAL(JumptoMissionCreate()), &createW, SLOT(MaintoCreate()));
    connect(mainW, SIGNAL(JumptoMissionList()), missionListW, SLOT(MaintoList()));
    connect(mainW, SIGNAL(JumptoSettings()), settingW, SLOT(MaintoSettings()));
    connect(mainW, SIGNAL(JumptoAbout()), aboutW, SLOT(MaintoAbout()));
    connect(settingW, SIGNAL(BacktoMain()), mainW, SLOT(SettingstoMain()));
    connect(historyW, SIGNAL(BacktoMain()), mainW, SLOT(HistorytoMain()));
    connect(aboutW, SIGNAL(AbouttoTeam()), teamW, SLOT(AbouttoTeam()));
    connect(aboutW, SIGNAL(BacktoMain()), mainW, SLOT(AbouttoMain()));
    connect(teamW, SIGNAL(BacktoAbout()), aboutW, SLOT(TeamtoAbout()));
    connect(missionListW,SIGNAL(jumpToRunWindows(Mission)),runW,SLOT(ListtoRun(Mission)));
//    connect(&createW,SIGNAL(sentAndJump(Mission)),&mainW,SLOT(othertoMain()));
    connect(createW,SIGNAL(sentAndJump(Mission)),missionListW,SLOT(recieveMission(Mission)));
    connect(missionListW,SIGNAL(create()),createW,SLOT(toCreate()));
    connect(runW, SIGNAL(JumptoMain()), mainW, SLOT(RuntoMain()));
    connect(achievementW, SIGNAL(JumptoMain()), mainW, SLOT(AchievetoMain()));
    connect(missionListW, SIGNAL(BacktoMain()), mainW, SLOT(ListtoMain()));
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
    tcDatabase->initAchievement(achieveList);       //若表为空则初始化，否则不做操作
    tcDatabase->queryAchievement(achieveList);      //从数据库获取成就数据
    achievementW = new AchievementWindow(achieveList);
}

void TomClock::initMissionListWindow()
{
    tcDatabase->queryMission(missionList);
    //将missionList传给missionListW
}

void TomClock::initHistoryWindow()
{
    tcDatabase->queryHistory(historyList);
    //将historyList传给historyW
}

void TomClock::showWindow()
{
    mainW->show();
}
