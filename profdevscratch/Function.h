#pragma once
#include "MemoryManager.h"
#include "dataChecker.h"
class Function
{
	/**
	 * .this is the private memory of the function so that there is no global vars
	 */
	MemoryManager* functionMemory = new MemoryManager();
	/**
	 * .this is the pcr of where the definition of the method so that the function can switch to it when called
	 */
	int MethodDefPcr;
	/**
	 * .this is the function name so that it can be identified when called
	 */
	std::string functionName = "";
	/**
	 * .this is the parameter list so that the function can check the num args are correct
	 */
	std::vector<std::string> parameterNames;
	/**
	 * .these are the args that are to be uploaded to memory under the name of the  parameters
	 */
	std::vector<std::string> Arguments;
	
	/**
	 * .this is the data checker to be used for checking data
	 */
	dataChecker* myChecker = dataChecker::getInstance();
	
public:
	
	/**
	 * .this is the constructor to set up parameters and the function name
	 * 
	 * \param wholeFuncName this is the input from the user to provide the context needed to set up function
	 */
	Function(std::string wholeFuncName);
	/**
	 * .this sets up the methoddefpcr
	 * 
	 * \param Pcr the pcr to have methoddefpcr set to
	 */
	void setMethodDefPcr(int Pcr);
	
	
	  /**
	   * .this sets the function name 
	   * \param wholeArgument this is input by user to have the name extracted from
	   */
	void setFunctionName(std::string wholeArgument); 
	/**
	 * .this updates the memory in execution to be the memory of the function 
	 * 
	 * \return the functions memory
	 */
	MemoryManager* updateMemory();
	/**
	 * .this makes sure the number of arugments inputted matches the number of parameters
	 * 
	 * \return succsess of the syntax check 
	 */
	bool syntaxCheck();
	/**
	 * .this makes sure that the params are of appropiate names
	 * 
	 * \return  the succesfulness of the syntax check 
	 */
	bool syntaxCheckParams();
	/**
	 * .this gets the parameters or aguments from the bracket portion of func name and sets them to the appropiate params or arguments vector
	 * 
	 * \param paramsOrArgs the parameters or arguments to be inputted 
	 * \param paramsOrArgsVector the vector for the arguments/parameters to add to 
	 */
	void extractParams(std::string paramsOrArgs,std::vector<std::string> &paramsOrArgsVector);
	/**
	 * .this adds the arguments to memory so that they can be retrieved from execution 
	 * 
	 */
	void addArgsToMemory();
	/**
	 * .this gets the name of the function
	 * 
	 * \return retursn the name of the function 
	 */
	std::string getName();
	/**
	 * .this sets the arguments this is used alongside extract to make sure the previous args are cleared before extraction
	 * 
	 * \param wholeStatement the whole function name inputted by user 
	 */
	void setArgs(std::string wholeStatement);
	/**
	 * .returns the method definition pcr 
	 * 
	 * \return the method definition pcr
	 */
	int getMethodDefPcr();






	








};

