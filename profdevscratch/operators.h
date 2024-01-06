#pragma once
#include <string>
#include "dataChecker.h"
#include "dataConverter.h"
class comparator
{
private:
	bool greaterThan(std::string term1, std::string term2);

	bool greaterThanEqual(std::string term1, std::string term2);

	bool lesserThan(std::string term1, std::string term2);

	bool lesserThanEqual(std::string term1, std::string term2);

	bool equalTo(std::string term1, std::string term2);

	
public:
	bool evaluateComparison(std::string term1, std::string comparator, std::string term2);

	bool validComparator(std::string comparator);

};

