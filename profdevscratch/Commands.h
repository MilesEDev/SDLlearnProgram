#pragma once
#include <string>
#include "nonnumberexception.h"
class Commands
{
protected:
	int parameterno = 0;
public:
	Commands();

	bool isFloat(std::string mystring);

	bool correctParamsCount(int numParams);
};

