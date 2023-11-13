#pragma once
#include <iostream>
#include <exception>
#include <string>       
/**
 * .used if non fill value attempted to be used in fill value parameter
 */
class nonfillvalue: public std::exception
{
private:
	/**
	 * . the error to be returned
	 */
	std::string error;
public:
	/**
	 * .the setting of error
	 * 
	 * \param error error to use to set
	 */
	nonfillvalue(std::string error);
	/**
	 * .
	 * 
	 * \return error  
	 */
	std::string returnError();



};


