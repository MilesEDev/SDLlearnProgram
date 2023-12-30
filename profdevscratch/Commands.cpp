#include "Commands.h"



Commands::Commands() {}






	

bool Commands::correctParamsCount(int numParams)
{
	if (numParams == parameterno) {
		return true;
	}
	else {
		return false;
	}
}

