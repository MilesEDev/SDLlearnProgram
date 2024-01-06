#include "VptrConv.h"
#include <string>
#include <iostream>

void VptrConv::converter()
{
	std::string value2 = "hello";
	std::string* value = &value2;
	Vptr = dynamic_cast<std::string*>(value);
	
	std::cout << *&Vptr;
	
}

void VptrConv::readVptr()
{
	
}
