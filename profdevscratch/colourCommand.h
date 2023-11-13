#pragma once
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
class colourCommand : public Commands

{
private:
	std::vector<Uint8> colours;


public:

	colourCommand();

	bool syntaxcheck(std::string colour);
	void setCol(std::string colour);
	std::string runCommand(Render* myrenderer);


};

