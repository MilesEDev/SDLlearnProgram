#pragma once
#include "dataChecker.h"
#include <typeinfo>
#include <vector>
#include "dataConverter.h"
class commandCat
{
protected:
	/**
	 * .the parameter count for every command 
	 */
	int parameterno = 0;
	/**
	 * .the data checker object every command can use to check data
	 */
	dataChecker* myChecker = dataChecker::getInstance();


	/**
	 * .the data converter object every command can use for data conversions
	 */
	dataConverter* myConverter = dataConverter::getInstance(); 

	/**
	 * . parsed attributes list in case numbers need to be stored 
	 */
	std::vector<int> parsedAttributes;
public:
	/**
	 * .function for checking param count is same as user entered
	 * 
	 * \param numParams the number of params the user has entered
	 * \return the succsess of whether param count matches or not 
	 */
	virtual bool correctParamsCount(int numParams);

};

