#pragma once
#include "Commands.h"
#include <string>
#include "rectangle.h"
#include "Render.h"
class notcommandexception: std::exception
{
private:
	std::string error;
public:
	notcommandexception(std::string error);

	std::string returnError();



};

