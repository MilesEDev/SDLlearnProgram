#pragma once
#include "SDL.h"
#include <array>
#include <vector>

class shape
{
public:

	virtual std::pair<float,float> renderself(SDL_Renderer* myrenderer, std::vector<Uint8> RGBA,bool fill) = 0;
	

};

