#pragma once
#include <utility>      
#include <string>       
#include <iostream>   
#include "shape.h"
#include "math.h"
#include "triangle.h"
#include <array>
#include <vector>
/**
 * .circle to contain circle draw methods and property setters
 */
class circle:public shape
{
private:
	/**
	 * .vertexes for triangles to form filled circle
	 */
	SDL_Vertex verts[3];
	/**
	 * .radius for circumference of circle
	 */
	float radius = 0;
	/**
	 * .pen for circle centre point
	 */
	std::pair<float, float> pen;
public:
	/**
	 * .default circle constructor
	 * 
	 */
	circle();
	/**
	 * .circle constructor taking pen pos and radius
	 * 
	 * \param pen pos 
	 * \param radius radius of circle
	 */
	circle(std::pair<float,float>, float radius);
	/**
	 * .sets radius of circle 
	 * 
	 * \param new_radius
	 */
	void setRadius(float new_radius);
	/**
	 * .render self method inherited to set up rendering code to pass to renderer
	 */

	std::pair<float,float> renderself(SDL_Renderer* myrenderer, std::vector<Uint8> RGBA, bool fill) override;
	/**
	 * .sets pen pos 
	 * 
	 * \param newPen pen pos 
	 */
	void setPen(std::pair<float, float> newPen);





	


};

