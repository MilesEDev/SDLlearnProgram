#pragma once
#include "programmingConstructs.h"
#include <SDL_stdinc.h>
#include "whileCommand.h"
#include "factoryEntry.h"
#include "endWhile.h"
#include "ifCommand.h"
#include "endif.h"
#include "methodCommand.h"
#include "endMethod.h"
class programmingConstructsFactory
{
private:
	/**
	 * .all the factory entires for programming constrcuts
	 */
	std::vector<factoryEntry*> factoryEntries;
	/**
	 * .the instance of the programmingconstructfactory for singleton pattenr 
	 */
	static programmingConstructsFactory* myProgConFactory;
	/**
	 * .the constrcutor for programmingconsrcuts factory used to set up all the construct entries
	 * 
	 */
	programmingConstructsFactory();
public:
	/**
	 * .this obtains the programming construct linked to the user input for name of the command 
	 * 
	 * \param thisCommand the pointer for the command entry so keys and pointer to specific command can be gathered
	 * \return the factory entry linked to user input
	 */
	factoryEntry* getCommand(std::string thisCommand);
	/**
	 * .obtains the pointer after running the getcommand so that only the pointer is returned no whole entry 
	 * 
	 * \param thisCommand the name of the command to gather pointer for 
	 * \return the pointer of the command 
	 */
	programmingConstructs* getPointer(std::string thisCommand);
	/**
	 * .this is used so that has key can be called from the factory not just from individual entry 
	 * it checks to see if a key matches in the factory entry so command manager commands can be run 
	 * 
	 * \param thisCommand the name of commmand key is to be searched for in 
	 * \param key the key for the command manager
	 * \return whether the key has been found 
	 */
	bool hasKey(std::string thisCommand,std::string key);
	/**
	 * .this populates all the factory entries
	 * 
	 */
	void populateFactoryEntries();

	/**
	 * .this gets the single instance of programmingconstructsfactory 
	 * 
	 * \return the singleton instance 
	 */
	static programmingConstructsFactory* getInstance();

};


