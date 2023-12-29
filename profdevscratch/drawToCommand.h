#pragma once
#include <string>
#include "rectangle.h"
#include "Render.h"
#include "Commands.h"
#include "IArgManager.h"
/**
 * .draw to command to act as a bridge between user and renderer
 */
class drawToCommand : public Commands, public IArgManager
{
private:

public:
	/**
	 * .draw to constructor for setting up param no
	 * 
	 */
	drawToCommand();
	
	/**
	 * .
	 *
	 * \param commandArgs takes in commandArgs and checks syntax on it for circle
	 * \return is good syntax or not
	 */
	bool syntaxcheck(std::vector<std::string> commandArgs) override;


	void setAttributes(std::vector<std::string> commandArgs) override;
	/**
	 * .runs command to draw to 
	 * 
	 * \param renderer to use to draw
	 * \param Pen to possibly link to commands 
	 * \return sdl error
	 */
	std::string runCommand(Render* renderer, std::pair<float, float> Pen);

};

