#pragma once
#include <string>
#include <iostream>   
#include "commands.h"
#include "Render.h"
class PosPencommand :public Commands
{

	float x = 0;
	float y = 0;
public:
	PosPencommand();

	bool syntaxcheck(std::string x, std::string y);
	void setPoints(float newx1, float newx2);
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);

};

