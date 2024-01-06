#include "commandCatFactory.h"
#include "Commands.h"
#include  "programmingConstructs.h"
#include "commandFactory.h"
#include "programmingConstructsFactory.h"


commandCat* commandCatFactory::getCommand(std::string thisCommand)
{
	commandFactory* comFactory = new commandFactory();
	Commands* currentCommand = comFactory->getCommand(thisCommand);
	if (currentCommand != nullptr)
	{
		return comFactory->getCommand(thisCommand);
	}
	programmingConstructsFactory* progFactory = new programmingConstructsFactory();
	programmingConstructs* currentConstruct = progFactory->getPointer(thisCommand);
	if (currentConstruct != nullptr)
	{
		return progFactory->getCommand(thisCommand)->getPointer();
	}

	

}
