#pragma once
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
#include "IArgManager.h"
#include "notcolourexception.h"
#include "dataConverter.h"
#include "nonStringException.h"
/**
 * .the bridge between user and renderer for setting colour 
 */
class colourCommand : public Commands,public IArgManager

{
private:
	/**
	 * .the colours to set too
	 */
	std::vector<Uint8> colours;


public:
	/**
	 * .the constructor to set parameter no 
	 * 
	 */
	colourCommand();

	/**
	 * .checks syntax for colour command 
	 * 
	 * \param commandArgs the arguments to be checked 
	 * \return 
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs) override;


	void setAttributes(std::vector<std::string> commandArgs) override;
	/**
	 * .runs  colour command
	 *
	 * \param renderer to be used set colour
	 * \param Pen kept as may update to inherit from commands
	 * \return sdl error if there is one
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen) override;


};

