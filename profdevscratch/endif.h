#pragma once
#include "programmingConstructs.h"
#include "bodyEnd.h"
#include "executorManager.h"

class endIf :public programmingConstructs,public bodyEnd, public executorManager
{
public:
	endIf();
	bool checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs) override;
	void runCommand() override;


};

