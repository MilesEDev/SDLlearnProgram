#pragma once
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
class drawToCommand : public Commands
{
private:
	float x;
	float y;
public:
	drawToCommand();
	bool syntaxcheck(std::string x, std::string y);

	void setPos(float x, float y);
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);

};

