#pragma once
#include <utility>      
#include <string>       
#include <iostream>
#include "SDL.h"
#include <vector>
#include "shape.h" 

class triangle:public shape
{

public:
	
	triangle();
    SDL_Vertex verts[3];
	std::pair<float, float> pen;
	
	triangle(float x, float y, float x2, float y2, float x3, float y3);
	std::pair<float,float> renderself(SDL_Renderer* myrenderer, std::vector<Uint8> RGBA , bool fill) override;
	void setPoints(float x, float y, float x2, float y2, float x3, float y3);
	void setColour(std::vector<Uint8> &RGBA);
	void setPen(std::pair<float, float> newPen);
	
	
	
};

