#include "triangleCommand.h"

triangleCommand::triangleCommand()
{
	parameterno = 4;
}

bool triangleCommand::syntaxcheck(std::string x1, std::string y1, std::string x2, std::string y2)
{
	bool error = false;
	if (!this->isFloat(x1)) 
	{
		error = true;
	}
	if (!this->isFloat(y1)) 
	{
		error = true;
	}
	if (!this->isFloat(x2))
	{
		error = true;
	}
	if (!this->isFloat(y2))
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
