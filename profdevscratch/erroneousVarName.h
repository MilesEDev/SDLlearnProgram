#pragma once
#pragma once
#include <iostream>
#include <exception>
#include <string>       

/**
 * .throws exception of non int used as int/float parameter
 */
class erreneousVarName :public std::exception
{
private:
	/**
	 * .error to be returned
	 */
	std::string error;
public:
	/**
	 * .sets error
	 *
	 * \param error
	 */
	erreneousVarName(std::string error);
	/**
	 * .returns error
	 *
	 * \return
	 */
	std::string returnError();



};
