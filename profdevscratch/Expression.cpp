#include "Expression.h"
#include <vector>

std::string Expression::add(std::string term1, std::string term2)
{
    
        if (term1[0] == '\"' && term2[0] == '\"')
        {
            std::string result =  term1 + term2;
            return result;
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

std::string Expression::getResult()
{
    return std::string();
}



std::string Expression::calcFull(std::string expr)
{
    bool key = false;
    int i = 0;
    std::string priorites[4] = { "/","*","+","-"};
    std::vector<int> operationPositions;
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
                    if (i > start && i < opLocation)
                    {
                        start = i;
                    }
                    i = opLocation;
                    while (!isOperation(expr, i, operation) && i > 0)
                    {
                        i--;
                    }

                }
                std::string arg1 = expr.substr(start, opLocation);
                i = end;
                for (std::string operation : priorites)
                {
                    if (i < end && i > opLocation)
                    {
                        end = i;
                    }
                    i = end;
                    bool key2 = false;
                    while (i > opLocation)
                    {
                        if (isOperation(expr, i, operation))
                        {
                            key2 = true;
                        }
                        if (key2 && i == opLocation+1)
                        {
                            break;
                        }
                        i--;
                    }
                    if (i == opLocation) 
                    {
                        i = expr.size();
                    }
                }
                std::string arg2 = expr.substr(opLocation +1,end-opLocation);
                if (operation == "+")
                {
                    std::string result = add(arg1, arg2);
                }
                if (operation == "-")
                {
                    std::string result = subtract(arg1, arg2);
                }
                expr.replace(start, end, result);
                i = 0;
            }
            

        }
    }
    return "fuck";

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
