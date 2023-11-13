#include "notcolourexception.h"

notcolourexception::notcolourexception(std::string error)
{
	this->error = error;
}

std::string notcolourexception::returnError()
{
	return error;
}
