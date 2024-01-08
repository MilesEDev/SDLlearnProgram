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
	
	commandFactory* myFactory = commandFactory::getInstance();
	programmingConstructsFactory* constructFactory = programmingConstructsFactory::getInstance();
	line = 0;
	try
	{
		for (int pcr = 0; pcr < commands.size(); pcr++)
		{
			std::vector<std::string> command = commands.at(pcr);
			line++;
		
			commandCatFactory* myfact = new commandCatFactory();

			commandCat* abstractCommand = myfact->getCommand(command.at(0));
		

			if(abstractCommand != nullptr)
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
				}
			
			}
			else
			{
				bool key = false;
				Expression* myExpression = new Expression();
				std::string statement = command.front();
				if (myExpression->isAssignment(statement))
				{
					if (myExpression->checkAssignment(statement,programMemory))
					{
						if (programMemory->isGoodVarName(myExpression->getVarName(statement)))
						{
							myExpression->performAssignment(statement,programMemory);
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
	}

	catch (nonStringException& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line " + std::to_string(line);
		
	}
	catch (nonnumberexception& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line "+std::to_string(line);
	}
	catch (InvalidParameters& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line " + std::to_string(line);
	}
	catch(nonfillvalue& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line " + std::to_string(line);
	}
	catch (operationNotSupportDataType& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line " + std::to_string(line);
	}
	catch (memoryUnsupportedType& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line " + std::to_string(line);
	}
	catch (erreneousVarName& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line " + std::to_string(line);
	}
	catch (variableIsUndefined& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line " + std::to_string(line);
	}
	catch (notcommandexception& e)
	{
		programMemory->deletePagetable();
		return e.returnError() + " on line " + std::to_string(line);
	}
	programMemory->deletePagetable();
	return "ok";
}
				
				
			
		
		
	





SDL_Texture* parser::runForAll(Render* myrenderer,SDL_Texture* mytext)
{
	

	
	SDL_SetRenderTarget(myrenderer->getSDLRenderer(), mytext);
	SDL_SetRenderDrawColor(myrenderer->getSDLRenderer(), 255, 255, 255, 255);
	SDL_RenderClear(myrenderer->getSDLRenderer());
	SDL_SetRenderDrawColor(myrenderer->getSDLRenderer(), 0, 0,0, 0);
	commandFactory* myComFactory = commandFactory::getInstance(); 
	programmingConstructsFactory* constructFactory = programmingConstructsFactory::getInstance();
	bool execution = true;
	executorManager* myExecutor = nullptr;
	bodyEnd* myBodyEnd = nullptr;
	
	

	for (int pcr = 0; pcr < commands.size(); pcr++)
	{
		std::vector<std::string> command = commands.at(pcr);

		commandCatFactory* myfact = new commandCatFactory();
		commandCat* abstractCommand = myfact->getCommand(command.at(0));

		std::vector<std::string> commandArgs;
		commandArgs.clear();
		if (abstractCommand != nullptr)
		{
			checkForAll(command, programMemory);
			if (!abstractCommand->correctParamsCount(0))
			{
				for (int i = 1; i < command.size(); i++)
				{
					commandArgs.push_back(command.at(i));

				}
				IArgManager* argChecker = dynamic_cast<IArgManager*>(abstractCommand);
				argChecker->setAttributes(commandArgs);
			}


			if (constructFactory->hasKey(command.front(), "body"))
			{
				programmingBodies* mybody = dynamic_cast<programmingBodies*>(abstractCommand);
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
			if (execution || (bodyPCRs.size() == 1 && constructFactory->hasKey(command.front(), "bodyend")))
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
		}
		else
		{
			Expression* myExpression = new Expression();
			std::string statement = command.front();
			if (myExpression->isAssignment(statement))
			{
				if (myExpression->checkAssignment(statement,programMemory))
				{
					if (programMemory->isGoodVarName(myExpression->getVarName(statement)))
					{
						myExpression->performAssignment(statement, programMemory);
					}
				}
			}
		}
	}
	myrenderer->removeAnyTargets();
	bodyPCRs.clear();
	execution = true;
	programMemory->deletePagetable();
	return mytext;


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







