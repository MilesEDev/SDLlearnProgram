#include "pch.h"
#include "CppUnitTest.h"
#include "renderTexture.h"
#include "SDL.h"
#include <exception>
#include <contextalreadyset.h>
#include "parser.h"
#include "nonnumberexception.h"
#include "invalidParameters.h"



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
		TEST_METHOD(toofewrectangle)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("rectangle 100");




			auto func = [myparser] { myparser->syntaxCheckAll(); };
			Assert::ExpectException<InvalidParameters>(func);


		}

	

	};
}



