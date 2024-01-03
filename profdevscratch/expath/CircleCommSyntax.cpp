
#include "circleCommand.h"
int CircComTestSyntax()
{
	circleCommand* myCircCommand = new circleCommand();
	std::vector<std::string> commandArgs;
	commandArgs.push_back("50");
	myCircCommand->syntaxcheck(commandArgs);
	return 0;
}
