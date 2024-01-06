#pragma once
class executorManager
{
protected:

	bool localExecution = false;
public:
	void setLocalExecution(bool Execution);

	bool getLocalExecution();
};

