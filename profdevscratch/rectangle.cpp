#include "rectangle.h"
#include <vector>

rectangle::rectangle()
{
	rectangleDimensions = std::make_pair(50,50);
	pen = std::make_pair(0.0f, 0.0f);
}
rectangle::rectangle(int width,int height,std::pair<float,float> pen)
{
	rectangleDimensions = std::make_pair(width, height);
	this->pen = pen;
}

void rectangle::setDimensions(int width, int height)
{
	rectangleDimensions.first = width;
	rectangleDimensions.second = height;
}


std::pair<float,float> rectangle::renderself(SDL_Renderer* myrenderer, std::vector<Uint8>  RGBA , bool fill)
{

	
	//std::pair<float, float> pen = myrenderer->getPen();
	
	SDL_Rect* srcRect = new SDL_Rect();
	srcRect->x = pen.first;
	srcRect->y = pen.second;
	srcRect->w = rectangleDimensions.first;
	srcRect->h = rectangleDimensions.second;
	
	SDL_RenderDrawRect(myrenderer, srcRect);

	if (fill) 
	{
		SDL_RenderFillRect(myrenderer, srcRect);

	}
	return pen;

}

void rectangle::setPen(std::pair<float, float> newPen)
{
	this->pen = newPen;
}

