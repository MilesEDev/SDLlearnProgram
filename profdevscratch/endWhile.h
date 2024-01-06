#pragma once
#include "programmingConstructs.h"
#include "bodyEnd.h"
#include "executorManager.h"

class endWhile :public programmingConstructs,public bodyEnd,public executorManager
{
public:
	endWhile();
	bool checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs) override;
	void runCommand() override;


};

