#pragma once
#include <vector>
#include <string>
#include "programmingBodies.h"
class bodyEnd
{
protected:
	/**
	 * .this is the pcr to be returned if the command changes pcr 
	 */
	int newPCR = -1;
	/**
	 * .this stores the pcr of the last body so things like loops can go back to original body 
	 */
	int lastBodyPCR = 0;
public:
	/**
	 * .this pops body from list so signify that the body is no longer being used in execution 
	 * 
	 * \param bodyPCRs these are the list of bodies 
	 * \return this returns the vector of the new programming body list after the pop 
	 */
	std::vector<programmingBodies*> popFromBodyList(std::vector<programmingBodies*> bodyPCRs);
	/**
	 * .this checks to make sure that the correct end if links to the correct body (virtual method to make sure that
	 * each endbody can change name of the body that is allowed to be popped)
	 * 
	 * \param bodyPCRs this is the list of bodies that should have check on 
	 * \return this returns whether the pop can be performed or not 
	 */
	virtual bool checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs) =0 ;
	/**
	 * .this sets the pcr so that the body end can link up to the body for things lik while loops
	 * 
	 * \param bodyPCRs this is the list of bodies the pcr is to be obtained from 
	 */
	void setCurrentBodyPCR(std::vector<programmingBodies*> bodyPCRs);
	/**
	 * .this returns the new pcr after the body end has been run 
	 * 
	 * \param pcr the input pcr so that it can return it back if no changes made to pcr 
	 * \return the new pcr for execution to follow 
	 */
	int getNewPCr(int pcr);
};

