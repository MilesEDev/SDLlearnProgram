#include "dataConverter.h"

dataConverter* dataConverter::myConverter = nullptr;


dataConverter::dataConverter(){

};

bool dataConverter::stringToBool(std::string myStr)
{
    
    if (SDL_strcasecmp(myStr.c_str(), "true"))
    {
        return true;
    }
    else if (SDL_strcasecmp(myStr.c_str(), "false"))
    {
        return false;
    }
    else
    {

    }
    
}

std::string dataConverter::boolToString(bool myBool)
{
    if (myBool) 
    {
        return "true";;
    }
    else
    {
        return "false";
    }
}

std::string dataConverter::sliceQoutes(std::string stringToSlice)
{
    return stringToSlice.substr(1, stringToSlice.size()-2);
}

std::string dataConverter::addQoutes(std::string stringToAdd)
{
    return "\"" + stringToAdd + "\"";
}

std::string dataConverter::removeSpecialChars(std::string stringToRemove)
{
    bool key = true;
    specialCharManager* mySpecialChar = new specialCharManager(); 
   
    std::string* specialChars = mySpecialChar->getSpecialChars();
        
    std::string specialChar;
    int i = 0;
    for (i = 0; i< mySpecialChar->getNumChars();i++) 
    {
        specialChar = mySpecialChar->getSingleSpecialChar(i);
        for (int k = 0; k < stringToRemove.size() - 1;k++)
        {
            char testChar = stringToRemove[k];
            key = true;
            for (int j = 0; j < specialChar.size(); j++)
            {
                testChar = stringToRemove[k+j];
                if (stringToRemove[k + j] != specialChar[j])
                {
                    key = false;
                    break;
                    
                }
            }
            if (key)
            {
                

                std::string replace = "";
                replace = replace + specialChar[1];
                

                stringToRemove = stringToRemove.replace(k, specialChars->size(), replace);

            }
        }
    }
    
    return stringToRemove;
}

std::string dataConverter::doubleNegative(std::string argument)
{
    if (argument[0] == '-')
    {
        if (argument[1] == '-')
        {
            return argument.substr(2, argument.size() - 3);
        }
    }
    return argument;
}

dataConverter* dataConverter::getInstance()
{
   
    if (dataConverter::myConverter == nullptr)
    {
        dataConverter::myConverter = new dataConverter;
    }
    return dataConverter::myConverter;
}
