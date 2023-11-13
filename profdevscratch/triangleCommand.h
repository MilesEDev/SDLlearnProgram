#pragma once
#include <string>       
#include <iostream>   
#include "commands.h"
#include "Render.h"
class triangleCommand:public Commands
{


	float x1 = 0;
	float x2 = 0;
	float y1 = 0;
	float y2 = 0;
public:
	triangleCommand();
	
	bool syntaxcheck(std::string x1, std::string y1, std::string x2, std::string y2);

	void setPoints(float newx1, float newx2, float newy1, float newy2);

	void runCommand(Render* renderer, std::pair<float, float> Pen);


};

