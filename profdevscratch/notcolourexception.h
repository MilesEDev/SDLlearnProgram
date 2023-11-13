#pragma once
#include <iostream>
#include <exception>
#include <string>     
/**
 * .thrown if user enters a value that is not a colour for colour command
 */
class notcolourexception : public std::exception
{
private:
	/**
	 * .error to return 
	 */
	std::string error;
public:
	/**
	 * .this constructor sets up the error to be returned
	 * 
	 * \param error
	 */
	notcolourexception(std::string error);
	/**
	 * .returns the error 
	 * 
	 * \return 
	 */
	std::string returnError();
};

