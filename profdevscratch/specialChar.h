#pragma once
#include <string>
class specialCharManager
{
private:
	std::string specialChars[2] = { "\\\\","\\\"" };

public:
	std::string* getSpecialChars();

	std::string getSingleSpecialChar(int iterator);

	int getNumChars();
};

