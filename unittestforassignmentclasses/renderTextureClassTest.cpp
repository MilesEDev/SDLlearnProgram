#include "pch.h"
#include "CppUnitTest.h"
#include "renderTexture.h"
#include "SDL.h"

#include <contextalreadyset.h>




using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestforassignmentclasses
{
	TEST_CLASS(unittestforassignmentclasses)
	{
	public:

		TEST_METHOD(linkTextureToRenderTest)
		{
			
			
			SDL_Window* mockWindow = SDL_CreateWindow("window", 200, 200, 200, 200, SDL_WINDOW_HIDDEN);
			SDL_Renderer* mockRenderer = SDL_CreateRenderer(mockWindow, -1, 0);
			renderTexture* mockTexture = new renderTexture(mockRenderer);
			void (*func)(SDL_Renderer*);
			
			SDL_Renderer* mockRenderer2 = SDL_CreateRenderer(mockWindow, -1, 0);
			
		
		

		}


	};
}
