#pragma once
#include "Commands.h"
#include <string>
#include "rectangle.h"
#include "Render.h"
class rectangleCommand:public Commands
{
public:
	float width = 0;
	float height = 0;
	rectangleCommand();

	bool syntaxcheck(std::string height,std::string width);

	void setRectDimensions(float width,float height);

	std::string runCommand(Render* renderer, std::pair<float, float> Pen);
	


};

