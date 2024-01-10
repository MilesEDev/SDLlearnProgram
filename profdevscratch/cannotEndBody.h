#pragma once
#include <iostream>
#include <exception>
#include <string>       
/**
 * .throws exception for invalid parameter number
 */
class cannotEndBody :public std::exception
{
private:
	/**
	 * .error to be returned
	 */
	std::string error;
public:
	/**
	 * .constructor sets the error
	 *
	 * \param error to be returned
	 */
	cannotEndBody(std::string error);
	/**
	 * .returns the error
	 *
	 * \return the error
	 */
	std::string returnError();



};

