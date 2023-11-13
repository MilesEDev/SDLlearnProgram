#include "PosPencommand.h"


PosPencommand::PosPencommand() 
{

	parameterno = 2;
}

bool PosPencommand::syntaxcheck(std::string x, std::string y)
{
	bool error = false;
	if (!this->isFloat(x))
	{
		error = true;
	}
	if (!this->isFloat(y))
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

void PosPencommand::setPoints(float newx, float newy)
{
	x = newx;
	y = newy;

}

std::string PosPencommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->setPen(x, y);
	return SDL_GetError();
}


