#include "circleCommand.h"
#include "Render.h"



circleCommand::circleCommand()
{
	parameterno = 1;
}

bool circleCommand::syntaxcheck(std::string radius)
{
	if (this->isFloat(radius)) {
		this->radius = std::stof(radius);
		return true;
		
	}
	else
	{
		return false;
	}
	
}

std::string circleCommand::runCommand(Render* renderer,std::pair<float,float> Pen)
{
	 
	renderer->drawShapeToText(new circle(Pen, this->radius));
	return SDL_GetError();
	

}
void circleCommand::setRadius(float newRadius) 
{

	radius = newRadius;
}
