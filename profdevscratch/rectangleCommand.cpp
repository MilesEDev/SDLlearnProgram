#include "rectangleCommand.h"


rectangleCommand::rectangleCommand()
{
	
}

bool rectangleCommand::syntaxcheck(std::string height, std::string width)
{
	bool error = false;
	if (!this->isFloat(height)) 
	{
		error = true;
	}
	if (!this->isFloat(width))
	{
		error = true;
	}
	if (error)
	{
		return false;
	}
	else 
	{
		return true;
	}
}
