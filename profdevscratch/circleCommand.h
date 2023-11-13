#pragma once
#include "Commands.h";
#include <string>       
#include <iostream>   
#include "Render.h"
#include "eventfactory.h"
#include "shape.h"
#include "circle.h"
class circleCommand:public Commands
{
private:
	float radius;
public:
	circleCommand();

	bool syntaxcheck(std::string radius);

	std::string runCommand(Render* renderer, std::pair<float, float> Pen);
	
	void setRadius(float newRadius);


};

