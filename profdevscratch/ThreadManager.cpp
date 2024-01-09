#include "ThreadManager.h"

void ThreadManager::setRenderer(Render* mainThreadRendererNew)
{
	mainThreadRenderer = mainThreadRendererNew;
}

Render* ThreadManager::getRenderer()
{
	return mainThreadRenderer;
}

Commands* ThreadManager::getToRun()
{
	return toRun;
}

void ThreadManager::setToRun(Commands* newToRun)
{
	toRun = newToRun;
}

