#pragma once
#include "MemoryManager.h"
class MemoryRestorer
{
protected:
	/**
	 * .a flag to show whether old memory in execution should be restored to current memory 
	 */
	bool restoreOldMemory = false;
	/**
	 * .a flag to show whether current memory in execution should be cleared 
	 */
	bool clearNewmemory = false;

public:
	/**
	 * .this clears the current memory 
	 * 
	 * \param currentMemory the current memory to be input so that it can be cleared
	 */
	void clearNew(MemoryManager* currentMemory);

	/**
	 * .the old memory to be restored to current memory
	 * 
	 * \param old this is used to allow current memory to match this argument old memory 
	 * \return old memory to be made current
	 */
	MemoryManager* oldToNew(MemoryManager* old);
	/**
	 * .returns the flag for whether old memory should be restored to current
	 * 
	 * \return the flag for restoring memory 
	 */
	bool getRestoreFlag();
	/**
	 * .returns the flag for whether the current memory should be cleared
	 * 
	 * \return the flag for clearing current memory 
	 */
	bool getClearFlag();

	 

	




};

