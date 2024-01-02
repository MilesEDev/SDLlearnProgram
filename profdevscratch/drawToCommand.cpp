#include "drawToCommand.h"

drawToCommand::drawToCommand()
{
	parameterno = 2;
}

bool drawToCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
	bool error = false;
	if (!myChecker->isFloat(commandArgs.at(0)))
	{
		error = true;
	}
	if (!myChecker->isFloat(commandArgs.at(1)))
	{
		error = true;
	}
	if (error)
	{
		throw nonnumberexception("you have put in an incorrect data type for drawtoCommand please enter a float with the format(number)"
			"e.g drawto 50 50");
		return false;

	}
	else
	{
		return true;
	}
}

void drawToCommand::setAttributes(std::vector<std::string> commandArgs)
{
	parsedAttributes.push_back(std::stoi(commandArgs.at(0)));
	parsedAttributes.push_back(std::stoi(commandArgs.at(1)));
}


std::string drawToCommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->drawTo(parsedAttributes.at(0),parsedAttributes.at(1));
	return(SDL_GetError());
}

