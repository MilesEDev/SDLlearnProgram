#pragma once

#include <iostream>
#include <exception>
#include <string>   
class operationNotSupportDataType
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
	operationNotSupportDataType(std::string error);
	/**
	 * .returns the error
	 *
	 * \return the error
	 */
	std::string returnError();



};


