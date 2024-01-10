#include "ThreadManager.h"



Commands* ThreadManager::getToRun()
{
	return toRun;
}

void ThreadManager::setToRun(Commands* newToRun)
{
	toRun = newToRun;
}

