#include "whileCommand.h"

whileCommand::whileCommand() 
{
	commandName = "while";
	parameterno = 3;
}

void whileCommand::runCommand()
{
	comparator* myComparator = new comparator();

	if (myComparator->evaluateComparison(localArguments.at(0), localArguments.at(1), localArguments.at(2)))
	{
		localExecution = true;
	}
	else
	{
		localExecution = false;
	}

}

void whileCommand::setAttributes(std::vector<std::string> commandArgs)
{
	localArguments.push_back(commandArgs.at(0));
	localArguments.push_back(commandArgs.at(1));
	localArguments.push_back(commandArgs.at(2));
}

bool whileCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
	dataChecker* myChecker = new dataChecker();
	comparator* myComparator = new comparator();
	if (myComparator->validComparator(commandArgs.at(1)))
	{
		if (myChecker->isString(commandArgs.at(0)) && myChecker->isString(commandArgs.at(2)))
		{
			return true;
		}
		if (myChecker->isFloat(commandArgs.at(0)) && myChecker->isFloat(commandArgs.at(2)))
		{
			return true;
		}
		if (myChecker->isBool(commandArgs.at(0)) && myChecker->isBool(commandArgs.at(2)))
		{
			return true;
		}
	}
	return false;

}


