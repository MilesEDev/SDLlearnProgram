#include "specialChar.h"

specialCharManager* specialCharManager::mySpecialManager = nullptr;

specialCharManager::specialCharManager() {}
std::string* specialCharManager::getSpecialChars()
{
    return specialChars;
}

std::string specialCharManager::getSingleSpecialChar(int iterator)
{
   std::string specialChar = specialChars[iterator];
   return specialChar;
}

int specialCharManager::getNumChars()
{
    return specialChars->size();
}

specialCharManager* specialCharManager::getInstance()
{
	if (mySpecialManager == nullptr)
	{
		mySpecialManager = new specialCharManager;
	}
	return mySpecialManager;
	

}
