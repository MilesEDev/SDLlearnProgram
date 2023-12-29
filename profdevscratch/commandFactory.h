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
public:
	Commands* getCommand(std::string thisCommand);
};

