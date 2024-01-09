#include "circleCommand.h"
#include "Render.h"


 
circleCommand::circleCommand()
{
	parameterno = 1;
}

bool circleCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
	//std::string breaktest = commandArgs.at(0);
	if (myChecker->isFloat(commandArgs.at(0))) {
		return true;
		
	}
	else
	{
		throw nonnumberexception("you have put in an incorrect data type for circleCommand please enter a float with the format(number)"
			"e.g circle 54");
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
