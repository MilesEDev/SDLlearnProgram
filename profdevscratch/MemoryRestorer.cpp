#include "MemoryRestorer.h"

void MemoryRestorer::clearNew(MemoryManager* currentMemory)
{
    currentMemory->deletePagetable();
}

MemoryManager* MemoryRestorer::oldToNew(MemoryManager* old)
{
    return old;
}

bool MemoryRestorer::getRestoreFlag()
{
    return restoreOldMemory;
}

bool MemoryRestorer::getClearFlag()
{
    return clearNewmemory;
}
