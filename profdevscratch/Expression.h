#pragma once
#include <string>
#include "dataChecker.h"
#include "operationNotSupportDataType.h"
#include  "dataConverter.h"
class Expression
{
private:
	dataChecker* myChecker = new dataChecker;
	
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
	std::string calcFull(std::string expr);


	

};

