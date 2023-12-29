#pragma once
#include <vector>
#include <string>
class IArgManager
{
	
public:
	/**
	 * .parses and stored command arguments e.g sets strings to ints
	 *
	 * \param commandArgs to take in and convert to int or not
	 * \return whether opertion was succesful or not
	 */
	virtual void setAttributes(std::vector<std::string> commandArgs) = 0;


	/**
	 * 
	 * .checks arguments to see if they match the commands parameter list
	 * 
	 * \param commandArgs the string arguments that will be input
	 * \return the succesfullnes of the syntax check 
	 */
	virtual bool syntaxcheck(std::vector<std::string> commandArgs) = 0;
};

