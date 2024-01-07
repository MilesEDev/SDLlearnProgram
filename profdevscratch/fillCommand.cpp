#include "fillCommand.h"

bool fillCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
    std::string onOrOff = commandArgs.at(0);
    if (SDL_strcasecmp(onOrOff.c_str(),"true") ==0|| SDL_strcasecmp(onOrOff.c_str(),"false")==0)
    {

        return true;
    }
    else
    {
        throw nonfillvalue("you have entered an incorrect value for fill please enter  true or false e.g fill true");
        return false;
    }



}

void fillCommand::setAttributes(std::vector<std::string> commandArgs)
{
    std::string onOrOff = commandArgs.at(0);
    if (SDL_strcasecmp(onOrOff.c_str(), "true") == 0) {

        fill = true;
    }
    else {
        fill = false;
    }
}

fillCommand::fillCommand()
{
    parameterno = 1;
}

std::string fillCommand::runCommand(Render* myrenderer, std::pair<float, float> Pen)
{
    myrenderer->setFill(fill);
    return(SDL_GetError());
}



