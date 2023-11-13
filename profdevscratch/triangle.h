#pragma once
#include <utility>      
#include <string>       
#include <iostream>
#include "SDL.h"
#include <vector>
#include "shape.h" 
/**
 * the class for setting up properties and methods for drawing triangles
 */
class triangle:public shape
{

public:
	/**
	 * .the triangle default constructor
	 * 
	 */
	triangle();
	/**
	 * .the vertices of the triangle
	 */
    SDL_Vertex verts[3];
	/**
	 * .the pen pos for the triangle
	 */
	std::pair<float, float> pen;
	/**
	 * .constructor taking in arugments for vertices
	 * 
	 * \param x verticy 1 x cord
	 * \param y verticy 1 y cord
	 * \param x2 verticy 2 x cord
	 * \param y2 verticy 2 y cord
	 * \param x3 verticy 3 x cord
	 * \param y3 verticy 3 y cord
	 */
	triangle(float x, float y, float x2, float y2, float x3, float y3);
	/**
	 * .the method for setting up drawing code to pass to renderer
	 * 
	 * \param myrenderer render to draw with
	 * \param RGBA the colour to make triangle
	 * \param fill the fill for whether to fill triangle 
	 * \return the pen 
	 */
	std::pair<float,float> renderself(SDL_Renderer* myrenderer, std::vector<Uint8> RGBA , bool fill) override;
	/**
	 * .sets points on triangle
	 * 
	 * \param x the x cord of 1st verticy
	 * \param y the y cord of 1st verticy
	 * \param x2 the x cord of second verticy
	 * \param y2 the y cord of second verticy 
	 * \param x3 the x cord of third verticy
	 * \param y3 the y cord of third verticy
	 */
	void setPoints(float x, float y, float x2, float y2, float x3, float y3);
	/**
	 * .sets the colour to set triangle too 
	 * 
	 * \param RGBA colour to set to
	 */
	void setColour(std::vector<Uint8> &RGBA);
	/**
	 * .sets new pen pos 
	 * 
	 * \param newPen pen pos 
	 */
	void setPen(std::pair<float, float> newPen);
	
	
	
};

