#pragma once
#include <utility>      
#include <string>       
#include <iostream>     
#include <list>
#include "Commands.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include "renderTexture.h"
#include "Render.h"
#include "nonnumberexception.h"
#include "invalidParameters.h"
#include <iostream>
#include <fstream>
#include "triangleCommand.h"
#include "fillCommand.h"
#include "nonfillvalue.h"
#include "PosPencommand.h"
#include "clearcommand.h"
#include "colourCommand.h"
#include "notcolourexception.h"
#include "drawToCommand.h"
#include "resetCommand.h"
#include "notcommandexception.h"


/**
 * 
 * .parses the commands and runs them 
 * 
 */
class parser
{
private:
	/**
	 * .command arguments to be stored
	 */
	std::vector<std::string> arguments;
	/**
	 * .whole commands to be stored in neat string
	 */
	std::vector<std::vector<std::string>> commands;
	int line = 0;
public:
	/**
	 * .this is empty constructor
	 * 
	 */
	parser();
	/**
	 * .this splits the input into commands
	 * 
	 * \param program
	 */
	void splitToCommands(std::string program);
	/**
	 * . this clears all lists before running 
	 * 
	 */
	void clearAllLists();
	/**
	 * 
	 * .checks all commands for good syntax
	 * 
	 * \return success
	 */
	bool syntaxCheckAll();
	/**
	 * .runs all commands
	 * 
	 * \param myrenderer rendererer to use to run
	 * \param mytext texture to load rendering into 
	 * \return sdl texture
	 */
	SDL_Texture* runForAll(Render* myrenderer,SDL_Texture* mytext);
	/**
	 * .split line into arugments
	 * 
	 * \param line the line to split to arguments
	 */
	void splitToArguments(std::string line);
	/**
	 * .save program to a txt 
	 * 
	 * \param program name to load to write to 
	 */
	void saveToTxt(std::string program);
	/**
	 * .reads from a txt program 
	 * 
	 * \param programName name of program to read
	 * \return the return of the load
	 */
	std::string loadFromTxt(std::string programName);
	
	
	
	


	



};

