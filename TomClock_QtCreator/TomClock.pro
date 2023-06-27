QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/achievement.cpp \
    src/about.cpp \
    src/missionpushbutton.cpp \
    src/ourteam.cpp \
    src/settings.cpp \
    src/achievementwindow.cpp \
    src/createmissionwindow.cpp \
    src/history.cpp \
    src/historywindow.cpp \
    src/mission.cpp \
    src/missionlistwindow.cpp \
    src/runwindow.cpp \
    src/tomclock.cpp \
    src/tomclockdatabase.cpp \
    src\main.cpp \
    src\mainwindow.cpp

HEADERS += \
    src/achievement.h \
    src/about.h \
    src/missionpushbutton.h \
    src/ourteam.h \
    src/settings.h \
    src/achievementwindow.h \
    src/createmissionwindow.h \
    src/history.h \
    src/historywindow.h \
    src/mission.h \
    src/missionlistwindow.h \
    src/runwindow.h \
    src/tomclock.h \
    src/tomclockdatabase.h \
    src\mainwindow.h
    src/mainwindow.h

FORMS += \
    screenUi/about.ui \
    screenUi/achievementwindow.ui \
    screenUi/createmissionwindow.ui \
    screenUi/historywindow.ui \
    screenUi/missionlistwindow.ui \
    screenUi/ourteam.ui \
    screenUi/runwindow.ui \
    screenUi/settings.ui \
    screenUi/mainwindow.ui \
    src/missionpushbutton.ui

TRANSLATIONS += \
    src\lang\TomClock_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
