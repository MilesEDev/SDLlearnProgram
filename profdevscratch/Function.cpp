#include "Function.h"

Function::Function(std::string wholeFuncName)
{
 
	setFunctionName(wholeFuncName);
    extractParams(wholeFuncName.substr(functionName.size(), wholeFuncName.size() - functionName.size()),parameterNames);
    syntaxCheckParams();
    functionMemory->setToDefine(parameterNames);


}
void Function::setMethodDefPcr(int Pcr)
{
	MethodDefPcr = Pcr;
}
MemoryManager* Function::updateMemory() 
{
	return functionMemory;
}
bool Function::syntaxCheck()
{
    if (parameterNames.size() == Arguments.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Function::syntaxCheckParams()
{
    for (std::string Param : parameterNames)
    {
        if (functionMemory->isGoodVarName(Param))//catch and throw new exception here
        {
            return false;
        }
        
    }
    return true;
}
void Function::extractParams(std::string paramsOrArgs, std::vector<std::string> &paramsOrArgsVector)
{

    int i = 0;
    int lastComma = 0;
   
    while(i < paramsOrArgs.size())
    {
        char breakTest = paramsOrArgs[i];
        if (paramsOrArgs[i] == '\"')
        {
            int j = i + 1;
            while (j < paramsOrArgs.size())
            {
                breakTest = paramsOrArgs[j];
                if (paramsOrArgs[j] == '\\')
                {
                    j++;
                }
                if (paramsOrArgs[j] == '\"')
                {
                    i = j;
                    break;
                }
                j++;
            }
        }
        if (paramsOrArgs[i] == ',' || i == paramsOrArgs.size()-1)
        {
            std::string toPush = paramsOrArgs.substr(lastComma+1, i-lastComma-1);
            if (toPush.size() > 0)
            {
                paramsOrArgsVector.push_back(paramsOrArgs.substr(lastComma + 1, i - lastComma - 1));
            }
                lastComma = i;
            
        }
        i++;
    }
}
void Function::addArgsToMemory()
{
    for (int i = 0; i < Arguments.size(); i++)
    {
        functionMemory->pageCreationAndUpdate(parameterNames.at(i), Arguments.at(i));
    }
}
std::string Function::getName()
{
    return functionName;
}
void Function::setArgs(std::string wholeStatement)
{
    Arguments.clear();
    extractParams(wholeStatement.substr(functionName.size(), wholeStatement.size() - functionName.size()), Arguments);
}
int Function::getMethodDefPcr()
{
    return MethodDefPcr;
}
void Function::setFunctionName(std::string wholeArgument)
{
	int i = 0;
    functionName = "";
	while (wholeArgument[i] != '(')
	{
		functionName = functionName + wholeArgument[i];
        i++;
	}
}

