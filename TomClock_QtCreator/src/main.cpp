#include "tomclock.h"

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

    TomClock tomClock;
    tomClock.showWindow(); //显示主窗口

//    //test
//    TomClockDatabase tcdb;
//    Mission m1(1, "study math", QTime().fromString("00:25", "mm:ss"), QTime().fromString("00:05", "mm:ss"), QDate::currentDate());
//    Mission m2(2, "study english", QTime().fromString("00:25", "mm:ss"), QTime().fromString("00:05", "mm:ss"), QDate::currentDate());
//    QVector<Mission> ml = {m1, m2};
//    QVector<Mission> qm;
//    History h1(1, QDate::currentDate(), "study math", 0, QTime().fromString("11:45", "mm:ss"));
//    QVector<History> qh = {h1};
//    Achievement a1("First Tomato", 0, "Get your first tomato by complete a mission.");
//    QVector<Achievement> al = {a1};
//    QVector<Achievement> qa;
//    tcdb.createMission(m1);
//    tcdb.createMission(m2);
//    tcdb.deleteMission(1);
//    tcdb.updateMission(ml);
//    qm = tcdb.queryMission();
////    qDebug(QString("%1").arg(qm[0].getId()).toLatin1());
////    qDebug(QString("%1").arg(qm[1].getId()).toLatin1());
//    tcdb.addHistory(h1);
//    qh = tcdb.queryHistory();
////    qDebug(QString("%1").arg(qh[0].getId()).toLatin1());
//    tcdb.initAchievement(al);
//    qa = tcdb.queryAchievement();
////    qDebug(QString("%1").arg(qa[0].getState()).toLatin1());
//    tcdb.updateAchievement(a1);
//    qa = tcdb.queryAchievement();
////    qDebug(QString("%1").arg(qa[0].getState()).toLatin1());
//    //test end
//    mainW.show();


    //我尝试了在各个页面的cpp文件下写页面跳转，但是好像先创建所有窗口方法的跳转不支持，你们有解决办法可以重写一下

    return a.exec();
}
