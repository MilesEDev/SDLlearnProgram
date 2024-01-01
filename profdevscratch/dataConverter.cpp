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
