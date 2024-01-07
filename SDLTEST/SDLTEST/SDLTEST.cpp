// SDLTEST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "SDL.h"
#include "RenderTest.h"
#include <vector>
#undef main
int main()
{

	SDL_Window* mywindow = SDL_CreateWindow("", 500, 50, 800, 500, SDL_WINDOW_OPENGL);
	SDL_Renderer* myrenderer = SDL_CreateRenderer(mywindow, 3, 0);
	SDL_SetRenderDrawColor(myrenderer, 255, 0, 0, 255);

	SDL_Vertex vertex_1 = {{400,400},{255, 0, 0, 255},{1, 1}};


	SDL_Vertex vertex_2 = {{500,500},{255, 0, 0, 255},{1, 1}};
	SDL_Vertex vertex_3 = {{600, 600},{255, 0, 0, 255},{1, 1}};

	SDL_Vertex vertices[3] = {vertex_1,vertex_2,vertex_3};
	SDL_RenderGeometry(myrenderer,nullptr, vertices, 3, NULL, 0);

	
	
	//SDL_RenderClear(myrenderer);
	SDL_RenderPresent(myrenderer);
	SDL_Delay(5000);

	



	

	
	
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
