#pragma once
#include "programmingConstructs.h"
#include <SDL_stdinc.h>
#include "whileCommand.h"
#include "factoryEntry.h"
#include "endWhile.h"
class programmingConstructsFactory
{
private:
	std::vector<factoryEntry*> factoryEntries;
	
public:

	programmingConstructsFactory();

	factoryEntry* getCommand(std::string thisCommand);

	programmingConstructs* getPointer(std::string thisCommand);

	bool hasKey(std::string thisCommand,std::string key);

	void populateFactoryEntries();

};

