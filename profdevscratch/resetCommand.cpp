#include "resetCommand.h"


resetCommand::resetCommand()
{
	parameterno = 0;
}

std::string resetCommand::runCommand(Render* renderer, std::pair<float, float> Pen)
{
	renderer->setPen(0,0);
	return(SDL_GetError());
}
