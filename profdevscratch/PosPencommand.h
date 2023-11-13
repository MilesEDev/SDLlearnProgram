#pragma once
#include <string>
#include <iostream>   
#include "commands.h"
#include "Render.h"
/**
 * .a bridge between user input and setting pen position
 */
class PosPencommand :public Commands
{
	/**
	 * .pos of pen x
	 */
	float x = 0;
	/**
	 *.pos of pen y
	 */
	float y = 0;
public:
	/**
	 * .sets num parameters taken
	 * 
	 */
	PosPencommand();
	/**
	 * .performs check on parameters coming to check if ints
	 * 
	 * \param x user input 1
	 * \param y user input 2
	 * \return success of check
	 */
	bool syntaxcheck(std::string x, std::string y);
	/**
	 * .sets points for setting of new pen pos
	 * 
	 * \param newx1 pen x change
	 * \param newx2 pen y change
	 */
	void setPoints(float newx1, float newx2);
	/**
	 * .runs set pen command
	 * 
	 * \param renderer uses renderer to do this
	 * \param Pen kept for possible inheritance on commands 
	 * \return sdl error
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);

};

