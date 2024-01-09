#pragma once
#include <string>
#include "specialChar.h"
class dataChecker
{
private:

	/**
	 * .singleton instance for datachecker
	 */
	static dataChecker* myChecker;
	/**
	 * .empty constructor
	 * 
	 */
	dataChecker();
	
public:

	/**
	 * .checks to see if input is a float
	 * 
	 * \param myString the arg to check
	 * \return true for float false for non
	 */
	bool isFloat(std::string myString);
	/**
	 * .checks if input is bool 
	 * 
	 * \param myString argument to check 
	 * \return true for float false for non 
	 */
	bool isBool(std::string myString);
	/**
	 * .checks if input is string 
	 * 
	 * \param myString arg to check if is string
	 * \return true if arg is string false if non
	 */
	bool isString(std::string myString);
	/**
	 * .checks to see if a section of string is special char e.g escape sequence
	 * 
	 * \param myString the whole string to get portion of 
	 * \param charIndex the index to get specific char to begin check
	 * \return true if special char is found false if not 
	 */
	bool isSpecialChar(std::string myString, int charIndex);
	
	/**
	 * .checks the whole string for any instance it can find of a special char
	 * 
	 * \param myString the whole string to be input
	 * \return whether any special chars were found 
	 */
	bool wholeCheckForBadSpecialChar(std::string myString);

	/**
	 * .checks to see if the arg inputted is a valid data value
	 * 
	 * \param toCheck the argument to be checked
	 * \return whether arg is valid data value
	 */
	bool isValue(std::string toCheck);

	/**
	 * .obtains the function name from the whole function name with parameters
	 * 
	 * \param funcStatement the whole function name with parameters
	 * \return just the function name portion of whole func name
	 */
	std::string readFuncName(std::string funcStatement);

	/**
	 * .gets the instance of the data checker class 
	 * 
	 * \return 
	 */

	static dataChecker* getInstance();

	int getDecimalAccuracy(std::string strNum);
	/**
	 * .gets the length of the non decimal values in string
	 * 
	 * \return the length of non decimal num
	 */
	int getWholeNumLength(std::string strNum);

};


