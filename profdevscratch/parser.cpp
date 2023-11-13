#include "parser.h"
#include <boost/algorithm/string.hpp>
#include "circleCommand.h"
#include "rectangleCommand.h"
#include "triangle.h"

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

bool parser::syntaxCheckAll()
{
	
	for (std::vector<std::string> command : commands)
	{
		if (SDL_strcasecmp(command.front().c_str(),"circle")==0)
		{
			circleCommand* circCom = new circleCommand();
			int size = command.size() - 1;
			if (!circCom->correctParamsCount(size)) 
			{
				throw InvalidParameters("you have entered the incorrect number of parameters on line" + std::to_string(line));
			}
			std::string store = command.at(1);
			if (!circCom->syntaxcheck(store)) 
			{
				throw nonnumberexception("you have tried to use a non number in a number field for circle at line" + std::to_string(line));
			}
			
		}
		if (SDL_strcasecmp(command.front().c_str(), "rectangle") == 0)
		{
			rectangleCommand* rectCom = new rectangleCommand();
			int size = command.size() -1;
			if (!rectCom->correctParamsCount(size))
			{
				throw InvalidParameters("you have entered the incorrect number of parameters on line" + std::to_string(line));
			}
			
			if (!rectCom->syntaxcheck(command.at(1),command.at(2)))
			{
				throw nonnumberexception("you have tried to use a non number in a number field for circle at line" + std::to_string(line));
			}
			
		}
		if (SDL_strcasecmp(command.front().c_str(), "triangle") == 0)
		{
			triangleCommand* triCom = new triangleCommand();
			int size = command.size() - 1;
			if (!triCom->correctParamsCount(size))
			{
				throw InvalidParameters("you have entered the incorrect number of parameters on line" + std::to_string(line));
			}

			if (!triCom->syntaxcheck(command.at(1), command.at(2),command.at(3),command.at(4)))
			{
				throw nonnumberexception("you have tried to use a non number in a number field for circle at line" + std::to_string(line));
			}
			
		}
		if (SDL_strcasecmp(command.front().c_str(), "fill") == 0)
		{
			fillCommand* fillCom = new fillCommand();
			int size = command.size() - 1;
			if (!fillCom->correctParamsCount(size))
			{
				throw InvalidParameters("you have entered the incorrect number of parameters on line" + std::to_string(line));
			}

			if (!fillCom->syntaxcheck(command.at(1)))
			{
				throw nonfillvalue("you have tried to use a value for fill which is not on or off" + std::to_string(line));
			}
		}
		if (SDL_strcasecmp(command.front().c_str(),"moveTo") == 0)
		{
			PosPencommand* penCom = new PosPencommand();
			int size = command.size() - 1;
			if (!penCom->correctParamsCount(size))
			{
				throw InvalidParameters("you have entered the incorrect number of parameters on line" + std::to_string(line));
			}
			std::string store = command.at(1);
			if (!penCom->syntaxcheck(command.at(1),command.at(2)))
			{
				throw nonnumberexception("you have tried to use a non number in a number field for circle at line" + std::to_string(line));
			}

		}


		
	}
	return true;

}

SDL_Texture* parser::runForAll(Render* myrenderer,SDL_Texture* mytext)
{
	
	if (syntaxCheckAll()) 
	{
		SDL_SetRenderTarget(myrenderer->getSDLRenderer(), mytext);
		myrenderer->setPenColourRGBA(255, 0, 0, 255);
		myrenderer->renderClear();
		
		

		


		for (std::vector<std::string> command : commands)
		{

			std::cout << command.front() << std::endl;
			if (SDL_strcasecmp(command.front().c_str(), "circle") ==0)
			{
				std::cout << "running" << std::endl;
				circleCommand* circCom = new circleCommand();
				myrenderer->setPenColourRGBA(0, 255, 0, 255);
				circCom->setRadius(std::stof(command.at(1)));
				circCom->runCommand(myrenderer,myrenderer->getPen());
				
			}
			if (SDL_strcasecmp(command.front().c_str(), "rectangle") == 0)
			{
				std::cout << "running" << std::endl;
				rectangleCommand* rectCom = new rectangleCommand();
				myrenderer->setPenColourRGBA(0, 255, 0, 255);
				rectCom->setRectDimensions(std::stof(command.at(1)),std::stof(command.at(2)));
				rectCom->runCommand(myrenderer, myrenderer->getPen());

			}
			if (SDL_strcasecmp(command.front().c_str(), "triangle") == 0)
			{
				std::cout << "running" << std::endl;
				triangleCommand* triCom = new triangleCommand();
				myrenderer->setPenColourRGBA(0, 255, 0, 255);
				triCom->setPoints(std::stof(command.at(1)), std::stof(command.at(2)),
					std::stof(command.at(3)), std::stof(command.at(4)));
				triCom->runCommand(myrenderer, myrenderer->getPen());
			}
			if (SDL_strcasecmp(command.front().c_str(), "fill") == 0)
			{
				std::cout << "running" << std::endl;
				fillCommand* fillCom = new fillCommand();
				fillCom->setFill(command.at(1));
				fillCom->runCommand(myrenderer);
			}
			if (SDL_strcasecmp(command.front().c_str(), "moveTo") == 0)
			{
				std::cout << "running" << std::endl;
				PosPencommand* penCom = new PosPencommand();
				penCom->setPoints(std::stof(command.at(1)), std::stof(command.at(2)));
				penCom->runCommand(myrenderer,myrenderer->getPen());
			}


		}

	}
	myrenderer->removeAnyTargets();
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



	
}

std::string parser::loadFromTxt(std::string programName)
{
	std::string storeProgram;
	std::ifstream MyReadFile(programName);
	std::string line;

	while (getline(MyReadFile, line)) 
	{
		storeProgram = storeProgram + line + "\n";
	}
	return storeProgram;

}







