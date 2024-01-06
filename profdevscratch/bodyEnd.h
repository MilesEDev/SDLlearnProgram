#pragma once
#include <vector>
#include <string>
#include "programmingBodies.h"
class bodyEnd
{
protected:
	int newPCR = -1;
	int lastBodyPCR = 0;
public:
	std::vector<programmingBodies*> popFromBodyList(std::vector<programmingBodies*> bodyPCRs);

	virtual bool checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs) =0 ;

	void setCurrentBodyPCR(std::vector<programmingBodies*> bodyPCRs);
		
	int getNewPCr(int pcr);
};

