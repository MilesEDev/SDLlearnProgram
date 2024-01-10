#include "endIf.h"


endIf::endIf()
{
    parameterno = 0;
}

bool endIf::checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs)
{
    if (bodyPCRs.back()->getName() == "if")
    {
        return true;
    }
    else
    {
        throw cannotEndBody("cannot end " + bodyPCRs.back()->getName() + "with endif");
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
