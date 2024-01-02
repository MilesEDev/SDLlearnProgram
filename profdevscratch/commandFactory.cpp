#include "commandFactory.h"

Commands* commandFactory::getCommand(std::string thisCommand)
{
	if (SDL_strcasecmp(thisCommand.c_str(),"circle")==0)
	{
		return new circleCommand();
	}
	else if(SDL_strcasecmp(thisCommand.c_str(), "triangle")==0)
	{
		return new triangleCommand();

	}
	else if (SDL_strcasecmp(thisCommand.c_str(), "clear")==0)
	{
		return new clearcommand();
	}
	else if (SDL_strcasecmp(thisCommand.c_str(), "colour")==0)
	{
		return new colourCommand();
	}
	else if (SDL_strcasecmp(thisCommand.c_str(), "drawto")==0)
	{
		return new drawToCommand();
	}
	else if (SDL_strcasecmp(thisCommand.c_str(), "fill")==0)
	{
		return new fillCommand();
	}
	else if (SDL_strcasecmp(thisCommand.c_str(), "pospen")==0)
	{
		return new PosPencommand();
	}
	else if (SDL_strcasecmp(thisCommand.c_str(), "rectangle")==0)
	{
		return new rectangleCommand(); 
	}
	else if (SDL_strcasecmp(thisCommand.c_str(), "reset")==0)
	{
		return new rectangleCommand(); 
	}
	
}
