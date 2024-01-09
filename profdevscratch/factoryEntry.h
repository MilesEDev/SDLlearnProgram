#pragma once
#include "programmingConstructs.h"
class factoryEntry
{
private:
	/**
	 * .this stores all the manager supporting classes used in a command
	 */
	std::vector<std::string> foreignKeys;
	/**
	 * .this stores a pointer for a programming construct so that a name can be derived from it and such
	 */
	programmingConstructs* thisPointer;
	/**
	 * .this is the name to be set for a specific command so it can link to user input 
	 */
	std::string name;

public:
	/**
	 * .this sets up all the factory entry attributes
	 * 
	 * \param foreignKeys the supporting classes that this command uses
	 * \param thisPointer the pointer that this command will return
	 * \param name the name of this command 
	 */
	factoryEntry(std::vector<std::string> foreignKeys, programmingConstructs* thisPointer, std::string name);

	/**
	 * .checks to see if this command posses a speciifc supporting class so it can be polymorphed to that4
	 * supporting class pointer
	 * 
	 * \param keyToFind the supporting class key to find 
	 * \return the succesfullness of whether the key could be foun d
	 */
	bool hasKey(std::string keyToFind);
	/**
	 * .this returns the name of the command 
	 */
	std::string getName(); 
	/**
	 * .this returns the pointer for this command 
	 * 
	 * \return 
	 */
	programmingConstructs* getPointer();
};

