#include "commandFactory.h"

Commands* commandFactory::getCommand(std::string thisCommand)
{
	if (SDL_strcasecmp(thisCommand.c_str(),"circle"))
	{
		return new circleCommand();
	}
	if (SDL_strcasecmp(thisCommand.c_str(), "triangle"))
	{
		return new triangleCommand();

	}
	if (SDL_strcasecmp(thisCommand.c_str(), "clear"))
	{
		return new clearcommand();
	}
	if (SDL_strcasecmp(thisCommand.c_str(), "colour"))
	{
		return new colourCommand();
	}
	if (SDL_strcasecmp(thisCommand.c_str(), "drawto"))
	{
		return new drawToCommand();
	}
	if (SDL_strcasecmp(thisCommand.c_str(), "fill"))
	{
		return new fillCommand();
	}
	if (SDL_strcasecmp(thisCommand.c_str(), "pospen"))
	{
		return new PosPencommand();
	}
	if (SDL_strcasecmp(thisCommand.c_str(), "rectangle"))
	{
		return new rectangleCommand(); 
	}
	if (SDL_strcasecmp(thisCommand.c_str(), "reset"))
	{
		return new rectangleCommand(); 
	}
	
}
