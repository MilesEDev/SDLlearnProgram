#pragma once
#include <string>
#include <iostream>   
#include "commands.h"
#include "Render.h"
#include "IArgManager.h"
/**
 * .a bridge between user input and setting pen position
 */
class PosPencommand :public Commands,public IArgManager
{
	/**
	 * .pos of pen x
	 */
	float x = 0;
	/**
	 *.pos of pen y
	 */
	float y = 0;
public:
	/**
	 * .sets num parameters taken
	 * 
	 */
	PosPencommand();
	
	/**
	 * .performs syntax check for the pos pen command 
	 * 
	 * \param commandArgs these are the arguments to be syntax checked 
	 * \return whether the syntax check was correct or  not 
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs) override;

	/**
	 * .this is used to make sure that all arguments are parsed before they are used in run command 
	 * 
	 * \param commandArgs these are the arguments that the user enters to be parsed and ran in the function 
	 */
	void setAttributes(std::vector<std::string> commandArgs) override;
	/**
	 * .runs set pen command
	 * 
	 * \param renderer uses renderer to do this
	 * \param Pen kept for possible inheritance on commands 
	 * \return sdl error
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);

};

