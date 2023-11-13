#include "rectangleCommand.h"


rectangleCommand::rectangleCommand()
{
	parameterno = 2;
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

void rectangleCommand::setRectDimensions(float width, float height)
{
	this->width = width;
	this->height = height;
		

}

void rectangleCommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->drawShapeToText(new rectangle(height,width,Pen));
}
