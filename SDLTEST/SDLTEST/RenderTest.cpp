#include "RenderTest.h"
#include <iostream>
/*
RenderTest::RenderTest()
{
    mywindow = SDL_CreateWindow("", 500, 50, 800, 500, SDL_WINDOW_OPENGL);
	mywindow2 = SDL_CreateWindow("", 0, 50, 300, 500, SDL_WINDOW_OPENGL);


	
	
	

	mytext = SDL_CreateTexture(myrendererth2, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
	mytext2 = SDL_CreateTexture(myrendererth2, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);


}

void RenderTest::drawToer(int line,int line2)
{

	//std::this_thread::sleep_for(std::chrono::seconds(10));
	//mySemaphore.acquire();
	SDL_SetRenderTarget(myrendererth1, mytext);
	
	SDL_SetRenderDrawColor(myrendererth1, 255, 0, 0, 255);
	
	SDL_RenderDrawLine(myrendererth1, 0, 0, 10, 30);
	std::this_thread::sleep_for(std::chrono::seconds(10));
	
	
	
	
	presentText();
	SDL_Delay(5000);
	
	



	


}
void RenderTest::diffcol()
{

	
	
	
	SDL_SetRenderTarget(myrendererth1, mytext2);
	
	SDL_SetRenderDrawColor(myrendererth1, 0, 255, 0, 255);
	SDL_RenderClear(myrendererth1);
	std::this_thread::sleep_for(std::chrono::seconds(10));
	SDL_SetRenderTarget(myrendererth1, nullptr);
	SDL_RenderCopy(myrendererth1, mytext2, nullptr, nullptr);
	SDL_RenderPresent(myrendererth2);
	//presentText2();
	
	//SDL_Delay(5000);

	
	

	

}

void RenderTest::presentText()
{
	SDL_SetRenderTarget(myrendererth1, nullptr);
	SDL_RenderCopy(myrendererth1, mytext, nullptr, nullptr);

	SDL_RenderPresent(myrendererth1);
}

void RenderTest::presentText2()
{
	SDL_SetRenderTarget(myrendererth2, nullptr);


	SDL_RenderCopy(myrendererth2, mytext, nullptr, nullptr);

	SDL_RenderPresent(myrendererth2);
}

void RenderTest::simpleThread(int &num)
{
	std::cout << "hello";
}
*/