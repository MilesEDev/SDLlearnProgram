#pragma once
#include "Commands.h";
#include <string>       
#include <iostream>   
#include "Render.h"
#include "eventfactory.h"
#include "shape.h"
#include "circle.h"
/**
 * .a bridge between user input and setting up circle 
 */
class circleCommand:public Commands
{
private:
	/**
	 * 
	 * .radius to be set and used to render circle
	 */
	float radius;
public:
	/**
	 * .sets num parameters 
	 * 
	 */
	circleCommand();
	/**
	 * .checks validity of input of radius
	 * 
	 * \param radius takes in user input
	 * \return successes or not
	 */
	bool syntaxcheck(std::string radius);
	/**
	 * .runs circle command
	 * 
	 * \param renderer to be used render circle
	 * \param Pen kept as may update to inherit from commands
	 * \return sdl error if there is one
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);
	/**
	 * .sets radius
	 * 
	 * \param newRadius new radius to set
	 */
	void setRadius(float newRadius);


};

