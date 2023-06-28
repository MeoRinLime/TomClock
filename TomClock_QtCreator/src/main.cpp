#include "mainwindow.h"
#include "achievementwindow.h"
#include "createmissionwindow.h"
#include "historywindow.h"
#include "missionlistwindow.h"
#include "runwindow.h"
#include "settings.h"
#include "about.h"
#include "ourteam.h"


#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TomClock_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //先创建所有窗口，跳转页面就是隐藏和显示不同的窗口
    MainWindow mainW;
    AchievementWindow achievementW;
    CreateMissionWindow createW;
    HistoryWindow historyW;
    MissionListWindow listW;
    RunWindow runW;
    Settings settingW;
    about aboutW;
    //test
    TomClockDatabase tcdb(qApp->applicationDirPath());
    Mission m1(1, "study math", QTime().fromString("00:25", "mm:ss"), QTime().fromString("00:05", "mm:ss"), QDate::currentDate());
    Mission m2(2, "study english", QTime().fromString("00:25", "mm:ss"), QTime().fromString("00:05", "mm:ss"), QDate::currentDate());
    Mission ml[2] = {m1, m2};
    Mission *qm = new Mission[2];
    History h1(1, QDate::currentDate(), "study math", 0, QTime().fromString("11:45", "mm:ss"));
    History *qh = new History[1];
    Achievement a1("First Tomato", 0, "Get your first tomato by complete a mission.");
    Achievement al[1] = {a1};
    Achievement *qa = new Achievement[1];
    tcdb.createMission(m1);
    tcdb.createMission(m2);
    tcdb.deleteMission(1);
    tcdb.updateMission(2, ml);
    delete[] qm;
    qm = tcdb.queryMission();
//    qDebug(QString("%1").arg(qm[0].getId()).toLatin1());
//    qDebug(QString("%1").arg(qm[1].getId()).toLatin1());
    tcdb.addHistory(h1);
    delete[] qh;
    qh = tcdb.queryHistory();
//    qDebug(QString("%1").arg(qh[0].getId()).toLatin1());
    tcdb.initAchievement(1, al);
    delete[] qa;
    qa = tcdb.queryAchievement();
//    qDebug(QString("%1").arg(qa[0].getState()).toLatin1());
    tcdb.updateAchievement("First Tomato");
    delete[] qa;
    qa = tcdb.queryAchievement();
//    qDebug(QString("%1").arg(qa[0].getState()).toLatin1());
    delete[] qm;
    qm = nullptr;
    delete[] qh;
    qh = nullptr;
    delete[] qa;
    qa = nullptr;
    //test end
    OurTeam teamW;

    mainW.show();

    //各页面之间进行跳转的实现
    QObject::connect(&mainW, SIGNAL(JumptoAchievement()), &achievementW, SLOT(MaintoAchievement()));
    QObject::connect(&mainW, SIGNAL(JumptoHistory()), &historyW, SLOT(MaintoHistory()));
   // QObject::connect(&mainW, SIGNAL(JumptoMissionCreate()), &createW, SLOT(MaintoCreate()));
    QObject::connect(&mainW, SIGNAL(JumptoMissionList()), &listW, SLOT(MaintoList()));
    QObject::connect(&mainW, SIGNAL(JumptoSettings()), &settingW, SLOT(MaintoSettings()));
    QObject::connect(&mainW, SIGNAL(JumptoAbout()), &aboutW, SLOT(MaintoAbout()));
    QObject::connect(&settingW, SIGNAL(BacktoMain()), &mainW, SLOT(SettingstoMain()));
    QObject::connect(&historyW, SIGNAL(BacktoMain()), &mainW, SLOT(HistorytoMain()));
    QObject::connect(&aboutW, SIGNAL(AbouttoTeam()), &teamW, SLOT(AbouttoTeam()));
    QObject::connect(&aboutW, SIGNAL(BacktoMain()), &mainW, SLOT(AbouttoMain()));
    QObject::connect(&teamW, SIGNAL(BacktoAbout()), &aboutW, SLOT(TeamtoAbout()));
    QObject::connect(&listW,SIGNAL(jumpToRunWindows(Mission)),&runW,SLOT(ListtoRun(Mission)));
    //QObject::connect(&createW,SIGNAL(sentAndJump(Mission)),&mainW,SLOT(othertoMain()));
     QObject::connect(&createW,SIGNAL(sentAndJump(Mission)),&listW,SLOT(recieveMission(Mission)));
    QObject::connect(&listW,SIGNAL(create()),&createW,SLOT(toCreate()));
    //我尝试了在各个页面的cpp文件下写页面跳转，但是好像先创建所有窗口方法的跳转不支持，你们有解决办法可以重写一下

    return a.exec();
}
