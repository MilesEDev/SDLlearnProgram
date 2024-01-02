#pragma once
#include <SDL_stdinc.h>
#include <string>
class dataConverter
{
public:
    bool stringToBool(std::string myStr);

    std::string boolToString(bool myBool);

    std::string sliceQoutes(std::string stringToSlice);

    std::string addQoutes(std::string stringToAdd);

    

};