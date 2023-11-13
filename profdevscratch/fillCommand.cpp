#include "fillCommand.h"

fillCommand::fillCommand()
{
    parameterno = 1;
}

void fillCommand::setFill(std::string onOrOff)
{
    if (SDL_strcasecmp(onOrOff.c_str(), "on") ==0) {

        fill = true;
    }
    else {
        fill = false;
    }
}

bool fillCommand::syntaxcheck(std::string onOrOff)
{
    
    if (SDL_strcasecmp(onOrOff.c_str(), "on") ==0 || SDL_strcasecmp(onOrOff.c_str(), "off") ==0) {

        return true;
    }
    else
    {
        return false; 
    }

    

}

void fillCommand::runCommand(Render* myrenderer)
{
    myrenderer->setFill(fill);
}
