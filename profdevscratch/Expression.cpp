#include "Expression.h"
#include <vector>
#include "dataConverter.h"
std::string Expression::add(std::string term1, std::string term2)
{
   
    if (myChecker->isString(term1) && myChecker->isString(term2))
    {
        std::string result = myConverter->sliceQoutes(term1) + myConverter->sliceQoutes(term2);
        return myConverter->addQoutes(result);
    }

    else if (myChecker->isFloat(term1) && myChecker->isFloat(term2))
    {
        float result = std::stof(term1) + std::stof(term2);
        return std::to_string(result);
    }
    else
    {
        throw operationNotSupportDataType("you have entered in an argument with an unsupported datatype for addition");
    }
        
    
   
}

std::string Expression::subtract(std::string num1, std::string num2)
{
    if (myChecker->isFloat(num1) && myChecker->isFloat(num2))
    {
        float result = std::stof(num1) - std::stof(num2);
        return std::to_string(result);
    }
    else
    {
        throw operationNotSupportDataType("you have entered in an argument with an unsupported datatype for subtraction");
    }
}

std::string Expression::multiply(std::string num1, std::string num2)
{
    if (myChecker->isFloat(num1) && myChecker->isFloat(num2))
    {
        float result = std::stof(num1) * std::stof(num2);
        return std::to_string(result);
    }
    else
    {
        throw operationNotSupportDataType("you have entered in an argument with an unsupported datatype for multiplication");
    }
}

std::string Expression::divide(std::string num1, std::string num2)
{
    if (myChecker->isFloat(num1) && myChecker->isFloat(num2))
    {
        float result = std::stof(num1) / std::stof(num2);
        return std::to_string(result);
    }
    else
    {
        throw operationNotSupportDataType("you have entered in an argument with an unsupported datatype for divide");
    }
}


std::string Expression::calcFull(std::string expr,MemoryManager* myManager)
{
    bool key = false;
    int i = 0;
    
    for (std::string operation : priorites)
    {
        for (i = 0; i < expr.size(); i++)
        {
            char breakTest = expr[i];
            if (expr[i] == '\"')
            {
                int j = i + 1;
                while (j < expr.size())
                {
                    breakTest = expr[j];
                    if (expr[j] == '\\')
                    {
                        j++;
                    }
                    else if (expr[j] == '\"')
                    {
                        i = j;
                        break;
                    }
                    j++;
                }
            }
            if (expr[i] == '(')
            {
                int j = i + 1;
                while (j < expr.size())
                {
                    breakTest = expr[j];
                    
                    if (expr[j] == ')')
                    {
                        std::string calcBrackets = calcFull(expr.substr(i + 1, j - (i + 1)), myManager);
                        expr.replace(i,j-i+1, calcBrackets);
                        i = 0;
                        break;
                    }
                    j++;
                }

            }
            key = isOperation(expr, i, operation);
            if (expr[0] == '-' && i == 0)
            {
                key = false;
            }
            if (key)
            {
                
                
                int end = expr.size();
                int start = 0;
                int opLocation = i;
                for (std::string operation : priorites)
                {

                    i = 0;

                    bool key2 = false;
                    while (i < opLocation)
                    {
                        char breakTest = expr[i];
                        if (expr[i] == '\"')
                        {
                            int j = i+1;
                            while (j < expr.size())
                            {
                                breakTest = expr[j];
                                if (expr[j] == '\\') 
                                {
                                    j++;
                                }
                                if (expr[j] == '\"')
                                {
                                    i = j;
                                    break;
                                }
                                j++;
                            }

                        }
                        if (isOperation(expr, i, operation))
                        {
                            key2 = true;
                            if (isAnyOperation(expr, i - 1))
                            {
                                
                            }
                            else if (i > start)
                            {
                                start = i + 1;
                            }
                        }

                        i++;
                    }

                }
                std::string arg1 = expr.substr(start, opLocation - start);
                i = end;
                for (std::string operation : priorites)
                {

                    i = end;
                    bool key2 = false;
                    while (i > opLocation)
                    {
                        char breakTest = expr[i];
                        if (expr[i] == '\"')
                        {
                            int j = i - 1;
                            while (j > 0)
                            {
                                char breakTest = expr[j];
                                char breaktest2 = expr[j - 1];
                                if (expr[j-1] == '\\')
                                {
                                    
                                }
                                else if (expr[j] == '\"')
                                {
                                    i = j;
                                    break;
                                }
                                j--;
                            }
                            
                        }
                        
                        if (isOperation(expr, i, operation))
                        {
                            key2 = true;
                            char breakTest2 = expr[i];
                            char breakTest3 = expr[i-1];
                            if (isAnyOperation(expr, i - 1))
                            {

                            }
                            else if (i < end)
                            {
                                end = i;
                            }
                        }

                        i--;
                    }

                }
                std::string arg2 = expr.substr(opLocation + 1, end - (opLocation + 1));
                std::string result;
                
                if (myManager->pageExist(arg1))
                {
                   arg1= myManager->returnValue(arg1);
                }
                if (myManager->pageExist(arg2))
                {
                    arg2 = myManager->returnValue(arg2);
                }

                
                
               

                if (operation == "+")
                {
                    result = add(arg1, arg2);
                }
                if (operation == "-")
                {
                    result = subtract(arg1, arg2);
                }
                if (operation == "/")
                {
                    result = divide(arg1, arg2);
                }
                if (operation == "*")
                {
                    result = multiply(arg1, arg2);
                }
                expr.replace(start, end - start, result);
                i = 0;
                    
                
            }
          

        }
        
    }
    return expr;

}

bool Expression::isExpression(std::string exprOrVal)
{
    int i = 0;
    bool key = false;
    for (std::string operation : priorites)
    {
        if (key)
        {
            break;
        }
        i = 0;
        while (i < exprOrVal.size())
        {
            char breakTest = exprOrVal[i];
            if (exprOrVal[i] == '\"')
            {
                int j = i + 1;
                while (j < exprOrVal.size())
                {
                    breakTest = exprOrVal[j];
                    if (exprOrVal[j] == '\\')
                    {
                        j++;
                    }
                    if (exprOrVal[j] == '\"')
                    {
                        i = j;
                        break;
                    }
                    j++;
                }
            }
            if (isOperation(exprOrVal, i, operation))
            {
                key = true;
                break;
            }
            i++;
        }
       
    }
    int opPos = i;
    if (opPos >= exprOrVal.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool Expression::isAssignment(std::string exprOrVal)
{
    int i = 0;
    while (i < exprOrVal.size())
    {
        char breakTest = exprOrVal[i];
        if (exprOrVal[i] == '\"')
        {
            int j = i + 1;
            while (j < exprOrVal.size())
            {
                breakTest = exprOrVal[j];
                if (exprOrVal[j] == '\\')
                {
                    j++;
                }
                if (exprOrVal[j] == '\"')
                {
                    i = j;
                    break;
                }
                j++;
            }
        }
        if (exprOrVal[i] == '=' && i>0 && i < exprOrVal.size()-1)
        {
            return true;
        }
        i++;
    }
    return false;
    


}
std::string Expression::getVarName(std::string exprOrVal)
{
    int i = 0;
    while (i < exprOrVal.size())
    {
        char breakTest = exprOrVal[i];
        if (exprOrVal[i] == '\"')
        {
            int j = i + 1;
            while (j < exprOrVal.size())
            {
                breakTest = exprOrVal[j];
                if (exprOrVal[j] == '\\')
                {
                    j++;
                }
                if (exprOrVal[j] == '\"')
                {
                    i = j;
                    break;
                }
                j++;
            }
        }
        if (exprOrVal[i] == '=')
        {
            std::string varName = exprOrVal.substr(0, i);
            return varName;
        }
        i++;
    }
    
}
void Expression::performAssignment(std::string assignmentStatement,MemoryManager* memory)
{
    std::string value = getAssignmentValue(assignmentStatement);
    if (checkAssignmentValue(value,memory))
    {
        std::string varName = getVarName(assignmentStatement);
        std::string value = assignmentStatement.substr(varName.size()+1, assignmentStatement.size()-varName.size());
        if (memory->pageExist(value))
        {
            value = memory->returnValue(value);
        }
        value = calcFull(value,memory);
       
        memory->pageCreationAndUpdate(varName,value);
    }
}
bool Expression::checkAssignmentValue(std::string value,MemoryManager* memory)
{
    
    
    if (isExpression(value))
    {
       
        
            value = calcFull(value, memory);
            return true;
        
    }
    else if(memory->pageExist(value))
    {

        return true;
    }
    else if (myChecker->isValue(value))
    {
        return true;
    }
    else
    {
        return false;
    }

}
std::string Expression::getAssignmentValue(std::string assignmentStatement)
{
    std::string varName = getVarName(assignmentStatement);
    std::string value = assignmentStatement.substr(varName.size() + 1, assignmentStatement.size());
    return value;
}
bool Expression::hasToDefines(std::string expression,MemoryManager* ToDefinesChecker)
{
    int i = 0;
    int opLocation = 0;
    for (std::string operation : priorites)
    {
        opLocation = 0;
        i = 0;
        while (i < expression.size())
        {
            char breakTest = expression[i];
            if (expression[i] == '\"')
            {
                int j = i + 1;
                while (j < expression.size())
                {
                    breakTest = expression[j];
                    if (expression[j] == '\\')
                    {
                        j++;
                    }
                    if (expression[j] == '\"')
                    {
                        i = j;
                        break;
                    }
                    j++;
                }
            }
            if (isOperation(expression, i, operation) && i > 0 && i < expression.size() - 1)
            {
                if (ToDefinesChecker->isToDefine(expression.substr(opLocation, i - opLocation)))
                {
                    return true;
                }
            }
            i++;
        }
    }
    return false;

}
bool Expression::isAnyOperation(std::string expr, int subStr)
{
    bool key = true;
    for (std::string operation:priorites) {
        key = true;
        for (int j = 0; j < operation.size(); j++)
        {
            if (subStr <= expr.size())
            {
                if (expr[subStr + j] != operation[j])
                {
                    key = false;
                }
            }

        }
        if (key)
        {
            return true;
        }
        
    }
    return false;
    

}



bool Expression::isOperation(std::string expr, int subStr, std::string operation)
{
   
    for (int j = 0; j < operation.size(); j++)
    {
        if (subStr <= expr.size())
        {
            if (expr[subStr + j] != operation[j])
            {
                return false;
            }
        }
    }
    
}
