#include "pch.h"
#include "CppUnitTest.h"
#include "renderTexture.h"
#include "SDL.h"
#include <exception>
#include <contextalreadyset.h>

/*


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fullyworkingunittests
{
	TEST_CLASS(fullyworkingunittests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			SDL_Window* mockWindow = SDL_CreateWindow("window", 200, 200, 200, 200, SDL_WINDOW_HIDDEN);
			SDL_Renderer* mockRenderer = SDL_CreateRenderer(mockWindow, -1, 0);
			renderTexture* mockTexture = new renderTexture(mockRenderer);


			SDL_Renderer* mockRenderer2 = SDL_CreateRenderer(mockWindow, -1, 0);
			auto func = [mockTexture, mockRenderer2] { mockTexture->linkTextureToRender(mockRenderer2); };
			Assert::ExpectException<std::invalid_argument>(func);
		

		}
	

	};
}
*/