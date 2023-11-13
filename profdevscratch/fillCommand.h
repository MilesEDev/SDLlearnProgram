#pragma once
#include <string>
#include "SDL.h"
#include "Commands.h"
#include "Render.h"
/**
 * .a bridge between user input and filling object 
 */
class fillCommand : public Commands

{
	
private:
	/**
	 * .bool fill to set
	 */
	bool fill = false;
public: 


	/**
	 * .sets noparametrs
	 * 
	 */
	fillCommand();
	/**
	 * .sets fill
	 * 
	 * \param onOrOff fill on or fill off
	 */
	void setFill(std::string onOrOff);
	/**
	 * .checks parameter is true or false 
	 * 
	 * \param onOrOff
	 * \return 
	 */
	bool syntaxcheck(std::string onOrOff);
	/**
	 * .runs the fill command
	 * 
	 * \param myrenderer renderer used to run fill command
	 * \return any sdl error
	 */
	std::string runCommand(Render* myrenderer);


	
};

