#include "erroneousVarName.h"

erreneousVarName::erreneousVarName(std::string error)
{
	this->error = error; 
}

std::string erreneousVarName::returnError()
{
	return error;
}
