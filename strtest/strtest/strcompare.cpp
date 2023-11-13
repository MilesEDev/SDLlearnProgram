#include "strcompare.h"

bool strcompare::strCompare(std::string test,const char* charcomp)
{
	int size = sizeof(charcomp);
	for (int i = 0; i < sizeof(charcomp)/sizeof(charcomp[0]); i++) {
		
		if (!test.c_str()[i] == std::tolower(charcomp[i])) {
			return false;
		}
		else
		{
			return true;
		}



	}

}