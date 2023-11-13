#pragma once
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
/**
 * .the bridge between user and renderer for setting colour 
 */
class colourCommand : public Commands

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
	 * .checks colour strings are valid 
	 * 
	 * \param colour user input 
	 * \return success 
	 */
	bool syntaxcheck(std::string colour);
	/**
	 * .sets the colour 
	 * 
	 * \param colour the string of colour to set too 
	 */
	void setCol(std::string colour);
	/**
	 * .runs the colour change 
	 * 
	 * \param myrenderer the renderer to use to change colour 
	 * \return sdl error 
	 */
	std::string runCommand(Render* myrenderer);


};

