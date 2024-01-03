#include "circleCommand.h"
int circleRun()
{
	circleCommand* myCircCommand = new circleCommand();
	Render* myRenderer = new Render();
	myCircCommand->runCommand(myRenderer,myRenderer->getPen());
	return 0;
};
