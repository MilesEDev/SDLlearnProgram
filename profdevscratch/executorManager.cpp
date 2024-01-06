#include "executorManager.h"

void executorManager::setLocalExecution(bool Execution)
{
	localExecution = Execution;
}

bool executorManager::getLocalExecution()
{
	return localExecution;
}
