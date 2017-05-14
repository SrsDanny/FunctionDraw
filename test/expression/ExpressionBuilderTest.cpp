#include <gtest/gtest.h>
#include <memory>
#include "expression/ExpressionBuilder.h"
#include "expression/Expression.h"
#include "HelperFunctions.h"

using namespace funcdraw::expression;
using namespace expressionBuilder;

namespace test
{
	TEST(ExpressionBuilderTest, MakeConstantWorks)
	{
		auto constantExpr = makeConstant(42);
		ASSERT_NE(nullptr, constantExpr);
		auto constant = dynamicCastAndAssertNotNull<Constant>(constantExpr);
		EXPECT_EQ(42, constant->getValue());
	}

	TEST(ExpressionBuilderTest, MakeVariableWorks)
	{
		auto variableExpr = makeVariable();
		ASSERT_NE(nullptr, variableExpr);
		dynamicCastAndAssertNotNull<Variable>(variableExpr);
	}

	TEST(ExpressionBuilderTest, MakeTwoOperandWorks)
	{
		{
			auto twoOp = makeTwoOperand(nullptr, '+', nullptr);
			dynamicCastAndAssertNotNull<Sum>(twoOp);
		}
		{
			auto twoOp = makeTwoOperand(nullptr, '-', nullptr);
			dynamicCastAndAssertNotNull<Subtract>(twoOp);
		}
		{
			auto twoOp = makeTwoOperand(nullptr, '*', nullptr);
			dynamicCastAndAssertNotNull<Multiply>(twoOp);
		}
		{
			auto twoOp = makeTwoOperand(nullptr, '/', nullptr);
			dynamicCastAndAssertNotNull<Divide>(twoOp);
		}
	}
}
