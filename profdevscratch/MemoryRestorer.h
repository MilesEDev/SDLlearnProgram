#pragma once
#include "MemoryManager.h"
class MemoryRestorer
{
protected:
	bool restoreOldMemory = false;
	bool clearNewmemory = false;

public:
	void clearNew(MemoryManager* currentMemory);

	MemoryManager* oldToNew(MemoryManager* old);

	bool getRestoreFlag();

	bool getClearFlag();

	 

	




};

