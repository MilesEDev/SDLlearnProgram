#pragma once
#include <string>
#include "dataChecker.h"
#include "dataConverter.h"
class operators
{
	bool greaterThan(std::string term1, std::string term2);

	bool greaterThanEqual(std::string term1, std::string term2);

	bool lesserThan(std::string term1, std::string term2);

	bool lesserThanEqual(std::string term1, std::string term2);

	bool equalTo(std::string term1, std::string term2);

};

