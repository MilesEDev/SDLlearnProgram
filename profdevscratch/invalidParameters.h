#pragma once
#pragma once
#pragma once
#include <iostream>
#include <exception>
#include <string>       


class InvalidParameters :public std::exception
{
private:
	std::string error;
public:
	InvalidParameters(std::string error);

	std::string returnError();



};

