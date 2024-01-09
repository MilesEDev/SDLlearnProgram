#include "programmingConstructsFactory.h"

//could use sets
programmingConstructsFactory* programmingConstructsFactory::myProgConFactory = nullptr;




programmingConstructsFactory::programmingConstructsFactory()
{
	populateFactoryEntries();
}

factoryEntry* programmingConstructsFactory::getCommand(std::string thisCommand)
{
	for (factoryEntry* entry : factoryEntries) 
	{
		if (SDL_strcasecmp(thisCommand.c_str(), entry->getName().c_str()) == 0)
		{
			return entry;
		}
	}
	return nullptr;
}

programmingConstructs* programmingConstructsFactory::getPointer(std::string thisCommand)
{
	factoryEntry* entry = getCommand(thisCommand);
	if (entry != nullptr)
	{
		return entry->getPointer();
	}
	else
	{
		return nullptr;
	}
}

bool programmingConstructsFactory::hasKey(std::string thisCommand,std::string key)
{
	factoryEntry* entry = getCommand(thisCommand);
	if (entry != nullptr) 
	{
		return entry->hasKey(key);
	}
	else
	{
		return false;
	}
}

void programmingConstructsFactory::populateFactoryEntries()
{
	std::vector<std::string> foreignKeys = {"body","execute"};
	factoryEntries.push_back(new factoryEntry(foreignKeys,new whileCommand(),"while"));
	foreignKeys = { "bodyend","execute" };
	factoryEntries.push_back(new factoryEntry(foreignKeys, new endWhile(), "endwhile"));
	foreignKeys = { "body","execute" };
	factoryEntries.push_back(new factoryEntry(foreignKeys, new ifCommand(), "if"));
	foreignKeys = { "bodyend","execute" };
	factoryEntries.push_back(new factoryEntry(foreignKeys, new endIf(), "endif"));
	foreignKeys = { "body","execute" };
	factoryEntries.push_back(new factoryEntry(foreignKeys, new methodCommand(), "method"));
	foreignKeys = { "bodyend","execute","memory"};
	factoryEntries.push_back(new factoryEntry(foreignKeys, new endMethod(), "endmethod"));
	
	

}

programmingConstructsFactory* programmingConstructsFactory::getInstance()
{
	if (programmingConstructsFactory::myProgConFactory == nullptr)
	{
		programmingConstructsFactory::myProgConFactory = new programmingConstructsFactory();
	}
	return programmingConstructsFactory::myProgConFactory;
}
