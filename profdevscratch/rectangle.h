#pragma once
#include <utility>      
#include <string>       
#include <iostream>   
#include "shape.h"
#include <array>
#include <vector>

/**
 * .rectangle for setting rectangle properties and using rectangle drawing methods
 */
class rectangle:public shape
{
private:
	/**
	 * .THE rectangle dimensions
	 */
	std::pair<int,int> rectangleDimensions;
	/**
	 * .the pen pos for rectangle
	 */
	std::pair<float, float> pen;
public:
	/**
	 * .sets up default rectangle with constructor
	 * 
	 */
	rectangle();
	/**
	 * .sets rectangle height width and pos with constructor 
	 * 
	 * \param width  width of rectangle
	 * \param height  height of rectangle
	 * \param pen pos of rectangle
	 */
	rectangle(int width, int height,std::pair<float,float> pen);
	/**
	 * .sets the dimensions of the rectangle
	 * 
	 * \param width width of the retangle
	 * \param height the height of the rectangle
	 */
	void setDimensions(int width, int height);
	/**
	 * .inherited method to render self uses code from render self to pass to renderer to draw rectangle
	 */

	std::pair<float,float> renderself(SDL_Renderer* myrenderer, std::vector<Uint8>  RGBA, bool fill) override;
	/**
	 * .sets pen position 
	 * 
	 * \param newPen new pen pos 
	 */
	void setPen(std::pair<float, float> newPen);
	

	
	
	


};

