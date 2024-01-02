#include "nonStringException.h"

nonStringException::nonStringException(std::string error)
{
	this->error = error;
}

std::string nonStringException::returnError()
{
	return error;
}
