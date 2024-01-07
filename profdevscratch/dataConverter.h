#pragma once
#include <SDL_stdinc.h>
#include <string>
#include "specialChar.h"
class dataConverter
{
private:
    static dataConverter* myConverter;

    dataConverter();
    
public:
    bool stringToBool(std::string myStr);

    std::string boolToString(bool myBool);

    std::string sliceQoutes(std::string stringToSlice);

    std::string addQoutes(std::string stringToAdd);

    std::string removeSpecialChars(std::string stringToRemove);

    std::string doubleNegative(std::string argument);

    static dataConverter* getInstance();


};