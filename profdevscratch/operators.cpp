#include "operators.h"

bool operators::greaterThan(std::string term1, std::string term2)
{
    dataChecker* myChecker = new dataChecker();
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

bool operators::greaterThanEqual(std::string term1, std::string term2)
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

bool operators::lesserThan(std::string term1, std::string term2)
{
    dataChecker* myChecker = new dataChecker();
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

bool operators::lesserThanEqual(std::string term1, std::string term2)
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

bool operators::equalTo(std::string term1, std::string term2)
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
