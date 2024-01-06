#pragma once
#include "commandCat.h"
class commandCatFactory
{
public:
	commandCat* getCommand(std::string thisCommand);
};

