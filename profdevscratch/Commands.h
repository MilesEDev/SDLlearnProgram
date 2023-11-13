#pragma once
#include <string>
#include "nonnumberexception.h"
/**  base class for commands */
class Commands
{
protected:
	/**
	 * .params taken for sub class commands
	 */
	int parameterno = 0;
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
};

