#include "cannotEndBody.h"

cannotEndBody::cannotEndBody(std::string error)
{
	this->error = error;
}

std::string cannotEndBody::returnError()
{
	return error;
}
