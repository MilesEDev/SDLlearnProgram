#include "invalidParameters.h"

InvalidParameters::InvalidParameters(std::string error)
{
	this->error = error;
}

std::string InvalidParameters::returnError()
{
	return error;
}
