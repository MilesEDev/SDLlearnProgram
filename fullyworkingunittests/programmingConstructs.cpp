#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <fstream>
#include "whileCommand.h"
#include "Function.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fullyworkingunittests
{
	TEST_CLASS(programmingConstructs)
	{
	public:

		TEST_METHOD(whileLoopTest)
		{
			bool execution = false;
			std::vector<std::string> commandArgs = {"2",">","1"};
			whileCommand* myWhile = new whileCommand();
			myWhile->setLocalExecution(execution);
			myWhile->setAttributes(commandArgs);
			myWhile->runCommand();
			Assert::IsTrue(true == myWhile->getLocalExecution());


		}
		TEST_METHOD(functionTest)
		{
			Function* thisFunc = new Function("myMethod(myparamA,myparamB)");
		}
		TEST_METHOD(ifTest)
		{
			Function* thisFunc = new Function("myMethod(myparamA,myparamB)");
		}
	



	};
}
