#include "dataConverter.h"


bool dataConverter::stringToBool(std::string myStr)
{
    
    if (SDL_strcasecmp(myStr.c_str(), "true"))
    {
        return true;
    }
    else if (SDL_strcasecmp(myStr.c_str(), "false"))
    {
        return false;
    }
    else
    {

    }
    
}

std::string dataConverter::boolToString(bool myBool)
{
    if (myBool) 
    {
        return "true";;
    }
    else
    {
        return "false";
    }
}

std::string dataConverter::sliceQoutes(std::string stringToSlice)
{
    return stringToSlice.substr(1, stringToSlice.size()-2);
}

std::string dataConverter::addQoutes(std::string stringToAdd)
{
    return "\"" + stringToAdd + "\"";
}
