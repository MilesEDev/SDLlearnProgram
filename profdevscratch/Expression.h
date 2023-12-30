#pragma once
#include <string>
#include "dataChecker.h"
#include "operationNotSupportDataType.h"
class Expression
{
private:
	dataChecker* myChecker = new dataChecker;
	std::string result;

	std::string add(std::string term1,std::string term2);

	std::string subtract(std::string num1, std::string num2);

	std::string multiply(std::string num1,std::string num2);

	std::string divide(std::string num1, std::string num2);

	std::string getResult();

	std::string calcFull(std::string expr);
public:

	bool isOperation(std::string expr,int subStr,std::string operation);

};

