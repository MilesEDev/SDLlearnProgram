#pragma once
#include <string>
#include "dataChecker.h"
#include "dataConverter.h"
class comparator
{
private:
	/**
	 * .the singleton intance for comparator
	 */
	static comparator* myComparator; 

	/**
	 * .data checker used for checking data 
	 */
	dataChecker* myChecker = dataChecker::getInstance();
	/**
	 * .empty constructor
	 */
	comparator(); 
	/**
	 * .checks to see if term1 is greather than term2
	 * 
	 * \param term1 the first value to see if is greater than
	 * \param term2 the second value to see if is smaller than
	 * \return whether term1 is greater them term2 
	 */
	bool greaterThan(std::string term1, std::string term2);
	/**
	 * .checks to see if term1 is greather than term2
	 *
	 * \param term1 the first value to see if is greater than or equalt to
	 * \param term2 the second value to see if is smaller than or equal to 
	 * \return whether term1 is greater them term2 or equal to it 
	 */
	bool greaterThanEqual(std::string term1, std::string term2);
	/**
	 * .checks to see if term1 is greather than term2
	 *
	 * \param term1 the first value to see if is smaller than
	 * \param term2 the second value to see if is greater than
	 * \return whether term1 is greater them term2
	 */
	bool lesserThan(std::string term1, std::string term2);
	/**
	 * .checks to see if term1 is greather than term2
	 *
	 * \param term1 the first value to see if is greater than
	 * \param term2 the second value to see if is smaller than
	 * \return whether term1 is greater them term2 or equal to it 
	 */
	bool lesserThanEqual(std::string term1, std::string term2);
	/**
	 * .used to see if term1 is equal to term 2
	 * 
	 * \param term1 the first input to see if is equal to
	 * \param term2 the second input to see if is equal to 
	 * \return whether the two terms are equal to each other 
	 */
	bool equalTo(std::string term1, std::string term2);
	/**
	 * .used to see if term 1 and term 2 are not equal to each other
	 * 
	 * \param term1 the first input to see  if not equal to 
	 * \param term2 the second input to see if  not equal to 
	 * \return whether the two terms are equal or not 
	 */
	bool notEqualTo(std::string term1, std::string term2);
	
public:
	/**
	 * .takes in both terms and the comparator to perform the correct operations and return result
	 * 
	 * \param term1 the first term to be used in operation
	 * \param comparator the comparator used to choose which operation to perform
	 * \param term2 the second term to be used in operation
	 * \return  the result of the chosen operation
	 */
	bool evaluateComparison(std::string term1, std::string comparator, std::string term2);
	/**
	 * .checks to see if inputted comparator is a real comparator 
	 * 
	 * \param comparator the comparator to be input
	 * \return whether inputted comparator is a supported comparator
	 */
	bool validComparator(std::string comparator);
	/**
	 * .gets the singleton instance for comparator 
	 * 
	 * \return 
	 */
	static comparator* getInstance();

};

