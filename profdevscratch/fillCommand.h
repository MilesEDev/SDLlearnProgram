#pragma once
#include <string>
#include "SDL.h"
#include "Commands.h"
#include "Render.h"
#include "IArgManager.h"
/**
 * .a bridge between user input and filling object 
 */
class fillCommand : public Commands,public IArgManager

{
	
private:
	/**
	 * .bool fill to set
	 */
	bool fill = false;
public: 

	bool syntaxcheck(std::vector<std::string> commandArgs) override;


	void setAttributes(std::vector<std::string> commandArgs) override;
	/**
	 * .sets noparametrs
	 * 
	 */
	fillCommand();
	
	/**
	 * .runs the fill command
	 * 
	 * \param myrenderer renderer used to run fill command
	 * \return any sdl error
	 */
	std::string runCommand(Render* myrenderer, std::pair<float, float> Pen) override;


	
};

