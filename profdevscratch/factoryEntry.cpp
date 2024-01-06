#include "factoryEntry.h"



factoryEntry::factoryEntry(std::vector<std::string> foreignKeys,programmingConstructs* thisPointer,std::string name) 
{
    this->foreignKeys = foreignKeys;
    this->thisPointer = thisPointer;
    this->name = name;
}
 

bool factoryEntry::hasKey(std::string keyToFind)
{
    for (std::string key : foreignKeys)
    {
        if (key == keyToFind)
        {
            return true;
        }
    }
    return false; 



        
}

std::string factoryEntry::getName()
{
    return name;
}

programmingConstructs* factoryEntry::getPointer()
{
    return thisPointer;
}
