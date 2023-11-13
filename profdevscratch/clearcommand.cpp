#include "clearcommand.h"

clearcommand::clearcommand()
{
    parameterno = 0;
}

std::string clearcommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
   
    renderer->renderClear();
    return(SDL_GetError());
}
