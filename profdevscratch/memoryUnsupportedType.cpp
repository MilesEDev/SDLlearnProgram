#include "memoryUnsupportedType.h"

memoryUnsupportedType::memoryUnsupportedType(std::string error)
{
	this->error = error;
}

std::string memoryUnsupportedType::returnError()
{
	return error;
}
