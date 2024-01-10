#pragma once
#include <string>
#include "Page.h"
#include <vector>
#include "dataConverter.h"
#include "dataChecker.h"
#include <regex>
#include "commandCatFactory.h"
#include "memoryUnsupportedType.h"
#include "erroneousVarName.h"
class MemoryManager
{
private:
	/**
	 * .data checker object for checking data
	 */
	dataChecker* myChecker = dataChecker::getInstance();
	/**
	 * .page table stores memory pages containing variable data name and data type
	 */
	std::vector<Page*> PageTable;
	/**
	 * .this stores any variables like parameters which are not defined yet but will be on execution
	 */
	std::vector <std::string> varsToDefine = {};
	/**
	 * .this is a page that is to be added to memory next 
	 */
	Page* pageToAdd;
public:
	
	/**
	 * .this creates a page and puts it in memory and the page table
	 * 
	 * \param varName the variable name to put in memory and page table
	 * \param varValue the value of the variable to update var too
	 */
	void createPage(std::string varName,std::string varValue);
	/**
	 * .this either adds a new page or alters the value of an existing one
	 * 
	 * \param varValue the value to upload to new or existing variable
	 * \param pageToEdit the existing or new page update to memory 
	 * \return this returns the page that has been altered
	 */
	Page* alterPage(std::string varValue,Page* pageToEdit);
	/**
	 * .this gets the value from a variable 
	 * 
	 * \param varName this is used to identify the variable to get value from
	 * \return the value gathered from var
	 */
	std::string returnValue(std::string varName);
	/**
	 * .this is used to make sure variables are not given names like command names or put in data format e.g nums
	 * 
	 * \param varName the variable name to be checked
	 * \return whether the variable is allowed or not
	 */
	bool BannedVarNames(std::string varName);
	/**
	 * .this is to make sure that a variable contains no special characters
	 * 
	 * \param varName the varname to check for special  characters
	 * \return if variable has special chars or not
	 */
	bool BannedChars(std::string varName);
	/**
	 * .this alters memory for updates but does not add a new entry to page table
	 * 
	 * \param varName the varname to identify variable to update
	 * \param varValue the new value to set the variable too
	 */
	void updateValue(std::string varName,std::string varValue);
	/**
	 * .this checks to see if variable exists and if validation is ok and var does not exist updates 
	 * page table and memory else it just updates var value
	 * 
	 * \param varName the variable name to identify variable
	 * \param varValue the value to set variable too
	 * \return the succsess of page creation or update
	 */
	bool pageCreationAndUpdate(std::string varName, std::string varValue);
	/**
	 * .checks to see if a variable exists with varname input
	 * 
	 * \param varName the var name to search for 
	 * \return whether the var exists or not
	 */
	bool pageExist(std::string varName);
	/**
	 * .this uses both bannedchars and bannednames to do a full validation check on varname
	 * 
	 * \param varName the varname to be fully checked
	 * \return whether the variable is a good name
	 */
	bool isGoodVarName(std::string varName);
	/**
	 * .this clears the page table
	 * 
	 */
	void deletePagetable();
	/**
	 * .this checks to see if a variable value is attempted to be obtained where the var is in isToDefine
	 * 
	 * \param the value being checked to see if in isToDefine
	 * \return whether the variable is in isToDefine
	 */
	bool isToDefine(std::string value);
	/**
	 * .checks to see if any value in a vector of values is in toDefine
	 * 
	 * \param values the list of values to be checked
	 * \return whether any values were found to be in isToDefine
	 */
	bool isAnyToDefine(std::vector<std::string> values);
	/**
	 * .this sets toDefine with function parameters to begin with 
	 * 
	 * \param newParameters the set of parameters to put in isToDefine
	 */
	void setToDefine(std::vector<std::string> newParameters);
	/**
	 * .this adds a new variable name to isToDefine
	 * 
	 * \param varName the varname to add to isToDefine
	 */
	void addVarToToDefines(std::string varName);
	/**
	 * .remove an entry from isToDefine
	 * 
	 * \param varName the name to remove in isToDefine
	 */
	void deleteToDefineEntry(std::string varName);
	/**
	 * .this clears all values in isToDefine
	 * 
	 */
	void clearToDefine();
	

};

