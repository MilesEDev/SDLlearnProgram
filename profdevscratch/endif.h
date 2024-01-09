#pragma once
#include "programmingConstructs.h"
#include "bodyEnd.h"
#include "executorManager.h"

class endIf :public programmingConstructs,public bodyEnd, public executorManager
{
public:
	/**
	 * .this is used to set parameter count
	 * 
	 */
	endIf();
	/**
	 * .this overides body end checker so that it will only throw error if it tries to pop a non-ifbody
	 * 
	 * \param bodyPCRs this is the list of bodies currently active in the program 
	 * \return this returns whether the body can be popped
	 */
	bool checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs) override;
	/**
	 * .this runs the endif command to alter execution back to true 
	 * 
	 */
	void runCommand() override;


};

