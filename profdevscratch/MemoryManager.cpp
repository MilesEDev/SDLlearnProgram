#include "MemoryManager.h"
#include <iostream>

Page* MemoryManager::alterPage(std::string varValue,Page* pageToEdit)
{
	dataConverter* myConverter = dataConverter::getInstance();
	if (pageToEdit->getVarPtr() != nullptr) {

		free(pageToEdit->getVarPtr());
	}
	if (myChecker->isString(varValue))
	{
		pageToEdit->setDataType("string");
		std::string tempStr = varValue;
		char* tempStrP = (char*)malloc(tempStr.size()+1 * sizeof(char));
		
		

		strcpy_s(tempStrP, varValue.size()+1,varValue.c_str());

		void* vPtr = tempStrP;

		pageToEdit->setVarPtr(vPtr);
		pageToEdit->setVarSize(varValue.size());
		
	}
	else if (myChecker->isFloat(varValue))
	{
		pageToEdit->setDataType("float");
		float* tempFloat = (float*)malloc(1*sizeof(float)); 
		
		float value = std::stof(varValue);
		tempFloat[0] = value;
		void* vPtr = tempFloat;
		
		
		pageToEdit->setVarPtr(vPtr);

	}
	else if(myChecker->isBool(varValue))
	{
		pageToEdit->setDataType("bool");
		
		bool tempBool = myConverter->stringToBool(varValue);
		void* vPtr = &tempBool;

		pageToEdit->setVarPtr(vPtr);

	}
	else
	{
		throw memoryUnsupportedType("you have entered a value that does not have a supported data type");
	}
	return pageToEdit;


	
}

void MemoryManager::createPage(std::string varName, std::string varValue)
{
	Page* newPage = new Page();
	newPage = alterPage(varValue, newPage);
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
	
	dataConverter* myConverter = dataConverter::getInstance();
	if (pageToReturn->getDataType() == "string")
	{
		char* rawValue = static_cast<char*>(pageToReturn->getVarPtr());
		std::string returnString = "";
		for (int i = 0; i < pageToReturn->getVarSize(); i++)
		{
			returnString = returnString + rawValue[i];
		}
		
		return returnString;
	}
	else if(pageToReturn->getDataType() == "float")
	{
		void* vP = pageToReturn->getVarPtr();
		float* rawValue = (float*)pageToReturn->getVarPtr(); 
		return std::to_string(*rawValue);
	}
	else if(pageToReturn->getDataType() == "bool") 
	{
		bool* rawValue = (bool*) pageToReturn->getVarPtr();

		return myConverter->boolToString(rawValue);
	}
	
	
}

bool MemoryManager::BannedVarNames(std::string varName)
{

	commandCatFactory* myCatFactory = new commandCatFactory();
	if (myCatFactory->getCommand(varName) == nullptr && !myChecker->isString(varName) 
		||myChecker->isBool(varName)||myChecker->isFloat(varName))
	{
		
		return true;
	}
	else
	{
		return false; 
	}
}

bool MemoryManager::BannedChars(std::string varName)
{
	std::regex banChar("[@_!#$%^&*()<>?/|}{~:]");
	if (std::regex_search(varName,banChar))
	{
		return false;
	}
	else
	{
		return true; 
	}
}

void MemoryManager::updateValue(std::string varName, std::string varValue)
{
	Page* pageToReturn = new Page();
	for (Page* page : PageTable)
	{
		if (page->getVarName() == varName)
		{
			pageToReturn = page;
			break;
		}

	}
	pageToReturn = alterPage(varValue, pageToReturn);
	

}

bool MemoryManager::pageExist(std::string varName)
{
	for (Page* page : PageTable)
	{
		if (page->getVarName() == varName)
		{
			
			return true;
		}

	}
	return false;
}

bool MemoryManager::isGoodVarName(std::string varName)
{
	if (!BannedChars(varName))
	{
		throw erreneousVarName("you have entered a var name which includes banned characters please"
			"do not use special characters");
		return false;
	}
	else if (!BannedVarNames(varName))
	{
		throw erreneousVarName("you have entered a var name which is a reserved name for something else"
			"please do not use var names of commands");
	}
	else if (myChecker->isValue(varName))
	{
		throw erreneousVarName("you have entered a varname which is a data type value e.g a number or string");
	}
	else
	{
		return true;
	}
}

void MemoryManager::deletePagetable()
{
	PageTable.clear();
}

bool MemoryManager::pageCreationAndUpdate(std::string varName,std::string varValue)
{
	if (!isGoodVarName(varName))
	{
		return false;
	}
	if (pageExist(varName))
	{
		updateValue(varName, varValue);
		return true;
	}
	else
	{
		createPage(varName, varValue);
		return true;
	}
}

