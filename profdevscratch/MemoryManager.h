#pragma once
#include <string>
#include "Page.h"
#include <vector>
#include "dataConverter.h"
#include "dataChecker.h"
#include <regex>
#include "commandCatFactory.h"
#include "memoryUnsupportedType.h"
#include "erroneousVarName.h"
class MemoryManager
{
private:
	
	dataChecker* myChecker = dataChecker::getInstance();
	std::vector<Page*> PageTable;
	
	Page* pageToAdd;
public:
	

	void createPage(std::string varName,std::string varValue);

	Page* alterPage(std::string varValue,Page* pageToEdit);

	std::string returnValue(std::string varName);

	bool BannedVarNames(std::string varName);

	bool BannedChars(std::string varName);

	void updateValue(std::string varName,std::string varValue);

	bool pageCreationAndUpdate(std::string varName, std::string varValue);

	bool pageExist(std::string varName);

	bool isGoodVarName(std::string varName);

	void deletePagetable();

	

};

