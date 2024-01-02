#include "dataChecker.h"
#include <SDL_stdinc.h>

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
			if (!isdigit(mystring.c_str()[i]))
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
	if (SDL_strcasecmp(myString.c_str(), "true") || SDL_strcasecmp(myString.c_str(), "false"))
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
	if (myString[0] == '\"' && myString[myString.size()-1] == '\"')
	{
		return true;
	}
	else
	{
		return false;
	}
}

