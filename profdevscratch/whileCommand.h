#pragma once
#include "programmingBodies.h"
#include "programmingConstructs.h"
#include "IArgManager.h"
#include "operators.h"
#include "executorManager.h"
class whileCommand :public programmingBodies,public programmingConstructs,public IArgManager,public executorManager
{
private:
	/**
	 * .local arguments to be used so arguments can be referanced without func pass 
	 */
	std::vector<std::string> localArguments;
	/**
	 * .comparator to be used that can conditions can be processed
	 */
	comparator* myComparator = comparator::getInstance();

public:
	/**
	 * .this is the while command constructor this sets the name of the command so that it can be popped
	 * and also sets up the param count for this command 
	 * 
	 */
	whileCommand();

	/**
	 * .this runs the command so it knows if it should continue running the loop or stop running it 
	 * 
	 */
	void runCommand() override;
	/**
	 * .this sets the local arguments variable to so that arguments can be referanced without func pass
	 * 
	 * \param commandArgs these are the command args to be passed and have local arguments set to 
	 */
	void setAttributes(std::vector<std::string> commandArgs) override;

	/**
	 * 
	 * .this performs a syntax check on arguments to make sure that they are of correct type and format in this case
	 * make sure that arguments are data values and valid operators 
	 * 
	 * \param commandArgs the command args to be syntax checked
	 * \return the successes of the syntax check 
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs);


};

