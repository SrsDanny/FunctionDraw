#include <gtest/gtest.h>
#include <memory>
#include "expression/ExpressionBuilder.hpp"
#include "expression/Expression.hpp"
#include "HelperFunctions.hpp"

using namespace funcdraw::expression;

namespace test
{
	TEST(ExpressionBuilderTest, MakeConstantWorks)
	{
		auto constantExpr = ExpressionBuilder::MakeConstant()(42);
		ASSERT_NE(nullptr, constantExpr);
		auto constant = dynamicCastAndAssertNotNull<Constant>(constantExpr);
		EXPECT_EQ(42, constant->getValue());
	}

	TEST(ExpressionBuilderTest, MakeVariableWorks)
	{
		auto variableExpr = ExpressionBuilder::MakeVariable()();
		ASSERT_NE(nullptr, variableExpr);
		dynamicCastAndAssertNotNull<Variable>(variableExpr);
	}

	TEST(ExpressionBuilderTest, MakeTwoOperandWorks)
	{
		ExpressionBuilder::MakeTwoOperand makeTwoOperand;
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
