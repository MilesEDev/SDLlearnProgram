#pragma once
#include <string>
class Page
{
private:
	/**
	 * .the variable name linked to this page
	 */
	std::string varName;
	/**
	 * .the data type linked to this page variable
	 */
	std::string dataType;
	/**
	 * .void pointer to be assigned to value
	 */
	void* varPtr;
	/**
	 * .the size of data stored in varPtr
	 */
	int size; 
public:
	/**
	 * .sets the var name in page variable
	 * 
	 * \param newName the newName to change this page name to
	 */
	void setVarName(std::string newName);
	/**
	 * .returns the current page name
	 * 
	 * \return the current page name
	 */
	std::string getVarName();
	/**
	 * .this sets a new data type for this page
	 * 
	 * \param newDataType the new data type to set this page to
	 */
	void setDataType(std::string newDataType);
	/**
	 * .this returns the current data type of this page
	 * 
	 * \return this returns the current data type of page
	 */
	std::string getDataType();
	/**
	 * .this sets the var pointer to new value
	 * 
	 * \param newPtr the new value to set varPtr to
	 */
	void setVarPtr(void* &newPtr);
	/**
	 * .this returns the current varptr linking to value from page
	 * 
	 * \return the current varptr linking to value
	 */
	void* getVarPtr();
	/**
	 * .this sets the new size of the value assigned to page
	 * 
	 * \param size the new size of value
	 */
	void setVarSize(int size);
	/**
	 * .this returns the current size of value in page
	 * 
	 * \return the size of the page value
	 */
	int getVarSize();



	
};

