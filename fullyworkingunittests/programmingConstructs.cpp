#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <fstream>
#include "whileCommand.h"
#include "Function.h"
#include "ifCommand.h"
#include "parser.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fullyworkingunittests
{
	TEST_CLASS(programmingConstructs)
	{
	public:
		/**
		 * .tests to see if while loop works
		 * 
		 */
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
		/**
		 * .tests to see if the function test works 
		 * 
		 */
		TEST_METHOD(functionTest)
		{
			bool assert = false;
			MemoryManager* funcMem;
			Function* thisFunc = new Function("myMethod(myparamA,myparamB)");
			thisFunc->setArgs("myMethod(50,60)");
			thisFunc->addArgsToMemory();
			funcMem = thisFunc->updateMemory();
			std::string arg1 = funcMem->returnValue("myparamA");
			std::string arg2 = funcMem->returnValue("myparamB");
			if (arg1 == "50.000000" && arg2 == "60.000000")
			{
				assert = true;
			}
			Assert::IsTrue(assert == true);


			

		}
		/**
		 * .test to see the if command works 
		 * 
		 */
		TEST_METHOD(ifTest)
		{
			bool execution = false;
			std::vector<std::string> commandArgs = { "2",">","1" };
			ifCommand* myIf = new ifCommand();
			myIf->setLocalExecution(execution);
			myIf->setAttributes(commandArgs);
			myIf->runCommand();
			Assert::IsTrue(true == myIf->getLocalExecution());

		}
		/**
		 * .test for nested bodies
		 * 
		 */
		TEST_METHOD(nestedBodiesTest)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("if 2 < 1\nif 2 < 1\ncircle 50\nendif\nendif");

			std::string error = myparser->syntaxCheckAll();
			int line = 0;

			Assert::IsTrue(error == "ok");


		}
		/**
		 * .test for function encapsulation
		 * 
		 */
		TEST_METHOD(funcEncapTest)
		{
			parser* myparser = new parser();

			myparser->splitToCommands("myVar=50\nmethod myMethod()\ncircle myVar\nendmethod");

			std::string error = myparser->syntaxCheckAll();
			int line = 0;

			Assert::IsTrue(error == "you have tried to use a variable that has not been defined on line 3\n");
		}




	};
}
