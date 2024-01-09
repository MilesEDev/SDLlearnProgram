#pragma once
#include "programmingBodies.h"
#include "programmingConstructs.h"
#include "IArgManager.h"
#include "operators.h"
#include "executorManager.h"
class methodCommand :public programmingBodies, public programmingConstructs, public IArgManager, public executorManager
{
private:
	/**
	 * .these are the local arguments so that arguments can be used without being passed in func 
	 */
	std::vector<std::string> localArguments;
	

public:
	/**
	 * .this sets up the name of the command so it can be popped and also sets up the param count 
	 * 
	 */
	methodCommand();
	/**
	 * .this runs the command making sure that the function definition commands are not executed 
	 */

	void runCommand() override;
	/**
	 * .this puts the inputted arguments to local arguments so they can be used without func pass
	 * 
	 * \param commandArgs the arguments passed by user 
	 */
	void setAttributes(std::vector<std::string> commandArgs) override;
	/**
	 * .this performs a syntax check making sure the command name is valid 
	 * 
	 * \param commandArgs the argumnts passed by user 
	 * \return the succsess of the syntax check 
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs);


};

