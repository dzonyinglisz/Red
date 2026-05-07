#include "time.h"

TimeKeeper::TimeKeeper(int initTime)
{
    time = initTime;
}

TimeKeeper::~TimeKeeper()
{
}

void TimeKeeper::progressTime(float dt)
{
    time += (dt * speed) / 60;
}
