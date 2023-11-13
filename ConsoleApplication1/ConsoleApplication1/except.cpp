#include "except.h"
#include <stdexcept>

int except::add(int a, int b)
{
	
	a + b;
	throw std::invalid_argument("AddPositiveIntegers arguments must be positive");
	return a;
	
}

void except::catcher()
{
	int a;


	
		
		

}
