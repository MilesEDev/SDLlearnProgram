#pragma once
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
class resetCommand: public Commands
{
public:
	resetCommand();
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);



};

