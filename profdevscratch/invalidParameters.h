#pragma once
#include <iostream>
#include <exception>
#include <string>       

/**
 * .throws exception for invalid parameter number
 */
class InvalidParameters :public std::exception
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
	InvalidParameters(std::string error);
	/**
	 * .returns the error
	 * 
	 * \return the error 
	 */
	std::string returnError();



};

