#include "pch.h"
#include "CppUnitTest.h"
#include "renderTexture.h"
#include "SDL.h"
#include <exception>
#include <contextalreadyset.h>
#include "parser.h"
#include "nonnumberexception.h"
#include "invalidParameters.h"
#include "Render.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fullyworkingunittests
{
	TEST_CLASS(fullyworkingunittests)
	{
	public:
		
		TEST_METHOD(circlestringasnum)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("circle beef");

			


			auto func = [myparser] { myparser->syntaxCheckAll(); };
			Assert::ExpectException<nonnumberexception>(func);
			

		}


		TEST_METHOD(circlevalidtest)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("circle 50");

			Render* myrenderer = new Render();

			

			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);

			SDL_Texture* mytext2;
			mytext2 = myparser->runForAll(myrenderer,mytext);

			Assert::IsTrue(mytext == mytext2);

		}


		TEST_METHOD(rectanglevalid)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("rectangle 50 50");

			Render* myrenderer = new Render();



			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);

			SDL_Texture* mytext2;
			mytext2 = myparser->runForAll(myrenderer, mytext);

			Assert::IsTrue(mytext == mytext2);

		}
		TEST_METHOD(trianglevalid)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("triangle 50 50 60 70");

			Render* myrenderer = new Render();



			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);

			SDL_Texture* mytext2;
			mytext2 = myparser->runForAll(myrenderer, mytext);

			Assert::IsTrue(mytext == mytext2);

		}
		TEST_METHOD(clearvalid)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("clear");

			Render* myrenderer = new Render();



			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);

			SDL_Texture* mytext2;
			mytext2 = myparser->runForAll(myrenderer, mytext);

			Assert::IsTrue(mytext == mytext2);

		}
		
		TEST_METHOD(toofewrectangle)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("rectangle 100");




			auto func = [myparser] { myparser->syntaxCheckAll(); };
			Assert::ExpectException<InvalidParameters>(func);


		}
		TEST_METHOD(toofewtriangles)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("Triangle 100");




			auto func = [myparser] { myparser->syntaxCheckAll(); };
			Assert::ExpectException<InvalidParameters>(func);


		}
		
		TEST_METHOD(fillupdate)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("fill on");

			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);


			//auto func = [myparser,myrenderer,mytext] { myparser->runForAll(myrenderer,mytext); };
			myparser->runForAll(myrenderer, mytext);
			bool fill = myrenderer->getFill();
			Assert::IsTrue(fill);


		
		}
		TEST_METHOD(badfill)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("fill beef");




			auto func = [myparser] { myparser->syntaxCheckAll(); };
			Assert::ExpectException<nonfillvalue>(func);


		}

		TEST_METHOD(movetotestupdate)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("moveTo 200 300");
			
			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);

			
			//auto func = [myparser,myrenderer,mytext] { myparser->runForAll(myrenderer,mytext); };
			myparser->runForAll(myrenderer, mytext);
			std::pair<float, float> newPen = myrenderer->getPen();
			Assert::AreEqual(std::to_string((int)newPen.first).c_str(),"200");
			
			
			


		}

	

	};
}



