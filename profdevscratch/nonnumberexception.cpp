#include "nonnumberexception.h"


nonnumberexception::nonnumberexception(std::string error)
{
	this->error = error;
}

std::string nonnumberexception::returnError()
{
	return error;
}
