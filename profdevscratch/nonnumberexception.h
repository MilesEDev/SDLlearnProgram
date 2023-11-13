#pragma once
#pragma once
#include <iostream>
#include <exception>
#include <string>       


class nonnumberexception:public std::exception
{
private:
	std::string error; 
public:
	nonnumberexception(std::string error);

	std::string returnError();

	

};

