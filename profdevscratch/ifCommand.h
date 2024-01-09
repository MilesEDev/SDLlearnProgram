#pragma once
#include "programmingBodies.h"
#include "programmingConstructs.h"
#include "IArgManager.h"
#include "operators.h"
#include "executorManager.h"
class ifCommand :public programmingBodies, public programmingConstructs, public IArgManager, public executorManager
{
private:
	/**
	 * .the local arguments to be used for the comparisons 
	 */
	std::vector<std::string> localArguments;
	/**
	 * .comparator to perform comparisons
	 */
	comparator* myComparator = comparator::getInstance();

public:
	/**
	 * .the constructor for if command setting up the name so that it can be checked from the body and 
	 * also adding the param count 
	 * 
	 */
	ifCommand();
	/**
	 * .this runs the if command setting execution depending on result of the condition 
	 * 
	 */
	void runCommand() override;
	/**
	 * .this adds the the arguments from user to local arguments to that arguments can be used outside of being passed
	 * to function 
	 * 
	 * \param commandArgs the arguments from user 
	 */
	void setAttributes(std::vector<std::string> commandArgs) override;
	/**
	 * .this performs a syntax check to make sure that the inputs are indeed data values 
	 * 
	 * \param commandArgs the arguments passed by user 
	 * \return this returns the succsesss of the syntax check 
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs);


};
