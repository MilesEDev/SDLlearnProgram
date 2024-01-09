#include "pch.h"
#include "CppUnitTest.h"
#include "commandFactory.h"
#include "Commands.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fullyworkingunittests
{
	TEST_CLASS(designPattern)
	{
		/**
		 * .checks factory pattern used well
		 * 
		 */
		TEST_METHOD(factoryTest)
		{
			commandFactory* myFactory = commandFactory::getInstance();
			Commands* myCommand = myFactory->getCommand("circle");
			Assert::IsTrue(myCommand != nullptr);

		}
		/**
		 * .checks singleton pattern has been used 
		 * 
		 */
		TEST_METHOD(SingletonTest)
		{
			commandFactory* myFactory = commandFactory::getInstance();
			Assert::IsTrue(myFactory != nullptr);
		}

	};
}
