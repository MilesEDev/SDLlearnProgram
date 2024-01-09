#include "programmingBodies.h"

int programmingBodies::getProgramCounterPos()
{
    return thisProgramCounterPos;
}

void programmingBodies::setProgramCounterPos(int pcr)
{
    this->thisProgramCounterPos = pcr;
}

std::string programmingBodies::getName()
{
    return commandName;
}
