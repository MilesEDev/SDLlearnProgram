#include "MemoryManager.h"

void MemoryManager::createPage(std::string varName, std::string varValue)
{
	dataConverter* myConverter = new dataConverter(); 
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
		
		bool tempBool = myConverter->stringToBool(varValue);
		void* vPtr = &tempBool;

		newPage->setVarPtr(vPtr);

	}


	newPage->setVarName(varName);
	PageTable.push_back(newPage);
}

std::string MemoryManager::returnValue(std::string varName)
{
	Page* pageToReturn = new Page();
	for(Page* page : PageTable) 
	{
		if (page->getVarName() == varName)
		{
			pageToReturn = page;
			break;
		}

	}
	dataConverter* myConverter = new dataConverter();
	if (pageToReturn->getDataType() == "string")
	{
		std::string* rawValue = static_cast<std::string*>(pageToReturn->getVarPtr());
		return myConverter->addQoutes(*rawValue);
	}
	if (pageToReturn->getDataType() == "float")
	{
		int* rawValue = (int*)pageToReturn->getVarPtr(); 
		return std::to_string(*rawValue);
	}
	if (pageToReturn->getDataType() == "bool") 
	{
		bool* rawValue = (bool*) pageToReturn->getVarPtr();

		return myConverter->boolToString(rawValue);
	}
	
	
}
