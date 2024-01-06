#pragma once
#include "dataChecker.h"
#include <typeinfo>
#include <vector>

class commandCat
{
protected:
	int parameterno = 0;

	dataChecker* myChecker = new dataChecker();

	std::vector<int> parsedAttributes;
public:
	virtual bool correctParamsCount(int numParams);

};

