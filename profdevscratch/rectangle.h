#pragma once
#include <utility>      
#include <string>       
#include <iostream>   
#include "shape.h"
#include <array>
#include <vector>

class rectangle:public shape
{
private:
	std::pair<int,int> rectangleDimensions;
	std::pair<float, float> pen;
public:
	rectangle();
	rectangle(int width, int height,std::pair<float,float> pen);
	
	void setDimensions(int width, int height);

	std::pair<float,float> renderself(SDL_Renderer* myrenderer, std::vector<Uint8>  RGBA, bool fill) override;

	void setPen(std::pair<float, float> newPen);
	

	
	
	


};

