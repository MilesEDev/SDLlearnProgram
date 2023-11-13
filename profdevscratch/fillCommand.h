#pragma once
#include <string>
#include "SDL.h"
#include "Commands.h"
#include "Render.h"
class fillCommand : public Commands

{
	
private:
	bool fill = false;
public: 



	fillCommand();

	void setFill(std::string onOrOff);
	bool syntaxcheck(std::string onOrOff);

	std::string runCommand(Render* myrenderer);


	
};

