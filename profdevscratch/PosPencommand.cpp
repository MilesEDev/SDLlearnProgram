#include "PosPencommand.h"


PosPencommand::PosPencommand() 
{

	parameterno = 2;
}

bool PosPencommand::syntaxcheck(std::vector<std::string> commandArgs)
{
	bool error = false;
	for (int i = 0; i < 2; i++)
	{
		if (myChecker->isFloat(commandArgs.at(i))) 
		{

		}
		else
		{
			error = true;
		}
		
	}
	return !error;
	
}

void PosPencommand::setAttributes(std::vector<std::string> commandArgs)
{
	for (int i = 0; i < 2; i++)
	{
		parsedAttributes.push_back(std::stoi(commandArgs.at(i)));
	}
}




std::string PosPencommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->setPen(parsedAttributes.at(0), parsedAttributes.at(1));
	return SDL_GetError();
}


