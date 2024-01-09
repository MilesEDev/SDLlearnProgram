#pragma once
#include "Commands.h";
#include <string>       
#include <iostream>   
#include "Render.h"
#include "eventfactory.h"
#include "shape.h"
#include "IArgManager.h"
#include "circle.h"
#include "incorrectDataTypeParameter.h"
#include "dataChecker.h"
#include "dataConverter.h"
/**
 * .a bridge between user input and setting up circle 
 */
class circleCommand:public Commands,public IArgManager
{
private:
	
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
	
	/**
	 * .runs circle command
	 * 
	 * \param renderer to be used render circle
	 * \param Pen kept as may update to inherit from commands
	 * \return sdl error if there is one
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen) override;
	

	/**
	 * .
	 * 
	 * \param commandArgs takes in commandArgs and checks syntax on it for circle 
	 * \return is good syntax or not 
	 * 
	 * \example CircleCommSyntax.cpp
	 * 
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs) override; 
	
	/**
	 * .this is used to parse the circle argument to that it is a float so it can be used in runcommand
	 * 
	 * \param commandArgs
	 * 
	 * \example circleCommSetAttr.cpp
	 */
	void setAttributes(std::vector<std::string> commandArgs) override;

	

};


