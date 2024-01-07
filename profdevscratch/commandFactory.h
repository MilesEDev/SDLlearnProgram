#pragma once
#include "Commands.h"
#include "drawToCommand.h"
#include "resetCommand.h"
#include "PosPencommand.h"
#include "clearcommand.h"
#include "colourCommand.h"
#include "circleCommand.h"
#include "rectangleCommand.h"
#include "triangleCommand.h"
#include "fillCommand.h"
class commandFactory
{
private:
	commandFactory();
public:
	static commandFactory* myComFactory;
	Commands* getCommand(std::string thisCommand);
	static commandFactory* getInstance();
};

