#ifndef TOMCLOCK_H
#define TOMCLOCK_H

#include "tomclockdatabase.h"
#include <QString>

class TomClock
{
public:
    TomClock();
private:
    TomClockDatabase *tcDatabase;
};

#endif // TOMCLOCK_H
