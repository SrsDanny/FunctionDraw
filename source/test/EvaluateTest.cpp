#include <gtest/gtest.h>
#include "Expression.hpp"
#include "Parser.hpp"

using namespace funcdraw;

namespace test
{
	class EvaluateTest : public ::testing::TestWithParam<std::tuple<std::string, double, double>>
	{
	public:
		std::string getExpressionStr() const { return std::get<0>(GetParam()); }
		double getX() const { return std::get<1>(GetParam()); }
		double getResult() const { return std::get<2>(GetParam()); }
	};

	TEST_P(EvaluateTest, EvaluateExpressions)
	{
		auto expr = Parser::parse(getExpressionStr());
		ASSERT_NE(nullptr, expr);
		EXPECT_NEAR(getResult(), expr->evaluate(getX()), std::numeric_limits<double>::epsilon());
	}

	INSTANTIATE_TEST_CASE_P(EvaluateExpressions,
		EvaluateTest,
		testing::Values(
			std::make_tuple("1", .0, 1.),
			std::make_tuple("1 + 4", .0, 5.),
			std::make_tuple("1 + x", 3., 4.),
			std::make_tuple("1.5 * 2", .0, 3.),
			std::make_tuple("2.9 * (x - 14.4)", 1.8, -36.54),
			std::make_tuple("(x + 7) * (x - 7)", 3.14, -39.1404)
		));
}