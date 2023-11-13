#pragma once
#include "SDL.h"
#include <array>
#include <vector>
/**
 * .the base class for all shapes ("The source of life!")
 */
class shape
{
public:
	/**
	 * .virtual function to have shapes pass render information to renderer
	 * 
	 * \param myrenderer the renderer to pass information too
	 * \param RGBA the colour to use for drawing
	 * \param fill the fill value for whether to fill or not
	 * \return the pen pos for any changes in position 
	 */
	virtual std::pair<float,float> renderself(SDL_Renderer* myrenderer, std::vector<Uint8> RGBA,bool fill) = 0;
	

};

