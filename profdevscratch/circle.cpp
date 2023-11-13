#include "circle.h"

circle::circle()
{
	radius = 100;
	pen = std::make_pair(100.0f, 100.0f);

}

circle::circle(std::pair<float, float>, float radius)
{
	this->radius = radius;
	this->pen = pen;
}

void circle::setRadius(float new_radius)
{
	radius = new_radius;
}

std::pair<float,float> circle::renderself(SDL_Renderer* myrenderer, std::vector<Uint8>  RGBA, bool fill)
{
	float x = 0;
	float y = 0;
	verts[0].position = { pen.first,pen.second };
	for (int angle = 0; angle <= 360; angle += 5) 
	{
		
		x = (float)(radius * cos((angle-5) * M_PI / 180.0f)) + verts[0].position.x;
		y = (float)(radius * sin((angle -5) * M_PI / 180.0f)) + verts[0].position.y;
		verts[1].position = { x,y };
		x = (float)(radius * cos((angle) * M_PI / 180.0f)) + verts[0].position.x;
		y = (float)(radius * sin((angle) * M_PI / 180.0f)) + verts[0].position.y;
		verts[2].position = { x,y };

		
		if (fill)
		{
			
			triangle* mytri = new triangle(verts[0].position.x, verts[0].position.y,
				verts[1].position.x, verts[1].position.y, verts[2].position.x, verts[2].position.y);
			mytri->setColour(RGBA);
			mytri->renderself(myrenderer, RGBA, fill);

		}
		else
		{
			SDL_RenderDrawLine(myrenderer, verts[1].position.x, verts[1].position.y, verts[2].position.x, verts[2].position.y);


		}
	}
	return pen;

}

void circle::setPen(std::pair<float, float> newPen)
{
	this->pen = newPen;

}
