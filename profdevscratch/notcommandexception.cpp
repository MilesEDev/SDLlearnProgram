#include "notcommandexception.h"

notcommandexception::notcommandexception(std::string error)
{
	this->error = error;
}

std::string notcommandexception::returnError()
{
	return error;
}
