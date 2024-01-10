#include "endMethod.h"


endMethod::endMethod()
{
    parameterno = 0;
}

bool endMethod::checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs)
{
    if (bodyPCRs.back()->getName() == "method")
    {
        return true;
    }
    else
    {
        throw cannotEndBody("cannot end " + bodyPCRs.back()->getName() + "with endmethod");
    }
}

void endMethod::runCommand()
{
    if (localExecution == false)
    {
        newPCR = -1;
        localExecution = true;
    
    }
    else
    {
        newPCR = lastBodyPCR;
      
    }
    clearNewmemory = true;
    restoreOldMemory = true;
}
