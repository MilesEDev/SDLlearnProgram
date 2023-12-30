#include "dataChecker.h"

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
