#include "methodCommand.h"

methodCommand::methodCommand()
{
	commandName = "method";
	parameterno = 1;
}

void methodCommand::runCommand()
{

	localExecution = false; 

}

void methodCommand::setAttributes(std::vector<std::string> commandArgs)
{
	localArguments.clear();
	localArguments.push_back(commandArgs.at(0));
	
}

bool methodCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
	
	std::string funcName = myChecker->readFuncName(commandArgs.at(0));


	if (commandArgs.at(0)[funcName.size()] == '(' && commandArgs.at(0)[commandArgs.at(0).size() - 1] == ')')
	{
		return true;
	}
	else
	{
		return false;
	}


}



