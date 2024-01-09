#pragma once
#include <SDL_stdinc.h>
#include <string>
#include "specialChar.h"
class dataConverter
{
private:
    /**
     * .the single instance of the myconverter class 
     */
    static dataConverter* myConverter;
    /**
     * .empty constructor 
     * 
     */
    dataConverter();
    
public:
    /**
     * .converts a string to a boolean value 
     * 
     * \param myStr the string to be converted
     * \return the converted value
     */
    bool stringToBool(std::string myStr);
    /**
     * .transforms the boolean value to a string 
     * 
     * \param myBool the boolean value
     * \return converted bool value
     */
    std::string boolToString(bool myBool);
    /**
     * .slices the qoutes off a strin
     * 
     * \param stringToSlice the string to have sliced
     * \return the sliced string
     */
    std::string sliceQoutes(std::string stringToSlice);
    /**
     * .add qoutes to a regular string on start and end
     * 
     * \param stringToAdd the string to have qoutes added too
     * \return the new string with qoutes added
     */
    std::string addQoutes(std::string stringToAdd);
    /**
     * .removes all special chars from a user string and converts them to standard behind the scenes
     * escape sequences e.g if a user entered "hello{slash}"there" it will remove the slash for output
     * 
     * \param stringToRemove string to have special chars removed from
     * \return the string with no special chars
     */
    std::string removeSpecialChars(std::string stringToRemove);
    /**
     * .if a number has two negatives it removes them to the new number is positive
     * 
     * \param argument the double negative number
     * \return the new positive number
     */
    std::string doubleNegative(std::string argument);
    /**
     * .returns the singleton instance of converter
     * 
     * \return the singleton instance 
     */
    static dataConverter* getInstance();


};