#pragma once
#include <string>
class specialCharManager
{
private:
	/**
	 * .singleton instance of specialcharmanger
	 */
	static specialCharManager* mySpecialManager;
	/**
	 * .currently supported list of special escape sequence chars
	 */
	std::string specialChars[2] = { "\\\\","\\\"" };
	/**
	 * .empty constructor
	 * 
	 */
	specialCharManager();
public:
	/**
	 * .returns the specialchars array
	 * 
	 * \return 
	 */
	std::string* getSpecialChars();
	/**
	 * .gets a single special char
	 * 
	 * \param iterator the index for the single special char you want
	 * \return the single special char at index from specialchars array
	 */
	std::string getSingleSpecialChar(int iterator);
	/**
	 * .gets current number of supported special chars
	 * 
	 * \return number of supported special chars
	 */
	int getNumChars();
	/**
	 * .gets the singleton intance of special chars
	 * 
	 * \return the singleton instance of special char
	 */
	static specialCharManager* getInstance();

};

