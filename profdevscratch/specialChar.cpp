#include "specialChar.h"

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
