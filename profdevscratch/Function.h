#pragma once
#include "MemoryManager.h"
#include "dataChecker.h"
class Function
{
	MemoryManager* functionMemory = new MemoryManager();
	int MethodDefPcr;
	
	std::string functionName = "";
	std::vector<std::string> parameterNames;
	std::vector<std::string> Arguments;
	
	dataChecker* myChecker = dataChecker::getInstance();
	
public:
	

	Function(std::string wholeFuncName);

	void setMethodDefPcr(int Pcr);

	void setFunctionName(std::string wholeArgument); 

	MemoryManager* updateMemory();

	bool syntaxCheck();

	bool syntaxCheckParams();

	void extractParams(std::string paramsOrArgs,std::vector<std::string> &paramsOrArgsVector);

	void addArgsToMemory();

	std::string getName();

	void setArgs(std::string wholeStatement);

	int getMethodDefPcr();






	








};

