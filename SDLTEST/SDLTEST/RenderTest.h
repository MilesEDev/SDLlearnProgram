#pragma once
#include "SDL.h"
#include <thread>
#include <semaphore> 



#undef main

class RenderTest
{
private:
	SDL_Renderer* myrendererth12;
	SDL_Window* mywindow;



	SDL_Texture* mytext;
public:
	

	std::binary_semaphore mySemaphore{ 1 };
	
	

	RenderTest();

	void drawToer(int line, int line2);
	
	

	void diffcol();

	void presentText();

	void RenderPassOn(SDL_Renderer* &toPass);

	void RenderPassOnT2(SDL_Renderer* &toPass);

	void startThreadsInternally();
	
	


};

