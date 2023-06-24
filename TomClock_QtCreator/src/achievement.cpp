#include "achievement.h"

Achievement::Achievement(QString name, bool state, QString howToAchieve)
{
    setName(name);
    setState(state);
    setHowToAchieve(howToAchieve);
}

QString Achievement::getName() const
{
    return name;
}

void Achievement::setName(const QString &newName)
{
    name = newName;
}

bool Achievement::getState() const
{
    return state;
}

void Achievement::setState(bool newState)
{
    state = newState;
}

QString Achievement::getHowToAchieve() const
{
    return howToAchieve;
}

void Achievement::setHowToAchieve(const QString &newHowToAchieve)
{
    howToAchieve = newHowToAchieve;
}
