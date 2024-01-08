#pragma once
#include "programmingBodies.h"
#include "programmingConstructs.h"
#include "IArgManager.h"
#include "operators.h"
#include "executorManager.h"
class ifCommand :public programmingBodies, public programmingConstructs, public IArgManager, public executorManager
{
private:
	std::vector<std::string> localArguments;
	comparator* myComparator = comparator::getInstance();

public:
	ifCommand();

	void runCommand() override;

	void setAttributes(std::vector<std::string> commandArgs) override;

	bool syntaxcheck(std::vector<std::string> commandArgs);


};
