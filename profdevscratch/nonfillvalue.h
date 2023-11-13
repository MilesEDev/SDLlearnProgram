#pragma once
#include <iostream>
#include <exception>
#include <string>       
class nonfillvalue: public std::exception
{
private:
	std::string error;
public:
	nonfillvalue(std::string error);

	std::string returnError();



};


