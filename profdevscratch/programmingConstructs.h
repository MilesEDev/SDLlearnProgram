#pragma once
#include "commandCat.h"
#include <string>
class programmingConstructs:public commandCat
{
public:
	/**
	 * .the run command format for programming constructs all constructs should use 
	 * 
	 */
	virtual void runCommand() = 0;

};

