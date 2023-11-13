#pragma once
#include <string>       
#include <iostream>   
#include "commands.h"
#include "Render.h"
/**
 * .a bridge between user input and rendering triangle
 */
class triangleCommand:public Commands
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
	 * \param x1 the user input for vertex 2 x value
	 * \param y1 the user input for vertex 2 y value
	 * \param x2 the user input for vertex 3 x value
	 * \param y2 the user input for vertex 3 y value 
	 * \return success or not for is int
	 */
	bool syntaxcheck(std::string x1, std::string y1, std::string x2, std::string y2);
	/**
	 * .sets up points for triangle to be rendered from 
	 * 
	 * \param newx1 new vertex 2 x
	 * \param newx2 new vertex 3 x
	 * \param newy1 new vertex 2 y
	 * \param newy2 new vertex 3 y
	 */
	void setPoints(float newx1, float newx2, float newy1, float newy2);
	/**
	 * .
	 * 
	 * \param renderer rendered to draw triangle with
	 * \param Pen kept for possible inheritance from commands
	 * \return sdl error 
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);


};

