#include <gtest/gtest.h>
#include <memory>
#include "ExpressionBuilder.hpp"
#include "Expression.hpp"

template<typename T, char c>
struct ValueAndType
{
	using type = T;
	static constexpr char op = c;
};

template<typename T>
class ExpressionBuilderTest : public ::testing::Test
{
	
};

typedef ::testing::Types
<
	ValueAndType<funcdraw::Sum, '+'>,
	ValueAndType<funcdraw::Subtract, '-'>,
	ValueAndType<funcdraw::Multiply, '*'>,
	ValueAndType<funcdraw::Divide, '/'>
> MyTypes;

TYPED_TEST_CASE(ExpressionBuilderTest, MyTypes);
 
TEST(ExpressionBuilderTest, MakeConstantWorks)
{
	auto constantExpr = funcdraw::ExpressionBuilder::MakeConstant()(42);
	ASSERT_NE(nullptr, constantExpr);
	auto constant = std::dynamic_pointer_cast<funcdraw::Constant>(constantExpr);
	ASSERT_NE(nullptr, constant);
	EXPECT_EQ(42, constant->getValue());
}

TEST(ExpressionBuilderTest, MakeVariableWorks)
{
	auto variableExpr = funcdraw::ExpressionBuilder::MakeVariable()();
	ASSERT_NE(nullptr, variableExpr);
	auto variable = std::dynamic_pointer_cast<funcdraw::Variable>(variableExpr);
	ASSERT_NE(nullptr, variable);
}

TYPED_TEST(ExpressionBuilderTest, MakeTwoOperandWorks)
{
	funcdraw::ExpressionBuilder::MakeTwoOperand makeTwoOperand;

	auto twoOp = makeTwoOperand(nullptr, TypeParam::op, nullptr);
	ASSERT_NE(nullptr, twoOp);
	auto concreteOp = std::dynamic_pointer_cast<TypeParam::type>(twoOp);
	ASSERT_NE(nullptr, concreteOp);
}