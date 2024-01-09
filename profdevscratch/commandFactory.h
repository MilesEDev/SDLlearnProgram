#pragma once
#include "Commands.h"
#include "drawToCommand.h"
#include "resetCommand.h"
#include "PosPencommand.h"
#include "clearcommand.h"
#include "colourCommand.h"
#include "circleCommand.h"
#include "rectangleCommand.h"
#include "triangleCommand.h"
#include "fillCommand.h"
class commandFactory
{
private:
	/**
	 * .the command factory constructor empty as no use 
	 * 
	 */
	commandFactory();
public:
	/**
	 * .the singleton instancee of the com factory
	 */
	static commandFactory* myComFactory;
	/**
	 * .this is used to get commands based on user input 
	 * 
	 * \param thisCommand the user input for command name
	 * \return  the command to be returned 
	 */
	Commands* getCommand(std::string thisCommand);
	/**
	 * . gets the instance of the commands factory 
	 * 
	 * \return the commandfactory instance
	 */
	static commandFactory* getInstance();
};

