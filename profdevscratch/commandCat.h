#pragma once
#include "dataChecker.h"
#include <typeinfo>
#include <vector>
#include "dataConverter.h"
class commandCat
{
protected:
	int parameterno = 0;

	dataChecker* myChecker = dataChecker::getInstance();



	dataConverter* myConverter = dataConverter::getInstance(); 

	std::vector<int> parsedAttributes;
public:
	virtual bool correctParamsCount(int numParams);

};

