#pragma once
#include "Commands.h"
#include <string>
#include "rectangle.h"
#include "Render.h"
/**
 * .exception to be thrown if user enters a command that does not exist
 */
class notcommandexception: std::exception
{
private:
	/**
	 * .error to be returned
	 */
	std::string error;
public:
	/**
	 * .constructor to set up the error
	 * 
	 * \param error
	 */
	notcommandexception(std::string error);
	/**
	 * .returns the error 
	 * 
	 * \return 
	 */
	std::string returnError();



};

