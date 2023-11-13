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

void triangleCommand::setPoints(float newx1, float newx2, float newy1, float newy2)
{
	x1 = newx1;
	x2 = newx2;
	y1 = newy1;
	y2 = newy2;

}
void triangleCommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->drawShapeToText(new triangle(Pen.first,Pen.second,x1,y1,x2,y2));
}

