#pragma once
#include <string>       
#include <iostream>   
#include "commands.h"
class triangleCommand:public Commands
{
public:
	triangleCommand();
	
	bool syntaxcheck(std::string x1, std::string y1, std::string x2, std::string y2);



};

