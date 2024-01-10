#pragma once
#include <utility>      
#include <string>       
#include <iostream>     
#include <list>
#include <fstream>
#include "Commands.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include "renderTexture.h"
#include "Render.h"
#include "nonnumberexception.h"
#include "invalidParameters.h"
#include "nonfillvalue.h"
#include "notcolourexception.h"
#include "notcommandexception.h"
#include "commandFactory.h"
#include "commandCatFactory.h"
#include "commandCat.h"
#include "programmingConstructs.h"
#include "programmingConstructsFactory.h"
#include "programmingBodies.h"
#include "bodyEnd.h"
#include "MemoryManager.h"
#include "Expression.h"
#include "variableIsUndefined.h"
#include "Function.h"
#include "methodCommand.h"
#include <semaphore>
#include "SDL.h"
#include <thread>
#include "ThreadManager.h"
#include "unEndedBody.h"
#include "cannotEndBody.h"
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
	/**
	 * 
	 * .this is the line number for returning error 
	 */
	std::vector<programmingBodies*> bodyPCRs;
	/**
	 * .this is the line count 
	 */
	int line = 0;
	/**
	 * .this is the current memory to be used in execution
	 */
	MemoryManager* programMemory = new MemoryManager();
	/**
	 * .this is the list of old memories to be restored
	 */
	std::vector<MemoryManager*> oldMemory;
	/**
	 * .this is the call table containing all functions
	 */
	std::vector<Function*> callTable;
	/**
	 * .data checker for checking data
	 */
	dataChecker* myChecker = dataChecker::getInstance();
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
	std::string syntaxCheckAll();
	/**
	 * .runs all commands
	 * 
	 * \param myrenderer rendererer to use to run
	 * \param mytext texture to load rendering into 
	 * \return sdl texture
	 */
	std::pair < SDL_Texture*,std::string> runForAll(Render* myrenderer, SDL_Texture* mytext);
	/**
	 * .split line into arugments
	 * 
	 * \param line the line to split to arguments
	 */

	std::string runForAllThread(Render* myrenderer,std::binary_semaphore &sharedSema,Render* myThreadRenderer,std::binary_semaphore &mainToThread,ThreadManager* threadManager,int threadid);
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
	/**
	 * .this checks to see if a specific input is variable
	 * 
	 * \param command the command line with args to check for variables
	 * \param myManager the memory to use to check for existing pages
	 * \param inputIndex the index of the arg to check 
	 */
	void checkForVars(std::vector<std::string> &command, MemoryManager* myManager,int inputIndex);
	/**
	 * .checks if a specific input is a data value
	 * 
	 * \param command the command containing argumnets
	 * \param inputIndex the index for the specific argument to check
	 * \return whether a value was found
	 */
	bool checkForValue(std::vector<std::string> &command,int inputIndex);

	/**
	 * .this checks to see if any args are variables and transforms to values
	 * 
	 * \param command the command to check if arguments are variables in
	 * \param myManager the memory manager used to check for vars
	 */
	void checkForAll(std::vector<std::string> &command, MemoryManager* myManager);
	/**
	 * .check to see if a statement is a function
	 * 
	 * \param callTable the call table to check for functions
	 * \param funcStatement the statement that could be a function
	 * \return nullptr if no func found the relevant function pointer if func has been found
	 */
	Function* isFunc(std::vector<Function*> callTable,std::string funcStatement);


};

