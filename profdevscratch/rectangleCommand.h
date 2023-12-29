#pragma once
#include "Commands.h"
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "IArgManager.h"
/**
 * .a bridge between taking user input and rendering rectangle
 */
class rectangleCommand:public Commands,public IArgManager
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
	 * .
	 *
	 * \param commandArgs takes in commandArgs and checks syntax on it for rectangle
	 * \return is good syntax or not
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs) override;
	

	void setAttributes(std::vector<std::string> commandArgs);
	/**
	 * .runs rectangle command
	 * 
	 * \param renderer the renderer to use to draw rectangle
	 * \param Pen pen kept for possible integration with command 
	 * \return possible SDL error 
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);
	


};

