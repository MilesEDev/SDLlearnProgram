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
		TEST_METHOD(expressionsTestTwoAdds)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(5 == std::stoi(myExpression->calcFull("1+2+2")));
		}
		TEST_METHOD(expressionsTestTwoAddsBig)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(50 == std::stoi(myExpression->calcFull("10+20+20")));
		}
		TEST_METHOD(expressionsTestTwoMinus)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(0 == std::stoi(myExpression->calcFull("3-2-1")));
		}
		TEST_METHOD(expressionsTestMinus)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(1 == std::stoi(myExpression->calcFull("2-1")));
		}
		TEST_METHOD(expressionsTestAddAndMinus)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(1 == std::stoi(myExpression->calcFull("4-1+2")));
		}
		TEST_METHOD(expressionsTestAddAndMinusBigNums)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(10 == std::stoi(myExpression->calcFull("40-10+20")));
		}
		TEST_METHOD(expressionsTestDivide)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(4 == std::stoi(myExpression->calcFull("8/2")));
		}
		TEST_METHOD(expressionsTestDivideAdd)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(5 == std::stoi(myExpression->calcFull("8/2+1")));
		}
		TEST_METHOD(expressionsTestMultiply)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(16 == std::stoi(myExpression->calcFull("8*2")));
		}
		TEST_METHOD(expressionsTestSubtractAndMultiply)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(15 == std::stoi(myExpression->calcFull("8*2-1")));
		}
		TEST_METHOD(FullBidmassUnordered)
		{
			Expression* myExpression = new Expression();

			Assert::IsTrue(31 == std::stoi(myExpression->calcFull("5-2*2/1+30")));
		}











	};
}