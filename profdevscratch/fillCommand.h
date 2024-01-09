#pragma once
#include <string>
#include "SDL.h"
#include "Commands.h"
#include "Render.h"
#include "IArgManager.h"
#include "nonfillvalue.h"
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

	/**
	 * .this performs a syntax check on the arguments added so it can check to see if the command can run with
	 * the entered arguments
	 * 
	 * \param commandArgs this stores the arguments to be syntax checked
	 * \return this returns the succsess of the syntax check if true it means command can run if false it means 
	 * it can not
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs) override;

	/**
	 * .sets arguments up so that it can  be used in the run commands with assurance that the arguments
	 * have all been correctly parsed
	 *
	 */
	void setAttributes(std::vector<std::string> commandArgs) override;
	
	/**
	 * .this is the fill constructor to set up the parameter count 
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

