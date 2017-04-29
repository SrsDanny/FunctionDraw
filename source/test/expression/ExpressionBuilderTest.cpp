#include <gtest/gtest.h>
#include <memory>
#include <expression/ExpressionBuilder.hpp>
#include <expression/Expression.hpp>
#include "HelperFunctions.hpp"

using namespace funcdraw::expression;

namespace test
{
	template<typename T, char c>
	struct ValueAndType
	{
		using type = T;
		static constexpr char op = c;
	};

	template<typename T>
	class ExpressionBuilderTest : public testing::Test{};

	typedef testing::Types
	<
		ValueAndType<Sum, '+'>,
		ValueAndType<Subtract, '-'>,
		ValueAndType<Multiply, '*'>,
		ValueAndType<Divide, '/'>
	> MyTypes;

	TYPED_TEST_CASE(ExpressionBuilderTest, MyTypes);
 
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

	TYPED_TEST(ExpressionBuilderTest, MakeTwoOperandWorks)
	{
		ExpressionBuilder::MakeTwoOperand makeTwoOperand;

		auto twoOp = makeTwoOperand(nullptr, TypeParam::op, nullptr);
		ASSERT_NE(nullptr, twoOp);
		dynamicCastAndAssertNotNull<TypeParam::type>(twoOp);
	}
}
