#include "pch.h"
#include "CppUnitTest.h"
#include "Expression.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace memoryAndExpressionsTests
{
	TEST_CLASS(memoryAndExpressionsTests)
	{
		TEST_METHOD(expressionsTest)
		{
			Expression* myExpression = new Expression();
			
			Assert::IsTrue(3 == std::stoi(myExpression->calcFull("1+2")));
		}

	};
}