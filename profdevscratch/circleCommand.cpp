#include "circleCommand.h"
#include "Render.h"



circleCommand::circleCommand()
{
	parameterno = 1;
}

bool circleCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
	if (this->isFloat(commandArgs.at(0))) {
		return true;
		
	}
	else
	{
		throw nonnumberexception("you have entered a non number as a parameter for circle");
		return false;
	}
	
}

void circleCommand::setAttributes(std::vector<std::string> commandArgs)
{
	parsedAttributes.push_back(std::stoi(commandArgs.at(0)));
}

std::string circleCommand::runCommand(Render* renderer,std::pair<float,float> Pen)
{
	 
	renderer->drawShapeToText(new circle(Pen, parsedAttributes.at(0)));
	return SDL_GetError();
	

}
