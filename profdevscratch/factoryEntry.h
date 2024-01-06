#pragma once
#include "programmingConstructs.h"
class factoryEntry
{
private:
	
	std::vector<std::string> foreignKeys;
	programmingConstructs* thisPointer;
	std::string name;

public:
	factoryEntry(std::vector<std::string> foreignKeys, programmingConstructs* thisPointer, std::string name);

	bool hasKey(std::string keyToFind);

	std::string getName(); 

	programmingConstructs* getPointer();
};

