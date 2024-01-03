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
#include "gui.h"
#include <iostream>
#include <fstream>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fullyworkingunittests
{
	TEST_CLASS(fullyworkingunittests)
	{
	public:
		/**
		 * .test method for checking if string added as float is handled
		 * 
		 */
		TEST_METHOD(circlestringasnum)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("circle beef");

			

			std::string error = myparser->syntaxCheckAll();
			int line = 0;

			Assert::IsTrue(error == "you have put in an incorrect data type for colourCommand please enter a float with the format(number)e.g circle 54 on line 1");


			

		}

		/**
		 * .test to see if circle renders with valid data
		 * 
		 */
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

		/**
		 * test to see if rectangle with valid parameters can be created.
		 * 
		 */
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
		/**
		 * .test to see if triangle with valid data can be created
		 * 
		 */
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
		/**
		 * .see if the clear function can clear 
		 * 
		 */
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
		
		/**
		 * .test for too few paramets on rectangle
		 * 
		 */
		TEST_METHOD(toofewrectangle)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("rectangle 100");

			

			std::string error = myparser->syntaxCheckAll();
			int line = 0;
		
			Assert::IsTrue(error == "you have entered the incorrect number of parameters on line 1");


		}
		/**
		 * 
		 * .test for too few parameters on triangles
		 * 
		 */
		TEST_METHOD(toofewtriangles)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("triangle 100");



			std::string error = myparser->syntaxCheckAll();
			int line = 0;

			Assert::IsTrue(error == "you have entered the incorrect number of parameters on line 1");




		}
		/**
		 * .test to see if fill command updates fill
		 * 
		 */
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
		/**
		 * .test to see if fill with invalid fill property is handled
		 * 
		 */
		TEST_METHOD(badfill)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("fill beef");

			std::string error = myparser->syntaxCheckAll();
			int line = 0;

			Assert::IsTrue(error == "you have entered an incorrect value for fill please enter on or off or true or false e.g fill on on line 1");




		}
		/**
		 * .moveto test to make sure pen changes
		 * 
		 */
		TEST_METHOD(movetotestupdate)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("moveTo 200 300");
			
			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);

			
			//auto func = [myparser,myrenderer,mytext] { myparser->runForAll(myrenderer,mytext); };
			myparser->runForAll(myrenderer, mytext);
			std::pair<float, float> newPen = myrenderer->getPen();
			Assert::IsTrue(newPen.first == 200 && newPen.second == 300);
			
			
			


		}
		/**
		 * .make sure update colour by checking if colours have changed
		 * 
		 */
		TEST_METHOD(updatecolour)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("pen \"green\"");

			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
			std::vector<Uint8> colours = { 0,255,0,255};

			//auto func = [myparser,myrenderer,mytext] { myparser->runForAll(myrenderer,mytext); };
			myparser->runForAll(myrenderer, mytext);
			std::vector<Uint8> actualColours = myrenderer->getPenColour();
			Assert::IsTrue(colours[0] == actualColours[0] && colours[1] == actualColours[1] && colours[2] == actualColours[2]
				&& colours[3] == actualColours[3]);
				
			
			
			

		}
		/**
		 * .check to make sure pen pos changes after drawto
		 * 
		 */
		TEST_METHOD(drawtotestupdate)
		{

			parser* myparser = new parser();

			myparser->splitToCommands("drawto 100 400");

			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);


			//auto func = [myparser,myrenderer,mytext] { myparser->runForAll(myrenderer,mytext); };
			myparser->runForAll(myrenderer, mytext);
			std::pair<float, float> newPen = myrenderer->getPen();
			Assert::IsTrue(newPen.first == 100 && newPen.second == 400);


		}
		/**
		 * .test to make sure resettest sets pen back to correct pos
		 * 
		 */
		TEST_METHOD(resettest)
		{

			parser* myparser = new parser();

			
			myparser->splitToCommands("reset");

			Render* myrenderer = new Render();
			myrenderer->setPen(100, 100);
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);


			//auto func = [myparser,myrenderer,mytext] { myparser->runForAll(myrenderer,mytext); };
			myparser->runForAll(myrenderer, mytext);
			std::pair<float, float> newPen = myrenderer->getPen();
			Assert::IsTrue(newPen.first == 0 && newPen.second == 0);


		}
		

		

		/**
		 * .this is testing for multi line command inputs into command line
		 * 
		 */
		TEST_METHOD(multilinetest)
		{
			gui* mygui = new gui();
			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
			mygui->setConsoleInput("run");

			parser* newparser = new parser();
			if (mygui->getConsoleInput() == "run")
			{
				mygui->setMultiLine("circle 60");
				newparser->splitToCommands(mygui->getMultiLine());
			}
			SDL_Texture* mytext2;
			mytext2 = newparser->runForAll(myrenderer, mytext);

			Assert::IsTrue(mytext == mytext2);



		}
		/**
		 * 
		 * .this is testing for single line command inputs into command line
		 * 
		 */
		TEST_METHOD(singlecommandlinetest)
		{
			gui* mygui = new gui();
			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
			mygui->setConsoleInput("circle 50");

			parser* newparser = new parser();

			newparser->splitToCommands(mygui->getConsoleInput());

			SDL_Texture* mytext2;
			mytext2 = newparser->runForAll(myrenderer, mytext);

			Assert::IsTrue(mytext == mytext2);




		}
		TEST_METHOD(invalidcommand) 
		{
			parser* myparser = new parser();

			myparser->splitToCommands("crce 100");



			auto func = [myparser] { myparser->syntaxCheckAll(); };
			Assert::ExpectException<notcommandexception>(func);


		}

		

		
	};
}



