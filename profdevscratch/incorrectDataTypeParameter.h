#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <string>       

class incorrectDataTypeParameter:public std::exception
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
	incorrectDataTypeParameter(std::string error);
	/**
	 * .returns the error
	 *
	 * \return the error
	 */
	std::string returnError();

};

