#include "triangle.h"
#include "SDL.h"

triangle::triangle() {
	
}
triangle::triangle(float x,float y,float x2,float y2,float x3,float y3)
{
	verts[0].position = { x,y };
	verts[1].position = { x2,y2 };
	verts[2].position = { x3,y3 };
}
std::pair<float,float> triangle::renderself(SDL_Renderer* myrenderer, std::vector<Uint8> RGBA, bool fill)
{
	
	if (fill) 
	{
		
		setColour(RGBA);
		SDL_RenderGeometry(myrenderer, nullptr, verts, 3, NULL, 0);
		
	}
	else
	{
		SDL_RenderDrawLine(myrenderer, verts[0].position.x, verts[0].position.y, verts[1].position.x, verts[1].position.y);
		SDL_RenderDrawLine(myrenderer, verts[0].position.x, verts[0].position.y, verts[2].position.x, verts[2].position.y);
		SDL_RenderDrawLine(myrenderer, verts[1].position.x, verts[1].position.y, verts[2].position.x, verts[2].position.y);

	}
	return this->pen;
}

void triangle::setPoints(float x, float y, float x2, float y2, float x3, float y3)
{
	verts[0].position = { x,y };
	verts[1].position = { x2,y2 };
	verts[2].position = { x3,y3 };
}

void triangle::setColour(std::vector<Uint8> RGBA)
{
	
	for (int i = 0; i < 3; i++)
	{
		verts[i].color = { RGBA[0],RGBA[1],RGBA[2],RGBA[3] };
		
	}
}

void triangle::setPen(std::pair<float, float> newPen)
{
	this->pen = newPen;
}





