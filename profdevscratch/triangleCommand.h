#pragma once
#include <string>       
#include <iostream>   
#include "commands.h"
#include "Render.h"
#include "IArgManager.h"
/**
 * .a bridge between user input and rendering triangle
 */
class triangleCommand:public Commands,public IArgManager
{

	/**
	 * .x cordinate of second verices
	 */
	float x1 = 0;
	/**
	 * .x cordinate of third vertices
	 */
	float x2 = 0;
	/**
	 * .y cordinate of second vertices
	 */
	float y1 = 0;
	/**
	 * .y cordinate of therd vertices
	 */
	float y2 = 0;
public:
	/**
	 * .sets parameterno
	 * 
	 */
	triangleCommand();
	/**
	 * .
	 *
	 * \param commandArgs takes in commandArgs and checks syntax on it for circle
	 * \return is good syntax or not
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs) override;

	void setAttributes(std::vector<std::string> commandArgs) override;
	/**
	 * .
	 * 
	 * \param renderer rendered to draw triangle with
	 * \param Pen kept for possible inheritance from commands
	 * \return sdl error 
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);


};

