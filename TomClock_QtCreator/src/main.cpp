#include "mainwindow.h"
#include "achievementwindow.h"
#include "createmissionwindow.h"
#include "historywindow.h"
#include "missionlistwindow.h"
#include "runwindow.h"
#include "settings.h"
#include "about.h"


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
    MainWindow mainW;
    AchievementWindow achievementW;
    CreateMissionWindow createW;
    HistoryWindow historyW;
    MissionListWindow listW;
    RunWindow runW;
    Settings settingW;
    about aboutW;
    mainW.show();
    //createW.show();
    //historyW.show();
    QObject::connect(&mainW, SIGNAL(JumptoAchievement()), &achievementW, SLOT(MaintoAchievement()));
    QObject::connect(&mainW, SIGNAL(JumptoHistory()), &historyW, SLOT(MaintoHistory()));
    QObject::connect(&mainW, SIGNAL(JumptoMissionCreate()), &createW, SLOT(MaintoCreate()));
    QObject::connect(&mainW, SIGNAL(JumptoMissionList()), &listW, SLOT(MaintoList()));
    QObject::connect(&mainW, SIGNAL(JumptoSettings()), &settingW, SLOT(MaintoSettings()));
    QObject::connect(&mainW, SIGNAL(JumptoAbout()), &aboutW, SLOT(MaintoAbout()));
    return a.exec();
}
