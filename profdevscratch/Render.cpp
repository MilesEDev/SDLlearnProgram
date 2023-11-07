#pragma once
#include <utility>      
#include <string>       
#include <iostream>   

#include "Render.h"


Render::Render()
{
	penStartCordinate = std::make_pair(0.0f, 0.0f);
}

Render::Render(window* mywindow) 
{
	penStartCordinate = std::make_pair(0.0f, 0.0f);
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
void Render::setPenColourRGBA(int R, int B, int G, int A)
{
	SDL_SetRenderDrawColor(myrenderer, R,G,B,A);
}
void Render::setPenColourString(std::string colour) 
{
	if (colour == "red")
	{
		SDL_SetRenderDrawColor(myrenderer, 255, 0, 0, 255);
	}
	else if (colour == "blue") {

		SDL_SetRenderDrawColor(myrenderer, 0, 0, 255, 255);
	}
	else if (colour == "green") 
	{
		SDL_SetRenderDrawColor(myrenderer, 0, 255, 0, 255);
	}
	else 
	{
		int donothing = 0;
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





