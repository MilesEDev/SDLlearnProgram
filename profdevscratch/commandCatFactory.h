#pragma once
#include "commandCat.h"
class commandCatFactory
{
public:
	/**
	 * .gets the command object required based on user input of command name 
	 * 
	 * \param thisCommand the command name input by user
	 * \return the pointer for the command or nullptr if none could be found 
	 */
	commandCat* getCommand(std::string thisCommand);
};

