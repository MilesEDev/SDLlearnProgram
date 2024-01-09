#pragma once
#include <string>
#include "dataChecker.h"
#include "operationNotSupportDataType.h"
#include  "dataConverter.h"
#include "MemoryManager.h"
class Expression
{
private:
	dataChecker* myChecker = dataChecker::getInstance();
	dataConverter* myConverter = dataConverter::getInstance();
	std::string priorites[4] = { "/","*","+","-" };
	
	/**
	 * .this is used to add terms together be they strings or intergers
	 * 
	 * \param term1 this is the first term to be added 
	 * \param term2 this is the second term to be added together 
	 * \return the result of adding term 1 and term 2 together 
	 */
	std::string add(std::string term1,std::string term2);
	/**
	 * .this is used to subtract terms tgether for integers/floats
	 * 
	 * \param num1 this is the first number that a value will be subtracted from
	 * \param num2 this is the amount that will be subtracted from the first number
	 * \return this will give the result of the operation 
	 */
	std::string subtract(std::string num1, std::string num2);
	/**
	 * .this is used to multiply terms together for intergers/floats
	 * 
	 * \param num1 this is the first number that will be multiplied by term2
	 * \param num2 this is the multiplier for multplieing the first number by 
	 * \return this is the return of the operation  
	 */
	std::string multiply(std::string num1,std::string num2);
	/**
	 * .this is ued to divide terms for integers/floats
	 * 
	 * \param num1 this is the first number this will be divided from 
	 * \param num2 this is the second number that will act as the divisor 
	 * \return this will return the result of the division operation 
	 */
	std::string divide(std::string num1, std::string num2);

	
	/**
	 * .this checks to see if a substring is an operation string is used here to allow for later additions of sqaure and sqaure root(**) and sqaure(//)
	 * 
	 * \param expr this is the expression that will be sub-stringed
	 * \param subStr this is the value that will be used to obtain the substr from the expression
	 * \param operation this is the operation that is being compared too
	 * \return this will return if there has been succsess in finding the operation or not 
	 */
	bool isOperation(std::string expr, int subStr, std::string operation);
public:
	/**
	 * .this will do the full calculation of an expression by finding operators and terms in an expression and than outputting a result 
	 * 
	 * \param expr this is the expression that will be input by the user
	 * \return the output of the expression 
	 */
	std::string calcFull(std::string expr,MemoryManager* myManager);

	/**
	 * .checkst to see if input is an expression
	 * 
	 * \param exprOrVal the input to have checked if expression
	 * \return if is expression or not
	 */
	bool isExpression(std::string exprOrVal);
	/**
	 * .checks to see if a substring is an operation
	 * 
	 * \param expr the whole string to have checked
	 * \param subStr the index showing where to check substrings
	 * \return whether the substr is an opration
	 */
	bool isAnyOperation(std::string expr, int subStr);
	/**
	 * .checks to see if input is an attempted assignment
	 * 
	 * \param exprOrVal the input to be checked
	 * \return whether the input is an attempted assignment
	 */
	bool isAssignment(std::string exprOrVal);
	/**
	 * .gets the name of the variable that is to be assigned tooo 
	 * \return the name of the variable
	 */
	std::string getVarName(std::string exprOrVal); 
	/**
	 * .performs the assignment updating the value of the var to output of expression or simply the value input
	 * 
	 * \param assignmentStatement the whole assignment statement to gather name and value from with getvarname and getassignmentvalue
	 * \param memory the memory pointer used to upload the completed assigned var to memory
	 */
	void performAssignment(std::string assignmentStatement,MemoryManager* memory);
	/**
	 * .make sure that the value to be input into performassignment is either an expression or data value
	 * 
	 * \param value the value or expression to be input to performassignment
	 * \param memory memorypointer used to check if values are variables
	 * \return 
	 */
	bool checkAssignmentValue(std::string value,MemoryManager* memory);
	/**
	 * .this obtains the value or expression from an assignment statement 
	 * 
	 * \param assignmentStatement the whole assignment state to have value or exression extracted from 
	 * \return the value of expression 
	 */
	std::string getAssignmentValue(std::string assignmentStatement);
	/**
	 * .checks if an expression contains a variable which may be valid but reliant on a parameter 
	 * 
	 * \param expression the expression to have checked
	 * \param toDefinesChecker the memory pointer containing list of variables to be defined 
	 * \return whether any arguments in expression matched any todefine vars 
	 */
	bool hasToDefines(std::string expression,MemoryManager* toDefinesChecker);

};

