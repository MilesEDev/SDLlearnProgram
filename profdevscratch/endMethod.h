#pragma once
#include "programmingConstructs.h"
#include "bodyEnd.h"
#include "executorManager.h"
#include "MemoryRestorer.h"
#include "cannotEndBody.h"

class endMethod :public programmingConstructs,public bodyEnd, public executorManager,public MemoryRestorer
{
public:
	/**
	 * .this sets up the parameter count for endmethod
	 */
	endMethod();
	/**
	 * .this overides body end checker so that it will only throw error if it tries to pop a non-ifbody
	 * 
	 * \param bodyPCRs the list of bodies that are currently active
	 * \return whether the body can be popped off 
	 */
	bool checkCorrectEnd(std::vector<programmingBodies*> bodyPCRs) override;
	/**
	 * .this alters execution and the PCR so that it returns to the correct place and properly continues
	 * execution
	 * 
	 */
	void runCommand() override;


};

