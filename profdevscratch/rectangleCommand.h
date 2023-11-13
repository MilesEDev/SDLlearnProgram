#pragma once
#include "Commands.h"
#include <string>
class rectangleCommand:public Commands
{
public:
	rectangleCommand();

	bool syntaxcheck(std::string height,std::string width);

};

