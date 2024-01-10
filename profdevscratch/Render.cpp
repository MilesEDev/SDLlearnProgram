#pragma once
#include <utility>      
#include <string>       
#include <iostream>   

#include "Render.h"
#include "shape.h"

Render::Render()
{
	penStartCordinate = std::make_pair(0.0f, 0.0f);
}

Render::Render(window* mywindow) 
{
	penStartCordinate = std::make_pair(0.0f, 0.0f);
	renderWindow = mywindow;
	canvas = mywindow->getSDLWindow();
	myrenderer = SDL_CreateRenderer(canvas, 3, 0); 
}
Render::Render(SDL_Renderer* SDLRenderer)
{
	penStartCordinate = std::make_pair(0.0f, 0.0f);
	myrenderer = SDLRenderer;


}

void Render::linkToWindow(window* mywindow) 
{
	renderWindow = mywindow;
	canvas = mywindow->getSDLWindow();
	myrenderer = SDL_CreateRenderer(canvas, 3, 0);
}
void Render::setPen(float x, float y)
{
	penStartCordinate.first = x;
	penStartCordinate.second = y;
}
void Render::drawTo(float x, float y) 
{
	SDL_RenderDrawLine(myrenderer, penStartCordinate.first, penStartCordinate.second, x, y);


	setPen(x, y);
	
}
void Render::setPenColourRGBA(Uint8 R, Uint8 G, Uint8 B, Uint8 A)
{
	
	penRGBA.clear();
	penRGBA.push_back(R);
	penRGBA.push_back(G);
	penRGBA.push_back(B);
	penRGBA.push_back(A);
	SDL_SetRenderDrawColor(myrenderer, R, G, B, A);

	

}
void Render::resetSDLColours() 
{
	SDL_SetRenderDrawColor(myrenderer, penRGBA[0], penRGBA[1], penRGBA[2], penRGBA[3]);
}
void Render::setPenColourString(std::string colour) 
{
	if (colour == "red")
	{
		setPenColourRGBA(255, 0, 0, 255);
		
	}
	else if (colour == "blue") {

		setPenColourRGBA(0, 255, 0, 255);
	}
	else if (colour == "green") 
	{
		setPenColourRGBA(0, 0, 255, 255);
	}
	else 
	{
		error = "this is not a colour";
	}
}
void Render::renderClear() 
{
	SDL_RenderClear(myrenderer);
}
void Render::showRender() 
{
	SDL_RenderPresent(myrenderer);
}

void Render::renderClearAbsoloute() {

	SDL_SetRenderDrawColor(myrenderer,0, 0, 0, 0);
	SDL_RenderClear(myrenderer);
	SDL_RenderPresent(myrenderer);
}


SDL_Renderer* Render::getSDLRenderer() 
{
	return myrenderer; 
}
void Render::setSDLRenderer(SDL_Renderer* myNewRenderer) 
{

	myrenderer = myNewRenderer;
}
void Render::setFill(bool onOrOff) 
{
	fill = onOrOff;
	
}
std::vector<Uint8> Render::getPenColour() {

	return penRGBA;
}
void Render::setPenColour(std::vector<Uint8> newColour)
{
	penRGBA = newColour;
}
bool Render::getFill()
{
	return fill;
}
std::pair<float, float> Render::getPen() 
{
	return penStartCordinate;
}
window* Render::getWindow() {

	return renderWindow;
}


void Render::drawShapeToText(shape* shapearg) {
	

	this->penStartCordinate = shapearg->renderself(myrenderer, penRGBA, fill);
	
}

std::string Render::getLastError()
{
	return error;
}

void Render::removeAnyTargets()
{
	SDL_SetRenderTarget(myrenderer, nullptr);
}


