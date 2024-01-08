#include "endIf.h"


endIf::endIf()
{
    parameterno = 0;
}

bool endIf::checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs)
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

void endIf::runCommand()
{
    if (localExecution == false)
    {
        localExecution = true;
    }
    else
    {
        localExecution = false;
    }
}
