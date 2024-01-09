#include "endWhile.h"


endWhile::endWhile()
{
    parameterno = 0;
}

bool endWhile::checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs)
{
    if (bodyPCRs.back()->getName() == "while")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void endWhile::runCommand()
{
    if (localExecution == false)
    {
        newPCR = -1;
        localExecution = true;
    }
    else
    {
        newPCR = lastBodyPCR;
        localExecution = true;
    }
}
