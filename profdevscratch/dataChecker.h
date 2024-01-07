#pragma once
#include <string>
#include "specialChar.h"
class dataChecker
{
private:


	static dataChecker* myChecker;
	dataChecker();
	
public:

	
	bool isFloat(std::string myString);

	bool isBool(std::string myString);

	bool isString(std::string myString);

	bool isSpecialChar(std::string myString, int charIndex);

	bool wholeCheckForBadSpecialChar(std::string myString);

	bool isValue(std::string toCheck);

	static dataChecker* getInstance();

};

