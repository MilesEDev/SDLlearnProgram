#pragma once
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
/**
 * .a bridge between render and user to reset pen position 
 */
class resetCommand: public Commands
{
public:
	/**
	 * .the number of parameters to take in set by constructor
	 * 
	 */
	resetCommand();
	/**
	 * .the function to run the command
	 * 
	 * \param renderer render to use to run command 
	 * \param Pen kept for possible future inheritance with command class
	 * \return sdl error 
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);



};

