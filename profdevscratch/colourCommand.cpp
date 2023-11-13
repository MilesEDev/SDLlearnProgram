#include "colourCommand.h"

colourCommand::colourCommand()
{
    parameterno =1;
}

bool colourCommand::syntaxcheck(std::string colour)
{
    if (SDL_strcasecmp(colour.c_str(), "red") == 0 || SDL_strcasecmp(colour.c_str(), "green") == 0
    || SDL_strcasecmp(colour.c_str(), "blue") == 0 ||SDL_strcasecmp(colour.c_str(), "white") == 0) 
    {

        return true;
    }
    else
    {
        return false;
    }


}

void colourCommand::setCol(std::string colour)
{
    colours.clear();
    if(SDL_strcasecmp(colour.c_str(), "red") == 0)
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

std::string colourCommand::runCommand(Render* myrenderer)
{
    myrenderer->setPenColourRGBA(colours[0], colours[1], colours[2], colours[3]);
    return(SDL_GetError());

}
