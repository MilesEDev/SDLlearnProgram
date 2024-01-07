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
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			
			Assert::IsTrue(3 == std::stoi(myExpression->calcFull("1+2",myMemory)));
		}
		TEST_METHOD(expressionsTestTwoAdds)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(5 == std::stoi(myExpression->calcFull("1+2+2",myMemory)));
		}
		TEST_METHOD(expressionsTestTwoAddsBig)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(50 == std::stoi(myExpression->calcFull("10+20+20",myMemory)));
		}
		TEST_METHOD(expressionsTestTwoMinus)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(0 == std::stoi(myExpression->calcFull("3-2-1",myMemory)));
		}
		TEST_METHOD(expressionsTestMinus)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(1 == std::stoi(myExpression->calcFull("2-1",myMemory)));
		}
		TEST_METHOD(expressionsTestAddAndMinus)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(1 == std::stoi(myExpression->calcFull("4-1+2",myMemory)));
		}
		TEST_METHOD(expressionsTestAddAndMinusBigNums)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(10 == std::stoi(myExpression->calcFull("40-10+20",myMemory)));
		}
		TEST_METHOD(expressionsTestDivide)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(4 == std::stoi(myExpression->calcFull("8/2",myMemory)));
		}
		TEST_METHOD(expressionsTestDivideAdd)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(5 == std::stoi(myExpression->calcFull("8/2+1",myMemory)));
		}
		TEST_METHOD(expressionsTestMultiply)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(16 == std::stoi(myExpression->calcFull("8*2",myMemory)));
		}
		TEST_METHOD(expressionsTestSubtractAndMultiply)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(15 == std::stoi(myExpression->calcFull("8*2-1",myMemory)));
		}
		TEST_METHOD(FullBidmassUnordered)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(-29 == std::stoi(myExpression->calcFull("5-2*2/1+30",myMemory)));
		}
		TEST_METHOD(stringToString)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			Assert::IsTrue("\"helloworld\"" == myExpression->calcFull("\"hello\"+\"world\"",myMemory));
		}
		TEST_METHOD(stringWithSpecial)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			Assert::IsTrue("\"hel\\\"loworld\"" == myExpression->calcFull("\"hel\\\"lo\"+\"world\"",myMemory));
		}
		TEST_METHOD(isExpressionStandard)
		{
			
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("5+4");
			Assert::IsTrue(true == passes);
		}
		TEST_METHOD(isExpressiondoubleplus)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("5+4+5");
			Assert::IsTrue(true == passes);
		}
		TEST_METHOD(isExpressionminus)
		{

			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("5-4");
			Assert::IsTrue(true == passes);
		}
		TEST_METHOD(isExpressionnot)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("54");
			Assert::IsTrue(false == passes);
		}
		TEST_METHOD(isExpressionstr)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("\"hello\"+\"world\"");
			Assert::IsTrue(true == passes);
		}
		TEST_METHOD(isExpressionOperationInStr)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("\"hello+\"+\"world\"");
			Assert::IsTrue(true == passes);
		}
		TEST_METHOD(isExpressionOperationInStrFalse)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("\"hello+\"\"world\"");
			Assert::IsTrue(false == passes);
		}
		TEST_METHOD(isAssignmentStandard)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isAssignment("hello=roar");
			Assert::IsTrue(true == passes);
		}
		TEST_METHOD(isAssignmentInString)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isAssignment("\"hello=roar\"");
			Assert::IsTrue(false == passes);
		}
		TEST_METHOD(isAssignmentInStringEqualsFirst)
		{
			
			Expression* myExpression = new Expression();
			bool passes = myExpression->isAssignment("=hi");
			Assert::IsTrue(false == passes);
		}
		TEST_METHOD(isAssignmentInStringEqualsLast)
		{
			
			Expression* myExpression = new Expression();
			bool passes = myExpression->isAssignment("hi=");
			Assert::IsTrue(false == passes);
		}
		TEST_METHOD(checkAssingmentToValidValue)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			bool passes = myExpression->checkAssignment("myVar=50",myMemory);
			Assert::IsTrue(true == passes);
		}
		TEST_METHOD(checkAssingmentToValidExpression)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			bool passes = myExpression->checkAssignment("myVar=50+40",myMemory);
			Assert::IsTrue(true == passes);
		}
		TEST_METHOD(checkAssingmentToInvalidValue)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			bool passes = myExpression->checkAssignment("myVar=abur",myMemory);
			Assert::IsTrue(false == passes);
		}
		




		


		










	};
}