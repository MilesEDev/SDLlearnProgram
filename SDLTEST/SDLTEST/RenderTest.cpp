#include "RenderTest.h"
#include <iostream>

RenderTest::RenderTest()
{
   
   
   
	mywindow = SDL_CreateWindow("", 500, 50, 800, 500, SDL_WINDOW_OPENGL);
	
}

void RenderTest::drawToer(int line,int line2)
{
	mytext = SDL_CreateTexture(myrendererth12, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
	SDL_Renderer* myrendererth1 = SDL_CreateRenderer(mywindow, 3, SDL_RENDERER_TARGETTEXTURE);
	// ^-- this why it's working, the render was created in this thread so will work in this thread and only this thread!

	//std::this_thread::sleep_for(std::chrono::seconds(10));
	mySemaphore.acquire();
	SDL_SetRenderTarget(myrendererth1, mytext);
	
	SDL_SetRenderDrawColor(myrendererth1, 255, 0, 0, 255);
	
	SDL_RenderClear(myrendererth1);
	//std::this_thread::sleep_for(std::chrono::seconds(10));
	SDL_SetRenderTarget(myrendererth1, nullptr);
	SDL_RenderCopy(myrendererth1, mytext, nullptr, nullptr);

	SDL_RenderPresent(myrendererth1);
	SDL_Delay(5000);

	mySemaphore.release();
	RenderPassOn(myrendererth1);
	
	//presentText();
	
	



	


}

void RenderTest::diffcol()
{

	
	SDL_Renderer* myrendererth1 = SDL_CreateRenderer(mywindow, 3, SDL_RENDERER_TARGETTEXTURE);
	mySemaphore.acquire();
	SDL_SetRenderTarget(myrendererth1, mytext);
	
	SDL_SetRenderDrawColor(myrendererth1, 0, 255, 0, 255);
	SDL_RenderClear(myrendererth1);
	
	SDL_SetRenderTarget(myrendererth1, nullptr);
	SDL_RenderCopy(myrendererth1, mytext, nullptr, nullptr);
	SDL_RenderPresent(myrendererth1);
	SDL_Delay(5000);
	mySemaphore.release();
	RenderPassOnT2(myrendererth1);
	
	

	

}


void RenderTest::RenderPassOn(SDL_Renderer* &toPass)
{

	mySemaphore.acquire();
	SDL_SetRenderTarget(toPass, mytext);

	SDL_SetRenderDrawColor(toPass, 0, 0, 0, 0);
	SDL_RenderClear(toPass);

	SDL_SetRenderTarget(toPass, nullptr);
	SDL_RenderCopy(toPass, mytext, nullptr, nullptr);
	SDL_RenderPresent(toPass);
	SDL_Delay(5000);
	mySemaphore.release();
}

void RenderTest::RenderPassOnT2(SDL_Renderer* &toPass)
{
	
	mySemaphore.acquire();
	SDL_SetRenderTarget(toPass, mytext);

	SDL_SetRenderDrawColor(toPass, 255, 255, 255, 255);
	SDL_RenderClear(toPass);

	SDL_SetRenderTarget(toPass, nullptr);
	SDL_RenderCopy(toPass, mytext, nullptr, nullptr);
	SDL_RenderPresent(toPass);
	SDL_Delay(5000);
	mySemaphore.release();
}

void RenderTest::startThreadsInternally()
{
	std::thread thread_runner1(&RenderTest::drawToer,this,5,10);
	//std::thread thread_runner2(&RenderTest::diffcol, this);

	thread_runner1.join();
	//thread_runner2.join();
}
