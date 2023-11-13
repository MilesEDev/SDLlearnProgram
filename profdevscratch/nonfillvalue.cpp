#include "nonfillvalue.h"

nonfillvalue::nonfillvalue(std::string error)
{
	this->error = error;
}

std::string nonfillvalue::returnError()
{
	return error;
}
