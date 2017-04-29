#include <gtest/gtest.h>
#include <expression/Expression.hpp>

using namespace funcdraw::expression;

namespace test
{
	using NumberPairs = std::pair<double, double>;

	class ExpressionTest : public ::testing::TestWithParam<NumberPairs>
	{
	public:
		Expression::ptr c1_, c2_;

		ExpressionTest()
			: c1_(std::make_shared<Constant>(GetParam().first)),
			  c2_(std::make_shared<Constant>(GetParam().second))
		{}
	};

	TEST_P(ExpressionTest, VariableTest)
	{
		Variable v;
		EXPECT_EQ(GetParam().first, v.evaluate(GetParam().first));
	}

	TEST_P(ExpressionTest, ConstantTest)
	{
		Constant c(GetParam().first);
		EXPECT_EQ(GetParam().first, c.getValue());
		EXPECT_EQ(GetParam().first, c.evaluate(GetParam().second));
	}

	TEST_P(ExpressionTest, SumTest)
	{
		Sum s(c1_, c2_);
		EXPECT_EQ(GetParam().first + GetParam().second,
			s.evaluate(GetParam().first));
	}

	TEST_P(ExpressionTest, SubtractTest)
	{
		Subtract s(c1_, c2_);
		EXPECT_EQ(GetParam().first - GetParam().second,
			s.evaluate(GetParam().first));
	}

	TEST_P(ExpressionTest, MultiplyTest)
	{
		Multiply s(c1_, c2_);
		EXPECT_EQ(GetParam().first * GetParam().second,
			s.evaluate(GetParam().first));
	}

	TEST_P(ExpressionTest, DivideTest)
	{
		Divide s(c1_, c2_);
		EXPECT_EQ(GetParam().first / GetParam().second,
			s.evaluate(GetParam().first));
	}

	INSTANTIATE_TEST_CASE_P(ExpressionTests,
		ExpressionTest,
		testing::ValuesIn(std::vector<NumberPairs>{
				{42, 6},
				{69, -1773},
				{3.14, 2.71},
				{-1.25, -5.78}
				}));
				
}
