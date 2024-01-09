#pragma once
#include "programmingConstructs.h"
#include "bodyEnd.h"
#include "executorManager.h"
#include "MemoryRestorer.h"

class endMethod :public programmingConstructs,public bodyEnd, public executorManager,public MemoryRestorer
{
public:
	endMethod();
	bool checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs) override;
	void runCommand() override;


};

