#include "MemoryManager.h"

void MemoryManager::createPage(std::string varName, std::string varValue)
{
	Page* newPage = new Page();
	if (myChecker->isString(varValue))
	{
		newPage->setDataType("string");
		std::string tempStr = varValue;

		void* vPtr = &tempStr;

		newPage->setVarPtr(vPtr);
		
	}
	if (myChecker->isFloat(varValue))
	{
		newPage->setDataType("float");
		float tempFloat = std::stof(varValue);

		void* vPtr = &tempFloat;

		newPage->setVarPtr(vPtr);

	}
	if (myChecker->isBool(varValue))
	{
		newPage->setDataType("bool");
		

		

		newPage->setVarPtr(vPtr);

	}


	newPage->setVarName(varName);

}
