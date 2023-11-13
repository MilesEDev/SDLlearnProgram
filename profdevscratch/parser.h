#pragma once
#include <utility>      
#include <string>       
#include <iostream>     
#include <list>
#include "Commands.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include "renderTexture.h"
#include "Render.h"
#include "nonnumberexception.h"
#include "invalidParameters.h"
#include <iostream>
#include <fstream>
#include "triangleCommand.h"
#include "fillCommand.h"
#include "nonfillvalue.h"

class parser
{
private:
	
	std::vector<std::string> arguments;
	std::vector<std::vector<std::string>> commands;
	int line = 0;
public:
	parser();
	void splitToCommands(std::string program);
	
	void clearAllLists();

	bool syntaxCheckAll();

	SDL_Texture* runForAll(Render* myrenderer,SDL_Texture* mytext);

	void splitToArguments(std::string line);

	void saveToTxt(std::string program);

	std::string loadFromTxt(std::string programName);
	
	
	
	


	



};

