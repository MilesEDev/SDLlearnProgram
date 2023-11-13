#include "eventfactory.h"

eventfactory::eventfactory() {}

shape* eventfactory::addShape(std::string shapeProduct)
{
	if (shapeProduct == "rectangle")
	{
		rectangle* rect = new rectangle();
		return rect;

	}
	else if(shapeProduct == "triangle")
	{
		triangle* tri = new triangle(100,100,100,200,300,300);
		return tri;
	}
	else 
	{
		circle* circ = new circle();
		return circ;
	}
	
}


