#pragma once
#include <string>
#include <vector>

class programmingBodies
{
protected:
	/**
	 * .the pcr of the programming body so that end body can obtain it 
	 */
	int thisProgramCounterPos = 0; 
	/**
	 * .the name of the command so that it can be checked if it needs poppping or not 
	 */

	std::string commandName ="";
public:
	/**
	 * .returns the pcr of the body so that it can be used by end body like while loops 
	 * 
	 * \return returns the pcr of this body command 
	 */
	int getProgramCounterPos();
	/**
	 * .this sets the local copy of program counter of body 
	 * 
	 * \param pcr the pcr to change the local copy of pcr into 
	 */
	void setProgramCounterPos(int pcr);

	/**
	 * .returns the name of the programming body so it can be checked to be popped
	 * 
	 * \return  the name of the programming body 
	 */
	std::string getName();

	
	

};

