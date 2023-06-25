#ifndef TOMCLOCK_H
#define TOMCLOCK_H

#include "tomclockdatabase.h"
#include <QString>

class TomClock
{
public:
    TomClock(const QString &path);
private:
    TomClockDatabase *tcDatabase;
};

#endif // TOMCLOCK_H
