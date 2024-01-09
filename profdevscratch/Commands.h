#pragma once
#include <string>
#include "nonnumberexception.h"
#include <vector>
#include "Render.h"
#include "dataChecker.h"
#include "commandCat.h"
/**  base class for commands */
class Commands:public commandCat
{

public:
	/**
	 * .empty constructor
	 * 
	 */
	Commands();

	/**
	 * .checks if value is float for user input might move to parser
	 *
	 * \param mystring
	 * \return isfloat or not
	 */
	

	/**
	 * .
	 *
	 * \param numParams
	 * \return is param count correct
	 */
	
	/**
	 * .the run command that all gui commands must follow 
	 */
	
	virtual std::string runCommand(Render* renderer, std::pair<float, float> Pen) = 0;





};

