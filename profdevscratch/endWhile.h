#pragma once
#include "programmingConstructs.h"
#include "bodyEnd.h"
#include "executorManager.h"
#include "cannotEndBody.h"

class endWhile :public programmingConstructs,public bodyEnd,public executorManager
{
public:
	/**
	 * .this sets up the parameter count for endwhile
	 * 
	 */
	endWhile();
	/**
	 * .this overides body end checker so that it will only throw error if it tries to pop a non-whilebody
	 *
	 * \param bodyPCRs this is the list of bodies currently active in the program
	 * \return this returns whether the body can be popped
	 */
	bool checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs) override;
	/**
	 * .this runs the command so that execution will be changed and the pcr will be changed according to the condition 
	 * of the while loop 
	 * 
	 */
	void runCommand() override;


};

