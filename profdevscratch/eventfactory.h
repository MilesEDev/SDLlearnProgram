#pragma once

#include <utility>      
#include <string>       
#include <iostream>     
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

#include <list>
/**
 * .not created yet may be expanded on to deal with dependencies
 */
class eventfactory
{
private:
	std::list<shape*> shapeList;
public:


	eventfactory();
	shape* addShape(std::string shapeProduct);





	
};

