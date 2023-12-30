#include "triangleCommand.h"

triangleCommand::triangleCommand()
{
	parameterno = 4;
}



bool triangleCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
	bool error = false;
	for (int i = 0; i < 4; i++)
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

void triangleCommand::setAttributes(std::vector<std::string> commandArgs)
{
	for (int i = 0; i < 4; i++)
	{
		parsedAttributes.push_back(std::stoi(commandArgs.at(i)));
	}
}


std::string triangleCommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->drawShapeToText(new triangle(Pen.first,Pen.second,x1,y1,x2,y2));
	return SDL_GetError();
}

