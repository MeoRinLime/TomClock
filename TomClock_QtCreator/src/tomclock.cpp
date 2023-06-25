#include "tomclock.h"

TomClock::TomClock(const QString &path)
{
    tcDatabase = new TomClockDatabase(path);
}
