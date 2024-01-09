#include "dataChecker.h"
#include <SDL_stdinc.h>


dataChecker* dataChecker::myChecker = nullptr;

dataChecker::dataChecker(){}

bool dataChecker::isFloat(std::string mystring)
{
	bool error = false;
	int pos;

	pos = mystring.find(".");

	if (pos > -1)
	{
		mystring.erase(pos, pos + 1);
		if (pos = mystring.find(".") > -1) {
			error = true;
		}
	}
	if (!error)
	{
		for (int i = 0; i < strlen(mystring.c_str()); i++)
		{
			char breakTest = mystring[i];
			if (!isdigit(mystring.c_str()[i]) && !(mystring.c_str()[0] =='-' && i==0))
			{

				error = true;
				break;

			}

		}
	}
	else {
		error = true;
	}
	if (error) {
		return false;
	}
	else {
		return true;
	}

}

bool dataChecker::isBool(std::string myString)
{
	if (SDL_strcasecmp(myString.c_str(), "true") ==0|| SDL_strcasecmp(myString.c_str(), "false")==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool dataChecker::isString(std::string myString)
{
	char testChar = myString[myString.size()];
	if (myString[0] == '\"' && myString[myString.size()-1] == '\"')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool dataChecker::isSpecialChar(std::string myString, int charIndex)
{
	specialCharManager* mySpecialChar = new specialCharManager();
	std::string specialChar;
	int key = true; 
	for (int i = 0; i < mySpecialChar->getNumChars();i++)
	{
		key = true;
		specialChar = mySpecialChar->getSingleSpecialChar(i);
		for (int j = 0; j < specialChar.size(); j++)
		{
			char test = myString[charIndex+j];
			if (myString[charIndex + j] != specialChar[j])
			{
				key = false; 
				break; 
			}

		}
		if (key)
		{
			return true;
		}

	}
	return false;
}

bool dataChecker::wholeCheckForBadSpecialChar(std::string myString)
{
	for (int i = 0; i < myString.size(); i++)
	{
		char test = myString[i];
		if (myString[i] == '\\')
		{
			if (!isSpecialChar(myString, i))
			{
				return false;
			}
			i++;


		}

	}
	return true;
}

bool dataChecker::isValue(std::string toCheck)
{
	if (isString(toCheck) || isBool(toCheck) || isFloat(toCheck))
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string dataChecker::readFuncName(std::string funcStatement)
{
	int i = 0;
	std::string functionName = "";
	
	while (funcStatement[i] != '(' && i < funcStatement.size())
	{
		functionName = functionName + funcStatement[i];
		i++;
	}
	return functionName;
}

dataChecker* dataChecker::getInstance()
{
	if (myChecker == nullptr)
	{
		myChecker = new dataChecker;
	}
	return myChecker;
}

