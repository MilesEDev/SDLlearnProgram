#include "colourCommand.h"

colourCommand::colourCommand()
{
    parameterno =1;
}

bool colourCommand::syntaxcheck(std::vector<std::string> commandArgs)
{
  
    dataConverter* myConverter = new dataConverter(); 
    dataChecker* myChecker = new dataChecker(); 
    std::string colour = commandArgs.at(0);
    if (!myChecker->isString(colour))
    {
        throw nonStringException("you have put in an incorrect data type for colourCommand please enter a string with the format (\"textinput\")"
            "e.g colour \"black\"");

    }
    colour = myConverter->sliceQoutes(colour);
    if (SDL_strcasecmp(colour.c_str(), "red") == 0 || SDL_strcasecmp(colour.c_str(), "green") == 0
        || SDL_strcasecmp(colour.c_str(), "blue") == 0 || SDL_strcasecmp(colour.c_str(), "white") == 0)
    {
        return true;
    }
    else
    {
        throw notcolourexception("you have submitted an input that is not a supported colour please enter either red blue green or white");
        return false;
    }
}

void colourCommand::setAttributes(std::vector<std::string> commandArgs)
{
    std::string colour = commandArgs.at(0);
    colours.clear();
    if (SDL_strcasecmp(colour.c_str(), "red") == 0)
    {
        colours.push_back(255);
        colours.push_back(0);
        colours.push_back(0);
        colours.push_back(255);
    }
    if (SDL_strcasecmp(colour.c_str(), "green") == 0)
    {
        colours.push_back(0);
        colours.push_back(255);
        colours.push_back(0);
        colours.push_back(255);
    }
    if (SDL_strcasecmp(colour.c_str(), "blue") == 0)
    {
        colours.push_back(0);
        colours.push_back(0);
        colours.push_back(255);
        colours.push_back(255);
    }
    if (SDL_strcasecmp(colour.c_str(), "white") == 0)
    {
        colours.push_back(255);
        colours.push_back(255);
        colours.push_back(255);
        colours.push_back(255);
    }

}




std::string colourCommand::runCommand(Render* myrenderer, std::pair<float, float> Pen)
{
    myrenderer->setPenColourRGBA(colours[0], colours[1], colours[2], colours[3]);
    return(SDL_GetError());

}
