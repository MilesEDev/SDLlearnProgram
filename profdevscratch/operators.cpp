#include "operators.h"

comparator* comparator::myComparator = nullptr;


comparator::comparator() {}
bool comparator::greaterThan(std::string term1, std::string term2)
{
    dataChecker* myChecker = dataChecker::getInstance();
    if (myChecker->isString(term1) && myChecker->isString(term2))
    {
        if (term1 > term2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (myChecker->isFloat(term1) && myChecker->isFloat(term2))
    {
        if (std::stof(term1) > std::stof(term2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (myChecker->isBool(term1) && myChecker->isBool(term2))
    {
        if (SDL_strcasecmp(term1.c_str(), "true") == 0 && SDL_strcasecmp(term2.c_str(), "false") == 0)
        {
            return true;
        }
        else
        {
            return false; 
        }

    }
    else
    {
        //throw error 
    }



}

bool comparator::greaterThanEqual(std::string term1, std::string term2)
{
    if (!greaterThan(term1, term2))
    {
        return equalTo(term1, term2);
    }
    else
    {
        return true;
    }
}

bool comparator::lesserThan(std::string term1, std::string term2)
{
    dataChecker* myChecker = dataChecker::getInstance();
    if (myChecker->isString(term1) && myChecker->isString(term2))
    {
        if (term1 < term2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (myChecker->isFloat(term1) && myChecker->isFloat(term2))
    {
        if (std::stof(term1) < std::stof(term2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (myChecker->isBool(term1) && myChecker->isBool(term2))
    {
        if (SDL_strcasecmp(term1.c_str(), "false") == 0 && SDL_strcasecmp(term2.c_str(), "true") == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        //throw error 
    }


}

bool comparator::lesserThanEqual(std::string term1, std::string term2)
{
    if (!lesserThan(term1, term2))
    {
        return equalTo(term1, term2);
    }
    else
    {
        return true;
    }
}

bool comparator::equalTo(std::string term1, std::string term2)
{
    if (term1 == term2) 
    {
        return true;

    }
    else
    {
        return false; 
    }
}

bool comparator::validComparator(std::string comparator)
{
    if (comparator == ">" || comparator == ">=" || comparator == "<" || comparator == "=<"
        || comparator == "==")
    {
        return true;
    }
    else
    {
        return false;
    }

}

comparator* comparator::getInstance()
{
    if (myComparator == nullptr)
    {
        myComparator = new comparator; 
    }
    return myComparator; 
}

bool comparator::evaluateComparison(std::string term1, std::string comparator, std::string term2)
{
    if (comparator == ">")
    {
        return greaterThan(term1, term2);
    }
    if (comparator == ">=")
    {
        return greaterThanEqual(term1, term2);
    }
    if (comparator == "<")
    {
        return lesserThan(term1, term2);
    }
    if (comparator == "=<")
    {
        return lesserThanEqual(term1, term2);
    }
    if (comparator == "==")
    {
        return equalTo(term1, term2);
    }

}
