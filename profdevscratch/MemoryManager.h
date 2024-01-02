#pragma once
#include <string>
#include "Page.h"
#include <vector>
#include "dataConverter.h"
#include "dataChecker.h"

class MemoryManager
{
private:
	
	dataChecker* myChecker = new dataChecker();
	std::vector<Page> PageList;
	
	Page* pageToAdd;
public:
	void addToMemory(Page newPage);

	void createPage(std::string varName, std::string varValue);
	
	

};

