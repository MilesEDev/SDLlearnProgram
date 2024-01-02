#pragma once
#include <iostream>
#include <exception>
#include <string>       

class nonStringException
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
		nonStringException(std::string error);
		/**
		 * .returns error
		 *
		 * \return
		 */
		std::string returnError();

};

