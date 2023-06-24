#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <QString>

class Achievement
{
public:
    Achievement(QString name, bool state, QString howToAchieve);

    QString getName() const;//获取成就名

    void setName(const QString &newName);//设置成就名

    bool getState() const;//判断该成就是否处于获取状态

    void setState(bool newState);//设置成就是否处于获取状态

    QString getHowToAchieve() const;//获取获得该成就的条件

    void setHowToAchieve(const QString &newHowToAchieve);//设置获取该成就的条件

private:
    QString name;
    bool state;
    QString howToAchieve;
};

#endif // ACHIEVEMENT_H
