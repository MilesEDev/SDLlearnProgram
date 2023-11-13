#pragma once
#include <utility>      
#include <string>       
#include <iostream>   
#include "shape.h"
#include "math.h"
#include "triangle.h"
#include <array>
#include <vector>
class circle:public shape
{
private:
	SDL_Vertex verts[3];
	float radius = 0;
	std::pair<float, float> pen;
public:

	circle();
	circle(std::pair<float,float>, float radius);

	void setRadius(float new_radius);

	std::pair<float,float> renderself(SDL_Renderer* myrenderer, std::vector<Uint8> RGBA, bool fill) override;

	void setPen(std::pair<float, float> newPen);





	


};

