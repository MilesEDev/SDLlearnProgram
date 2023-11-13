#pragma once
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
/**
 * .draw to command to act as a bridge between user and renderer
 */
class drawToCommand : public Commands
{
private:
	/**
	 * .target x position to draw to 
	 */
	float x;
	/**
	 * .target y position to draw to 
	 */
	float y;
public:
	/**
	 * .draw to constructor for setting up param no
	 * 
	 */
	drawToCommand();
	/**
	 * .checks to make sure both x and y inputs are ints
	 * 
	 * \param x x input 
	 * \param y input 
	 * \return bool 
	 */
	bool syntaxcheck(std::string x, std::string y);
	/**
	 * .sets pos of target x and y values 
	 * 
	 * \param x target value
	 * \param y target value 
	 */
	void setPos(float x, float y);
	/**
	 * .runs command to draw to 
	 * 
	 * \param renderer to use to draw
	 * \param Pen to possibly link to commands 
	 * \return sdl error
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);

};

