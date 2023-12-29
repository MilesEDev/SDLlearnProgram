#pragma once
#include <string>
#include "nonnumberexception.h"
#include <vector>
#include "Render.h"
/**  base class for commands */
class Commands
{
protected:
	/**
	 * .params taken for sub class commands
	 */
	int parameterno = 0;

	std::vector<int> parsedAttributes;
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
	bool isFloat(std::string mystring);

	/**
	 * .
	 *
	 * \param numParams
	 * \return is param count correct
	 */
	bool correctParamsCount(int numParams);

	
	virtual std::string runCommand(Render* renderer, std::pair<float, float> Pen) = 0;





};

