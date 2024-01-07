#include "variableIsUndefined.h"

variableIsUndefined::variableIsUndefined(std::string error)
{
	this->error = error;
}

std::string variableIsUndefined::returnError()
{
	return error;
}
