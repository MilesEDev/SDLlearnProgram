#pragma once
class executorManager
{
protected:
	/**
	 * .the local exeuction to be changed by all commands that implmenet executor mamanger
	 */
	bool localExecution = false;
public:
	/**
	 * .sets local command execution so child commands know what current state is
	 * 
	 * \param Execution the current execution state
	 */
	void setLocalExecution(bool Execution);

	/**
	 * .returns the execution after command is run to change the execution state
	 * 
	 * \return the new execution state
	 */
	bool getLocalExecution();
};

