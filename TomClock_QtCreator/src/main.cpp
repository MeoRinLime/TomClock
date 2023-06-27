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
    OurTeam teamW;

    mainW.show();

    //各页面之间进行跳转的实现
    QObject::connect(&mainW, SIGNAL(JumptoAchievement()), &achievementW, SLOT(MaintoAchievement()));
    QObject::connect(&mainW, SIGNAL(JumptoHistory()), &historyW, SLOT(MaintoHistory()));
    QObject::connect(&mainW, SIGNAL(JumptoMissionCreate()), &createW, SLOT(MaintoCreate()));
    QObject::connect(&mainW, SIGNAL(JumptoMissionList()), &listW, SLOT(MaintoList()));
    QObject::connect(&mainW, SIGNAL(JumptoSettings()), &settingW, SLOT(MaintoSettings()));
    QObject::connect(&mainW, SIGNAL(JumptoAbout()), &aboutW, SLOT(MaintoAbout()));
    QObject::connect(&settingW, SIGNAL(BacktoMain()), &mainW, SLOT(SettingstoMain()));
    QObject::connect(&historyW, SIGNAL(BacktoMain()), &mainW, SLOT(HistorytoMain()));
    QObject::connect(&aboutW, SIGNAL(AbouttoTeam()), &teamW, SLOT(AbouttoTeam()));
    QObject::connect(&aboutW, SIGNAL(BacktoMain()), &mainW, SLOT(AbouttoMain()));
    QObject::connect(&teamW, SIGNAL(BacktoAbout()), &aboutW, SLOT(TeamtoAbout()));

    //我尝试了在各个页面的cpp文件下写页面跳转，但是好像先创建所有窗口方法的跳转不支持，你们有解决办法可以重写一下

    return a.exec();
}
