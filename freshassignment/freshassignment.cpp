// freshassignment.cpp : This file contains the 'main' function. Program execution begins and ends the#



#include <iostream>
#include "SDL.h"
#undef main
int main()
{
	SDL_Window* window = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
		500, 
		50, 
		800, 
		500,
		SDL_WINDOW_SHOWN); 
	
	SDL_Init(SDL_INIT_EVERYTHING);

	

	SDL_Renderer* myrenderer = SDL_CreateRenderer(window, -1,0);
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	SDL_SetRenderDrawColor(myrenderer, 255, 0, 0, 255);
	SDL_Rect* srcrect = new SDL_Rect();
	srcrect->x = 50;
	srcrect->y = 50;
	srcrect->w = 20;
	srcrect->h = 20;
	


	SDL_UpdateWindowSurface(window);

	SDL_RenderClear(myrenderer);
	

	SDL_UpdateWindowSurface(window);
	
	SDL_SetRenderDrawColor(myrenderer, 0, 255, 0, 255);
	SDL_UpdateWindowSurface(window);
	SDL_RenderDrawRect(myrenderer, srcrect);
	SDL_UpdateWindowSurface(window);


	Uint32 col = SDL_MapRGB(0, 255, 0, 255);
	SDL_FillRect(surface, srcrect, col);
	SDL_UpdateWindowSurface(window);
	SDL_UpdateWindowSurfaceRects(window,srcrect,1);
	SDL_FillRect(surface, srcrect, col);
	SDL_UpdateWindowSurface(window);
	SDL_UpdateWindowSurfaceRects(window, srcrect, 1);
	SDL_Delay(5000);
	SDL_RenderPresent(myrenderer);

	
	SDL_Delay(5000);

	SDL_DestroyWindow(window);
	SDL_Quit();
	

	return 0;

   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
