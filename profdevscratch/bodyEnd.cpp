#include "bodyEnd.h"

std::vector<programmingBodies*> bodyEnd::popFromBodyList(std::vector<programmingBodies*> bodyPCRs)
{
    bodyPCRs.pop_back();
    return bodyPCRs;
}


void bodyEnd::setCurrentBodyPCR(std::vector<programmingBodies*> bodyPCRs)
{
    lastBodyPCR = bodyPCRs.back()->getProgramCounterPos();
}

int bodyEnd::getNewPCr(int pcr)
{
    if (this->newPCR > -1)
    {
        return newPCR;
    }
    else
    {
        return pcr; 
    }
}
