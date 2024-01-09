#pragma once
#include <string>
#include <vector>

class programmingBodies
{
protected:
	int thisProgramCounterPos = 0; 
	std::string commandName ="";
public:
	int getProgramCounterPos();

	void setProgramCounterPos(int pcr);

	std::string getName();

	
	

};

