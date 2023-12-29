#include "commandFactory.h"

Commands* commandFactory::getCommand(std::string thisCommand)
{
	if (thisCommand == "circle") 
	{
		return new circleCommand();
	}
	if (thisCommand == "triangle")
	{
		return new triangleCommand();

	}
	if (thisCommand == "clear")
	{
		return new clearcommand();
	}
	if (thisCommand == "colour")
	{
		return new colourCommand();
	}
	if (thisCommand == "drawto")
	{
		return new drawToCommand();
	}
	if (thisCommand == "fill")
	{
		return new fillCommand();
	}
	if (thisCommand == "pospen")
	{
		return new PosPencommand();
	}
	if (thisCommand == "rectangle")
	{
		return new rectangleCommand(); 
	}
	if (thisCommand == "reset")
	{
		return new rectangleCommand(); 
	}
	
}
