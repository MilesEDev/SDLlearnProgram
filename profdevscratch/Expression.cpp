#include "Expression.h"
#include <vector>
#include "dataConverter.h"
std::string Expression::add(std::string term1, std::string term2)
{
    dataConverter* dataConv = new dataConverter();
    dataChecker* myChecker = new dataChecker();
    if (myChecker->isString(term1) && myChecker->isString(term2))
    {
        std::string result =  dataConv->sliceQoutes(term1) + dataConv->sliceQoutes(term2);
        return dataConv->addQoutes(result);
    }
        
    else if (myChecker->isFloat(term1) && myChecker->isFloat(term2))
    {
        float result = std::stof(term1) + std::stof(term2);
        return std::to_string(result);
    }
    else
    {
        //throw operationNotSupportDataType("you have entered in an argument with an unsupported datatype for addition");
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
        //throw operationNotSupportDataType("you have entered in an argument with an unsupported datatype for subtraction");
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
        //throw operationNotSupportDataType("you have entered in an argument with an unsupported datatype for multiplication");
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
        //throw operationNotSupportDataType("you have entered in an argument with an unsupported datatype for divide");
    }
}


std::string Expression::calcFull(std::string expr)
{
    bool key = false;
    int i = 0;
    
    for (std::string operation : priorites)
    {
        for (i = 0; i < expr.size(); i++)
        {
            key = isOperation(expr, i, operation);
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
                            if (i > start)
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
                        if (expr[i] == '\"')
                        {
                            int j = i - 1;
                            while (j > 0)
                            {
                                j--;
                                if (j == '\"')
                                {
                                    i = j;
                                    break;
                                }
                            }

                        }
                        if (isOperation(expr, i, operation))
                        {
                            key2 = true;
                            if (i < end)
                            {
                                end = i;
                            }
                        }

                        i--;
                    }

                }
                std::string arg2 = expr.substr(opLocation + 1, end - (opLocation + 1));
                
            
                
                std::string result;
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
    dataChecker* myChecker = new dataChecker();
    if (myChecker->isString(exprOrVal))
    {
        return false; 
    }
    else 
    {
        for (std::string operation : priorites)
        {
            for (int i = 0; i < exprOrVal.size(); i++)
            {

                if (isOperation(exprOrVal, i, operation))
                {
                    return true;
                }
            }
        }
        return false; 
    }
   
   
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
    
    return true;
}
