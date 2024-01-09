#pragma once
#include "Commands.h"
#include "Render.h";
class ThreadManager
{
public:
	Commands* toRun = nullptr;
	Render* mainThreadRenderer;

	void setRenderer(Render* mainThreadRendererNew);

	Render* getRenderer();

	Commands* getToRun();

	void setToRun(Commands* newToRun);
};

