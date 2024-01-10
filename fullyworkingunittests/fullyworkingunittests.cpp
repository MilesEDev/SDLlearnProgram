#include "pch.h"
#include "CppUnitTest.h"
#include "renderTexture.h"
#include "SDL.h"
#include <exception>
#include <contextalreadyset.h>
#include "nonnumberexception.h"
#include "invalidParameters.h"
#include "gui.h"
#include <iostream>
#include <fstream>
#include "ThreadManager.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fullyworkingunittests
{
	TEST_CLASS(fullyworkingunittests)
	{
	public:
		gui* mygui = new gui;
		/**
		 * .test method for checking if string added as float is handled
		 * 
		 */
		TEST_METHOD(circlestringasnum)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("circle \"beef\"");

			

			std::string error = myparser->syntaxCheckAll();
			int line = 0;

			Assert::IsTrue(error == "you have put in an incorrect data type for circleCommand please enter a float with the format(number)e.g circle 54 on line 1\n");


			

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

			
			std::string tempError;
			std::pair<SDL_Texture*, std::string> runData;
			runData = myparser->runForAll(myrenderer, mytext);
			tempError = runData.second;
			
			Assert::IsTrue(tempError == "ok");

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

			std::string tempError;
			std::pair<SDL_Texture*, std::string> runData;
			runData = myparser->runForAll(myrenderer, mytext);
			tempError = runData.second;

			Assert::IsTrue(tempError == "ok");
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

			std::string tempError;
			std::pair<SDL_Texture*, std::string> runData;
			runData = myparser->runForAll(myrenderer, mytext);
			tempError = runData.second;

			Assert::IsTrue(tempError == "ok");

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

			std::string tempError;
			std::pair<SDL_Texture*, std::string> runData;
			runData = myparser->runForAll(myrenderer, mytext);
			tempError = runData.second;

			Assert::IsTrue(tempError == "ok");
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
		
			Assert::IsTrue(error == "you have entered the incorrect number of parameters on line 1\n");


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

			Assert::IsTrue(error == "you have entered the incorrect number of parameters on line 1\n");




		}
		/**
		 * .test to see if fill command updates fill
		 * 
		 */
		TEST_METHOD(fillupdate)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("fill true");

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

			myparser->splitToCommands("fill \"beef\"");

			std::string error = myparser->syntaxCheckAll();
			int line = 0;

			Assert::IsTrue(error == "you have entered an incorrect value for fill please enter  true or false e.g fill true on line 1\n");




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

			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
			mygui->setConsoleInput("run");

			parser* newparser = new parser();
			if (mygui->getConsoleInput() == "run")
			{
				mygui->setMultiLine("circle 60");
				newparser->splitToCommands(mygui->getMultiLine());
			}
			std::string tempError;
			std::pair<SDL_Texture*, std::string> runData;
			runData = newparser->runForAll(myrenderer, mytext);
			tempError = runData.second;

			Assert::IsTrue(tempError == "ok");


		}
		/**
		 * 
		 * .this is testing for single line command inputs into command line
		 * 
		 */
		TEST_METHOD(singlecommandlinetest)
		{
			
			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
			mygui->setConsoleInput("circle 50");

			parser* newparser = new parser();

			newparser->splitToCommands(mygui->getConsoleInput());

			std::string tempError;
			std::pair<SDL_Texture*, std::string> runData;
			runData = newparser->runForAll(myrenderer, mytext);
			tempError = runData.second;
			
			Assert::IsTrue(tempError == "ok");



		}
		TEST_METHOD(invalidcommand) 
		{
			parser* myparser = new parser();

			myparser->splitToCommands("crce 100");

			std::string error = myparser->syntaxCheckAll();
	
			Assert::IsTrue(error == "you have entered something that is not a command nore an assignment on line 1\n");

			


		}
		TEST_METHOD(doubleThread)
		{
			gui* threadTester = new gui();
			Render* myrenderer = new Render();
			SDL_Texture* mytext = SDL_CreateTexture(myrenderer->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 500);
			std::string myStr = "";
			std::string myStr2 = "";
			bool running = false;
			bool running2 = false;
			std::string program = "circle 50";
			running = true;
			running2 = true;

			std::thread thread_runner1(&gui::runnerThreaded,*&threadTester,myrenderer,program,std::ref(myStr),std::ref(running),1);
			
			thread_runner1.detach();
			std::thread thread_runner2(&gui::runnerThreaded, *&threadTester, myrenderer, program, std::ref(myStr2), std::ref(running2),2);

			thread_runner2.detach();


			while (running != false)
			{
				if (threadTester->getManager()->getToRun() != nullptr)
				{
					std::cout << mytext << std::endl;
					SDL_SetRenderTarget(myrenderer->getSDLRenderer(), mytext);
					threadTester->getManager()->getToRun()->runCommand(myrenderer, myrenderer->getPen());
					threadTester->getManager()->setToRun(nullptr);
					myrenderer->removeAnyTargets();
					SDL_RenderCopy(myrenderer->getSDLRenderer(), mytext, nullptr, nullptr);

					std::cout << "hello world" << std::endl;


					std::cout << "main thread release" << std::endl;
					threadTester->releaseMainSemaphore();

				}
			}
			
			Assert::IsTrue(myStr+myStr2 == "okok");
			
		}
		
		
		TEST_METHOD(syntaxCheck)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("circle \"stringTestingCheck\"");



			std::string error = myparser->syntaxCheckAll();
			int line = 0;

			Assert::IsTrue(error == "you have put in an incorrect data type for circleCommand please enter a float with the format(number)e.g circle 54 on line 1\n");

		}
		
	};
}



