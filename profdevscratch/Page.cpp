#include "Page.h"

void Page::setVarName(std::string newName)
{
	varName = newName;
}

std::string Page::getVarName()
{
	return varName;
}

void Page::setDataType(std::string newDataType)
{
	dataType = newDataType;
}

std::string Page::getDataType()
{
	return dataType;
}

void Page::setVarPtr(void* &newPtr)
{
	varPtr = *&newPtr;
}

void* Page::getVarPtr()
{
	return varPtr;
}

void Page::setVarSize(int size)
{
	this->size = size; 
}

int Page::getVarSize()
{
	return this->size;
}



