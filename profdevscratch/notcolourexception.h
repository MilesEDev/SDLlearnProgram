#pragma once
#include <iostream>
#include <exception>
#include <string>     
class notcolourexception : public std::exception
{
private:
	std::string error;
public:
	notcolourexception(std::string error);

	std::string returnError();
};

