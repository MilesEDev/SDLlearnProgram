#pragma once
#include <string>
class Page
{
private:
	std::string varName;

	std::string dataType;

	void* varPtr;

	int size; 
public:
	void setVarName(std::string newName);

	std::string getVarName();

	void setDataType(std::string newDataType);

	std::string getDataType();

	void setVarPtr(void* &newPtr);

	void* getVarPtr();

	void setVarSize(int size);

	int getVarSize();



	
};

