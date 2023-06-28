#include "tomclock.h"

TomClock::TomClock()
{
    tcDatabase = new TomClockDatabase();
    mainW = new MainWindow();
    achievementW = new AchievementWindow();
    createW = new CreateMissionWindow();
    historyW = new HistoryWindow();
    missionListW = new MissionListWindow();
    runW = new RunWindow();
    settingW = new Settings();
    aboutW = new about();
    teamW = new OurTeam();

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

}

void TomClock::initMissionListWindow()
{

}

void TomClock::initHistoryWindow()
{

}
