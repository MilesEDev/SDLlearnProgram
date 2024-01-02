#include "rectangleCommand.h"


rectangleCommand::rectangleCommand()
{
	parameterno = 2;
}

bool rectangleCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
	bool error = false;

	for (int i = 0; i < 2; i++)	{

		if (myChecker->isFloat(commandArgs.at(i))) 
		{

		}
		else
		{
			throw nonnumberexception("you have put in an incorrect data type for rectangleCommand please enter a float with the format(number)"
				"e.g rectangle 50 50");
			error = true;
		}
	}
	return !error;
}

void rectangleCommand::setAttributes(std::vector<std::string> commandArgs) 
{
	for (int i = 0; i < 2; i++)
	{
		parsedAttributes.push_back(std::stoi(commandArgs.at(i)));
	}
}


std::string rectangleCommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->drawShapeToText(new rectangle(parsedAttributes.at(0),parsedAttributes.at(1), Pen));
	return(SDL_GetError());
}
