#include "operationNotSupportDataType.h"

operationNotSupportDataType::operationNotSupportDataType(std::string error)
{
	this->error = error;
}

std::string operationNotSupportDataType::returnError()
{
	return error;
}
