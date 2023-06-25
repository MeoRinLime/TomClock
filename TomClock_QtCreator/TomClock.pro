QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/about.cpp \
    src/settings.cpp \
    src/achievementwindow.cpp \
    src/createmissionwindow.cpp \
    src/historywindow.cpp \
    src/missionlistwindow.cpp \
    src/runwindow.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/about.h \
    src/settings.h \
    src/achievementwindow.h \
    src/createmissionwindow.h \
    src/historywindow.h \
    src/missionlistwindow.h \
    src/runwindow.h \
    src/mainwindow.h

FORMS += \
    screenUi/about.ui \
    screenUi/achievementwindow.ui \
    screenUi/createmissionwindow.ui \
    screenUi/historywindow.ui \
    screenUi/missionlistwindow.ui \
    screenUi/runwindow.ui \
    screenUi/settings.ui \
    screenUi/mainwindow.ui

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
