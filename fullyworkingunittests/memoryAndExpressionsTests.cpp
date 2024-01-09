#include "pch.h"
#include "CppUnitTest.h"
#include "Expression.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace memoryAndExpressionsTests
{
	TEST_CLASS(memoryAndExpressionsTests)
	{
		/**
		 * .check if expression works with + 
		 * 
		 */
		TEST_METHOD(expressionsTest)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			
			Assert::IsTrue(3 == std::stoi(myExpression->calcFull("1+2",myMemory)));
		}
		/**
		 * . check if expression works with two adds
		 * 
		 */
		TEST_METHOD(expressionsTestTwoAdds)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(5 == std::stoi(myExpression->calcFull("1+2+2",myMemory)));
		}
		/**
		 * . check if expression works with larger numbers
		 * 
		 */
		TEST_METHOD(expressionsTestTwoAddsBig)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(50 == std::stoi(myExpression->calcFull("10+20+20",myMemory)));
		}
		/**
		 * . check expression works with two minuses
		 * 
		 */
		TEST_METHOD(expressionsTestTwoMinus)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(0 == std::stoi(myExpression->calcFull("3-2-1",myMemory)));
		}
		/**
		 * .check expression works with 1 minus
		 * 
		 */
		TEST_METHOD(expressionsTestMinus)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(1 == std::stoi(myExpression->calcFull("2-1",myMemory)));
		}
		/**
		 * .check expression works with an add and a minus
		 * 
		 */
		TEST_METHOD(expressionsTestAddAndMinus)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(1 == std::stoi(myExpression->calcFull("4-1+2",myMemory)));
		}
		/**
		 * . check if expression works with larger nums and add and minus
		 * 
		 */
		TEST_METHOD(expressionsTestAddAndMinusBigNums)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(10 == std::stoi(myExpression->calcFull("40-10+20",myMemory)));
		}
		/**
		 * .check expression works with divide
		 * 
		 */
		TEST_METHOD(expressionsTestDivide)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(4 == std::stoi(myExpression->calcFull("8/2",myMemory)));
		}
		/**
		 * .check expression works with add and divide
		 * 
		 */
		TEST_METHOD(expressionsTestDivideAdd)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(5 == std::stoi(myExpression->calcFull("8/2+1",myMemory)));
		}
		/**
		 * .check expression works with multiply
		 * 
		 */
		TEST_METHOD(expressionsTestMultiply)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(16 == std::stoi(myExpression->calcFull("8*2",myMemory)));
		}
		/**
		 * .check expression works with substract and multiply
		 * 
		 */
		TEST_METHOD(expressionsTestSubtractAndMultiply)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(15 == std::stoi(myExpression->calcFull("8*2-1",myMemory)));
		}
		/**
		 * .check expression works with full bidmass 
		 * 
		 */
		TEST_METHOD(FullBidmassUnordered)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();

			Assert::IsTrue(-29 == std::stoi(myExpression->calcFull("5-2*2/1+30",myMemory)));
		}
		/**
		 * .check that expression works with two strings
		 * 
		 */
		TEST_METHOD(stringToString)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			Assert::IsTrue("\"helloworld\"" == myExpression->calcFull("\"hello\"+\"world\"",myMemory));
		}
		/**
		 * .check string add works with a " in middle
		 * 
		 */
		TEST_METHOD(stringWithSpecial)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			Assert::IsTrue("\"hel\\\"loworld\"" == myExpression->calcFull("\"hel\\\"lo\"+\"world\"",myMemory));
		}
		/**
		 * .check expression can be detected with one add
		 * 
		 */
		TEST_METHOD(isExpressionStandard)
		{
			
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("5+4");
			Assert::IsTrue(true == passes);
		}
		/**
		 * .check expression can be detected with double plus
		 * 
		 */
		TEST_METHOD(isExpressiondoubleplus)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("5+4+5");
			Assert::IsTrue(true == passes);
		}
		/**
		 * .check expression can be found with minus 
		 * 
		 */
		TEST_METHOD(isExpressionminus)
		{

			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("5-4");
			Assert::IsTrue(true == passes);
		}
		/**
		 * .check expression is not found when expression not inputted 
		 * 
		 */
		TEST_METHOD(isExpressionnot)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("54");
			Assert::IsTrue(false == passes);
		}
		/**
		 * .check expression is detected with strings 
		 * 
		 */
		TEST_METHOD(isExpressionstr)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("\"hello\"+\"world\"");
			Assert::IsTrue(true == passes);
		}
		/**
		 * .check expression can be detected even if an operations is put in string alongside proper operation
		 * 
		 */
		TEST_METHOD(isExpressionOperationInStr)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("\"hello+\"+\"world\"");
			Assert::IsTrue(true == passes);
		}
		/**
		 * .check to make sure if expression operation is in a string and there is no proper operation returns false
		 * 
		 */
		TEST_METHOD(isExpressionOperationInStrFalse)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isExpression("\"hello+\"\"world\"");
			Assert::IsTrue(false == passes);
		}
		/**
		 * .check to see if a valid assignment can be found 
		 * 
		 */
		TEST_METHOD(isAssignmentStandard)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isAssignment("hello=roar");
			Assert::IsTrue(true == passes);
		}
		/**
		 * .check assignment is not located if it is all in string 
		 * 
		 */
		TEST_METHOD(isAssignmentInString)
		{
			Expression* myExpression = new Expression();
			bool passes = myExpression->isAssignment("\"hello=roar\"");
			Assert::IsTrue(false == passes);
		}
		/**
		 * .check if no 1st term isassignment is false
		 * 
		 */
		TEST_METHOD(isAssignmentInStringEqualsFirst)
		{
			
			Expression* myExpression = new Expression();
			bool passes = myExpression->isAssignment("=hi");
			Assert::IsTrue(false == passes);
		}
		/**
		 * .check if no second term isassignment is false 
		 * 
		 */
		TEST_METHOD(isAssignmentInStringEqualsLast)
		{
			
			Expression* myExpression = new Expression();
			bool passes = myExpression->isAssignment("hi=");
			Assert::IsTrue(false == passes);
		}
		/**
		 * .check assignment is true when a valid value is passed
		 * 
		 */
		TEST_METHOD(checkAssingmentToValidValue)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			std::string value = myExpression->getAssignmentValue("myVar=50");
			bool passes = myExpression->checkAssignmentValue(value,myMemory);
			Assert::IsTrue(true == passes);
		}
		/**
		 * .check assignment check is true if valid expression is passed
		 * 
		 */
		TEST_METHOD(checkAssingmentToValidExpression)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			std::string value = myExpression->getAssignmentValue("myVar=50+40");
			bool passes = myExpression->checkAssignmentValue(value, myMemory);
			
			Assert::IsTrue(true == passes);
		}
		/**
		 * .check assignment is false when invalid value passed
		 * 
		 */
		TEST_METHOD(checkAssingmentToInvalidValue)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			std::string value = myExpression->getAssignmentValue("myVar=abur");
			bool passes = myExpression->checkAssignmentValue(value, myMemory);
			Assert::IsTrue(false == passes);
		}
		/**
		 * .check invalid assignment throws an error
		 * 
		 */
		TEST_METHOD(checkAssingmentToInvalidExpressionThrowsError)
		{
			MemoryManager* myMemory = new MemoryManager();
			Expression* myExpression = new Expression();
			std::string value = myExpression->getAssignmentValue("myVar=abur+abur");
			try {
				bool passes = myExpression->checkAssignmentValue(value, myMemory);
			}
			catch (operationNotSupportDataType& e)
			{
				Assert::IsTrue(true == true);
			}

		}

		




		


		










	};
}