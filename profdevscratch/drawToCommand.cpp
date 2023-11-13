#include "drawToCommand.h"

drawToCommand::drawToCommand()
{
	parameterno = 2;
}

bool drawToCommand::syntaxcheck(std::string x, std::string y)
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

void drawToCommand::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

std::string drawToCommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->drawTo(this->x, this->y);
	return(SDL_GetError());
}

