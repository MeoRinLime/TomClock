#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <QString>

class Achievement
{
public:
    Achievement(QString name, bool state, QString howToAchieve);
    QString getName() const;
    void setName(const QString &newName);

    bool getState() const;
    void setState(bool newState);
    QString getHowToAchieve() const;
    void setHowToAchieve(const QString &newHowToAchieve);

private:
    QString name;
    bool state;
    QString howToAchieve;
};

#endif // ACHIEVEMENT_H
