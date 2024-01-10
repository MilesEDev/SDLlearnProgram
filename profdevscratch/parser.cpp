#include "parser.h"
#include <boost/algorithm/string.hpp>


parser::parser() 
{

}


void parser::splitToCommands(std::string program)
{
	int pos =1;
	int pos2 =1;
	std::string line;
	std::string arg;
	std::string saveline;
	std::string saveprogram;
	while(pos > -1)
	{
		pos = program.find("\n");
		line = program.substr(0, pos);
		
		splitToArguments(line);
		
		if (program == saveprogram.erase(0, pos)) {

			break;
		}
		else {
			program = program.erase(0, pos+1);
		}

		commands.push_back(arguments);
		arguments.clear();
	}
}

void parser::clearAllLists()
{
	arguments.clear();
	commands.clear();
}

std::string parser::syntaxCheckAll()
{
	std::string error = "";

	commandFactory* myFactory = commandFactory::getInstance();
	programmingConstructsFactory* constructFactory = programmingConstructsFactory::getInstance();
	line = 0;
	

	for (int pcr = 0; pcr < commands.size(); pcr++)
	{
		try
		{
			std::vector<std::string> command = commands.at(pcr);
			line = pcr+1;

			commandCatFactory* myfact = new commandCatFactory();

			commandCat* abstractCommand = myfact->getCommand(command.at(0));


			if (abstractCommand != nullptr)
			{
				if (!programMemory->isAnyToDefine(command))
				{

					checkForAll(command, programMemory);
					int size = command.size() - 1;
					if (!abstractCommand->correctParamsCount(size))
					{
						throw InvalidParameters("you have entered the incorrect number of parameters");
					}
					if (size > 0)
					{

						IArgManager* argChecker = dynamic_cast<IArgManager*>(abstractCommand);
						std::vector<std::string> commandArgs;
						for (int i = 1; i < command.size(); i++)
						{
							commandArgs.push_back(command.at(i));

						}

						argChecker->syntaxcheck(commandArgs);
					}
				}
				if (constructFactory->hasKey(command.front(), "body"))
				{
					programmingBodies* mybody = dynamic_cast<programmingBodies*>(abstractCommand);
					bodyPCRs.push_back(mybody);
				}
				if (constructFactory->hasKey(command.front(), "bodyend"))
				{
					bodyEnd* myBodyEnd = dynamic_cast<bodyEnd*>(abstractCommand);
					myBodyEnd->checkCorrectEnd(bodyPCRs);
					myBodyEnd->setCurrentBodyPCR(bodyPCRs);
					bodyPCRs = myBodyEnd->popFromBodyList(bodyPCRs);//if any bodies left chuck error at end

				}
				if (command.front() == "method")
				{
					Function* newFunc = new Function(command.at(1));
					oldMemory = programMemory;
					programMemory = newFunc->updateMemory();
					
					callTable.push_back(newFunc);

				}
				if (constructFactory->hasKey(command.front(), "memory"))
				{
					MemoryRestorer* myMemory = dynamic_cast<MemoryRestorer*>(abstractCommand);
					if (myMemory->getClearFlag())
					{
						myMemory->clearNew(programMemory);
					}
					if (myMemory->getRestoreFlag())
					{
						programMemory = myMemory->oldToNew(oldMemory);
						
					}

				}


			}
			else
			{
				bool key = false;
				Expression* myExpression = new Expression();
				std::string statement = command.front();
				if (myExpression->isAssignment(statement))
				{
					std::string exprName = myExpression->getVarName(statement);
					if (programMemory->isToDefine(exprName))
					{
						programMemory->deleteToDefineEntry(exprName);
					}
					std::string value = myExpression->getAssignmentValue(statement);
					
					if ((programMemory->isToDefine(value) || myExpression->hasToDefines(value,programMemory)) && !programMemory->pageExist(value))
					{
						programMemory->addVarToToDefines(exprName);
						key = true;
					}
					else
					{
						if (myExpression->checkAssignmentValue(value, programMemory))
						{
							if (programMemory->isGoodVarName(myExpression->getVarName(statement)))
							{
								myExpression->performAssignment(statement, programMemory);
								key = true;
							}
						}
					}



				}
				if (!key)
				{
					for (Function* func : callTable)
					{

						if (myChecker->readFuncName(command.at(0)) == func->getName())
						{
							func->setArgs(command.at(0));
							programMemory->clearToDefine();
							
							func->syntaxCheck();
							key = true;
						}

					}
				}
				if (!key)
				{
					throw notcommandexception("you have entered something that is not a command nore an assignment");
				}


			}
		}


		catch (nonStringException& e)
		{
			
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";

		}
		catch (nonnumberexception& e)
		{
			
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (InvalidParameters& e)
		{
		
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (nonfillvalue& e)
		{
			
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (operationNotSupportDataType& e)
		{
		
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (memoryUnsupportedType& e)
		{
			
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (erreneousVarName& e)
		{
			
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (variableIsUndefined& e)
		{
		
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (notcommandexception& e)
		{

			error=error+e.returnError() + " on line " + std::to_string(line)+"\n";
		}
		catch (cannotEndBody& e)
		{
			error = error + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		
	}
	for (programmingBodies* body : bodyPCRs)
	{
		try
		{
			bool a = 1;
			throw unEndedBody("syntax error unEndedbody on line " + std::to_string(body->getProgramCounterPos() + 1));
		}
		catch (unEndedBody& e)
		{
			error = error + e.returnError();
		}
	}
	if (error == "")
	{
		error = "ok";
	}
	programMemory->deletePagetable();
	bodyPCRs.clear();
	callTable.clear();

	return error;
}
				
				
			
		
		
	





std::pair < SDL_Texture*, std::string> parser::runForAll(Render* myrenderer,SDL_Texture* mytext)
{
	

	SDL_SetRenderTarget(myrenderer->getSDLRenderer(), mytext);
	SDL_SetRenderDrawColor(myrenderer->getSDLRenderer(), 255, 255, 255, 255);
	SDL_RenderClear(myrenderer->getSDLRenderer());
	myrenderer->setPenColourRGBA(0, 0, 0, 0);
	myrenderer->setFill(false);
	myrenderer->setPen(0, 0);

	
	std::string error = "";
	int line = 0;
	commandFactory* myComFactory = commandFactory::getInstance(); 
	programmingConstructsFactory* constructFactory = programmingConstructsFactory::getInstance();
	bool execution = true;
	executorManager* myExecutor = nullptr;
	bodyEnd* myBodyEnd = nullptr;
	

	for (int pcr = 0; pcr < commands.size(); pcr++)
	{
		try
		{
			line = pcr + 1;
			std::vector<std::string> command = commands.at(pcr);

			commandCatFactory* myfact = new commandCatFactory();
			commandCat* abstractCommand = myfact->getCommand(command.at(0));

			std::vector<std::string> commandArgs;
			commandArgs.clear();
			if (abstractCommand != nullptr)
			{
				if (execution)
				{
					checkForAll(command, programMemory);

					if (!abstractCommand->correctParamsCount(0))
					{
						for (int i = 1; i < command.size(); i++)
						{
							commandArgs.push_back(command.at(i));

						}


						IArgManager* argChecker = dynamic_cast<IArgManager*>(abstractCommand);
						if (argChecker->syntaxcheck(commandArgs))
						{
							argChecker->setAttributes(commandArgs);
						}
					}


				}



				if (constructFactory->hasKey(command.front(), "body"))
				{
					programmingBodies* mybody = dynamic_cast<programmingBodies*>(abstractCommand);
					mybody->setProgramCounterPos(pcr);
					bodyPCRs.push_back(mybody);
				}
				if (constructFactory->hasKey(command.front(), "bodyend"))
				{
					myBodyEnd = dynamic_cast<bodyEnd*>(abstractCommand);
					myBodyEnd->checkCorrectEnd(bodyPCRs);
					myBodyEnd->setCurrentBodyPCR(bodyPCRs);
					bodyPCRs = myBodyEnd->popFromBodyList(bodyPCRs);//if any bodies left chuck error at end

				}
				if (constructFactory->hasKey(command.front(), "execute"))
				{
					myExecutor = dynamic_cast<executorManager*>(abstractCommand);
					myExecutor->setLocalExecution(execution);


				}
				if (execution || (bodyPCRs.size() == 0 && constructFactory->hasKey(command.front(), "bodyend")))
				{
					if (myComFactory->getCommand(command.at(0)) != nullptr)
					{
						Commands* current_Command = dynamic_cast<Commands*>(abstractCommand);
						current_Command->runCommand(myrenderer, myrenderer->getPen());
					}

					else if (constructFactory->getCommand(command.at(0)) != nullptr)
					{
						programmingConstructs* currentConstruct = dynamic_cast<programmingConstructs*>(abstractCommand);
						currentConstruct->runCommand();
					}
				}

				if (constructFactory->hasKey(command.front(), "execute"))
				{
					execution = myExecutor->getLocalExecution();
				}
				if (constructFactory->hasKey(command.front(), "bodyend"))
				{
					pcr = myBodyEnd->getNewPCr(pcr);

				}
				if (command.front() == "method")
				{
					Function* newFunc = new Function(command.at(1));
					oldMemory = programMemory;
					programMemory = newFunc->updateMemory();
					newFunc->setMethodDefPcr(pcr);
					callTable.push_back(newFunc);


				}
				if (constructFactory->hasKey(command.front(), "memory"))
				{
					MemoryRestorer* myMemory = dynamic_cast<MemoryRestorer*>(abstractCommand);
					if (myMemory->getClearFlag())
					{
						myMemory->clearNew(programMemory);
					}
					if (myMemory->getRestoreFlag())
					{
						programMemory = myMemory->oldToNew(oldMemory);
					}

				}
			}
			else
			{
				if (execution)
				{
					Function* newFunc = isFunc(callTable, command.at(0));
					Expression* myExpression = new Expression();
					std::string statement = command.front();
					if (myExpression->isAssignment(statement))
					{
						std::string value = myExpression->getAssignmentValue(statement);

						if (myExpression->checkAssignmentValue(value, programMemory))
						{
							if (programMemory->isGoodVarName(myExpression->getVarName(statement)))
							{
								myExpression->performAssignment(statement, programMemory);
							}
						}
					}
					else if (newFunc != nullptr)
					{

						newFunc->setArgs(command.at(0));
						newFunc->addArgsToMemory();
						methodCommand* methoCom = new methodCommand();
						methoCom->setProgramCounterPos(pcr + 1);
						bodyPCRs.push_back(methoCom);
						pcr = newFunc->getMethodDefPcr();
						
						oldMemory = programMemory;
						programMemory = newFunc->updateMemory();


					}

				}


			}

		}
		
		catch (nonStringException& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";

		}
		catch (nonnumberexception& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (InvalidParameters& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (nonfillvalue& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (operationNotSupportDataType& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (memoryUnsupportedType& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (erreneousVarName& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (variableIsUndefined& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (notcommandexception& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (cannotEndBody& e)
		{
			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
	}
	
		for (programmingBodies* body : bodyPCRs)
		{
			try
			{
				bool a = 1;
				throw unEndedBody("run time error unEndedbody on line " + std::to_string(body->getProgramCounterPos() + 1));
			}
				catch(unEndedBody& e)
				{
					error = error + e.returnError();
				}
		}
	

	

	myrenderer->removeAnyTargets();
	callTable.clear();
	bodyPCRs.clear();
	execution = true;
	programMemory->deletePagetable();
	if (error == "")
	{
		error = "ok";
	}
	std::pair < SDL_Texture*, std::string > runData;

	runData = std::make_pair(mytext,error);
	return runData;


}

std::string parser::runForAllThread(Render* myrenderer, std::binary_semaphore& sharedSema, Render* myThreadRenderer, std::binary_semaphore &mainToThread,ThreadManager* myThreadManager,int threadid)
{

	std::string error = "";
	int line = 0;
	commandFactory* myComFactory = commandFactory::getInstance();
	programmingConstructsFactory* constructFactory = programmingConstructsFactory::getInstance();
	bool execution = true;
	executorManager* myExecutor = nullptr;
	bodyEnd* myBodyEnd = nullptr;


	for (int pcr = 0; pcr < commands.size(); pcr++)
	{
		try
		{
			line = pcr + 1;
			std::vector<std::string> command = commands.at(pcr);

			commandCatFactory* myfact = new commandCatFactory();
			commandCat* abstractCommand = myfact->getCommand(command.at(0));

			std::vector<std::string> commandArgs;
			commandArgs.clear();
			if (abstractCommand != nullptr)
			{
				if (execution)
				{
					checkForAll(command, programMemory);

					if (!abstractCommand->correctParamsCount(0))
					{
						for (int i = 1; i < command.size(); i++)
						{
							commandArgs.push_back(command.at(i));

						}


						IArgManager* argChecker = dynamic_cast<IArgManager*>(abstractCommand);
						if (argChecker->syntaxcheck(commandArgs))
						{
							argChecker->setAttributes(commandArgs);
						}
					}


				}



				if (constructFactory->hasKey(command.front(), "body"))
				{
					programmingBodies* mybody = dynamic_cast<programmingBodies*>(abstractCommand);
					mybody->setProgramCounterPos(pcr);
					bodyPCRs.push_back(mybody);
				}
				if (constructFactory->hasKey(command.front(), "bodyend"))
				{
					myBodyEnd = dynamic_cast<bodyEnd*>(abstractCommand);
					myBodyEnd->checkCorrectEnd(bodyPCRs);
					myBodyEnd->setCurrentBodyPCR(bodyPCRs);
					bodyPCRs = myBodyEnd->popFromBodyList(bodyPCRs);//if any bodies left chuck error at end

				}
				if (constructFactory->hasKey(command.front(), "execute"))
				{
					myExecutor = dynamic_cast<executorManager*>(abstractCommand);
					myExecutor->setLocalExecution(execution);


				}
				if (execution || (bodyPCRs.size() == 0 && constructFactory->hasKey(command.front(), "bodyend")))
				{
					
					if (myComFactory->getCommand(command.at(0)) != nullptr)
					{
						sharedSema.acquire();
						std::cout << "thread" << threadid << "running in thread semaphore" << std::endl;
						myrenderer->setFill(myThreadRenderer->getFill());
						float x = myThreadRenderer->getPen().first;
						float y = myThreadRenderer->getPen().second;
						myrenderer->setPen(x,y);
						std::vector<Uint8> colour = myThreadRenderer->getPenColour();
						myrenderer->setPenColour(colour);
						
						
						Commands* current_Command = dynamic_cast<Commands*>(abstractCommand);
						myThreadManager->setToRun(current_Command);
						std::cout << command.front() << std::endl;
						std::cout << "thread wait aquire" << std::endl;
						mainToThread.acquire();
						std::cout << "thread grab aquire" << std::endl;

						myThreadRenderer->setFill(myrenderer->getFill());
					    x = myrenderer->getPen().first;
						y = myrenderer->getPen().second;
						myThreadRenderer->setPen(x,y);
						std::cout << "x" << myThreadRenderer->getPen().first << "y" << myThreadRenderer->getPen().second << std::endl;
						colour = myrenderer->getPenColour();
						myThreadRenderer->setPenColour(colour);
					
					
						std::cout << "thread copied context" << std::endl;
						sharedSema.release();
						std::cout << "thread" << threadid << "running out of thread semaphore" << std::endl;
						
					}

					else if (constructFactory->getCommand(command.at(0)) != nullptr)
					{
						programmingConstructs* currentConstruct = dynamic_cast<programmingConstructs*>(abstractCommand);
						currentConstruct->runCommand();
					}
				}

				if (constructFactory->hasKey(command.front(), "execute"))
				{
					execution = myExecutor->getLocalExecution();
				}
				if (constructFactory->hasKey(command.front(), "bodyend"))
				{
					pcr = myBodyEnd->getNewPCr(pcr);

				}
				if (command.front() == "method")
				{
					Function* newFunc = new Function(command.at(1));
					oldMemory = programMemory;
					programMemory = newFunc->updateMemory();
					newFunc->setMethodDefPcr(pcr);
					callTable.push_back(newFunc);


				}
				if (constructFactory->hasKey(command.front(), "memory"))
				{
					MemoryRestorer* myMemory = dynamic_cast<MemoryRestorer*>(abstractCommand);
					if (myMemory->getClearFlag())
					{
						myMemory->clearNew(programMemory);
					}
					if (myMemory->getRestoreFlag())
					{
						programMemory = myMemory->oldToNew(oldMemory);
					}

				}
			}
			else
			{
				if (execution)
				{
					Function* newFunc = isFunc(callTable, command.at(0));
					Expression* myExpression = new Expression();
					std::string statement = command.front();
					if (myExpression->isAssignment(statement))
					{
						std::string value = myExpression->getAssignmentValue(statement);

						if (myExpression->checkAssignmentValue(value, programMemory))
						{
							if (programMemory->isGoodVarName(myExpression->getVarName(statement)))
							{
								myExpression->performAssignment(statement, programMemory);
							}
						}
					}
					else if (newFunc != nullptr)
					{

						newFunc->setArgs(command.at(0));
						newFunc->addArgsToMemory();
						methodCommand* methoCom = new methodCommand();
						methoCom->setProgramCounterPos(pcr + 1);
						bodyPCRs.push_back(methoCom);
						pcr = newFunc->getMethodDefPcr();
						oldMemory = programMemory;
						programMemory = newFunc->updateMemory();


					}

				}


			}
		}

		catch (nonStringException& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";

		}
		catch (nonnumberexception& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (InvalidParameters& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (nonfillvalue& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (operationNotSupportDataType& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (memoryUnsupportedType& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (erreneousVarName& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (variableIsUndefined& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (notcommandexception& e)
		{

			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
		catch (cannotEndBody& e)
		{
			error = error + "run time error " + e.returnError() + " on line " + std::to_string(line) + "\n";
		}
	}
	for (programmingBodies* body : bodyPCRs)
	{
		try
		{
			bool a = 1;
			throw unEndedBody("run time error unEndedbody on line " + std::to_string(body->getProgramCounterPos() + 1));
		}
		catch (unEndedBody& e)
		{
			error = error + e.returnError();
		}
	}



	callTable.clear();
	bodyPCRs.clear();
	execution = true;
	programMemory->deletePagetable();
	if (error == "")
	{
		error = "ok";
	}
	return error;


}

void parser::splitToArguments(std::string line)
{
	int pos2 = 1;
	std::string arg;
	std::string saveline;
	while (pos2 > -1)
	{
		pos2 = line.find(" ");
		arg = line.substr(0, pos2);
		std::cout << arg << std::endl;
		arguments.push_back(arg);
		saveline = line;
		if (line == saveline.erase(0, pos2)) {

			break;
		}
		else
		{
			line = line.erase(0, pos2+1);
		}

	}
}

void parser::saveToTxt(std::string program)
{
	int numOfFiles = 0;
	std::string newFileName;
	std::string numOfFilesstr;
	std::ifstream MyReadFile("NumOfTxt.txt");

	 getline(MyReadFile, numOfFilesstr);

	 numOfFiles = std::stoi(numOfFilesstr);

	 numOfFiles++;

	 std::ofstream MyWriteFile("NumOfTxt.txt");

	 MyWriteFile << std::to_string(numOfFiles);


	 newFileName="program"+ std::to_string(numOfFiles)+".txt";
	 std::ofstream MyMainWriteFile(newFileName);
	 MyMainWriteFile << program;
	 MyWriteFile.close();


	
}

std::string parser::loadFromTxt(std::string programName)
{
	std::string storeProgram;

	std::ifstream MyReadFile(programName.c_str());
	
	std::string line;

	while (getline(MyReadFile, line)) 
	{
		storeProgram = storeProgram + line + "\n";
	}
	MyReadFile.close();
	return storeProgram;


}

void parser::checkForVars(std::vector<std::string> &command, MemoryManager* myManager,int inputIndex)
{
	
	if (myManager->pageExist(command.at(inputIndex))) 
	{
		command.at(inputIndex) = myManager->returnValue(command.at(inputIndex));
	}
	else
	{
		throw variableIsUndefined("you have tried to use a variable that has not been defined");
	}
	
}

bool parser::checkForValue(std::vector<std::string> &command,int inputIndex)
{
	dataChecker* myChecker = dataChecker::getInstance();
	if (myChecker->isValue(command.at(inputIndex)))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void parser::checkForAll(std::vector<std::string>& command, MemoryManager* myManager)
{
	for (int i = 1; i < command.size(); i++)
	{
			if (!checkForValue(command, i) && myManager->BannedChars(command.at(i)))
			{
				checkForVars(command, myManager, i);
			}

	}
}

Function* parser::isFunc(std::vector<Function*> callTable, std::string funcStatement)
{
	for (Function* func : callTable)
	{

		if (myChecker->readFuncName(funcStatement) == func->getName())
		{
			return func;
		}

	}
	return nullptr;
}









