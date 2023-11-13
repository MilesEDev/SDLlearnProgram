#pragma once
#include "Commands.h"
#include <string>
#include "rectangle.h"
#include "Render.h"
/**
 * .a bridge between taking user input and rendering rectangle
 */
class rectangleCommand:public Commands
{

private:
	/**
	 * .width of rectangle to pass
	 */
	float width = 0;
	/**
	 * .width of height to pass
	 */
	float height = 0;
public:
	/**
	 * .set parameter no 
	 * 
	 */
	rectangleCommand();
	/**
	 * .check user inputs are both floats or ints to set height and width
	 * 
	 * \param height height of rectangle
	 * \param width width of rectangle
	 * \return success or not
	 */
	bool syntaxcheck(std::string height,std::string width);
	/**
	 * .sets up height and width
	 * 
	 * \param width width of rectangle
	 * \param height height of rectangle
	 */
	
	void setRectDimensions(float width,float height);
	/**
	 * .runs rectangle command
	 * 
	 * \param renderer the renderer to use to draw rectangle
	 * \param Pen pen kept for possible integration with command 
	 * \return possible SDL error 
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);
	


};

