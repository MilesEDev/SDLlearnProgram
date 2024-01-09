#pragma once
#include <string>
class specialCharManager
{
private:
	static specialCharManager* mySpecialManager;
	std::string specialChars[2] = { "\\\\","\\\"" };
	specialCharManager();
public:
	std::string* getSpecialChars();

	std::string getSingleSpecialChar(int iterator);

	int getNumChars();

	static specialCharManager* getInstance();

};

