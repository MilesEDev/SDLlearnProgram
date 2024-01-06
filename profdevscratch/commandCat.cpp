#include "commandCat.h"

bool commandCat::correctParamsCount(int numParams)
{
	if (numParams == parameterno) {
		return true;
	}
	else {
		return false;
	}
}

