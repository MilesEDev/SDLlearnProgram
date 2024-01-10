#pragma once
#include "Commands.h"
#include "Render.h";
class ThreadManager
{
public:
	/**
	 * .the gui command to run
	 */
	Commands* toRun = nullptr;

	/**
	 * .this returns the GUI command to be run
	 * 
	 * \return 
	 */
	Commands* getToRun();
	/**
	 * .this sets the GUI command to be run
	 * 
	 * \param newToRun the new GUI command to run
	 */
	void setToRun(Commands* newToRun);
};

