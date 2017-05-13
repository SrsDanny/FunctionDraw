#include <gtest/gtest.h>
#include <expression/Parser.hpp>
#include "expression/Parser.hpp"
#include "HelperFunctions.hpp"
#include <expression/ParseException.hpp>
#include "expression/ParseException.hpp"

using namespace funcdraw::expression;

namespace test
{
	class ParserTest : public ::testing::TestWithParam<std::string>{};

	TEST(ParserTest, TestSimpleSum)
	{
		std::string expressionStr = "1 + x";
		auto expression = Parser::parse(expressionStr);
		auto sum = dynamicCastAndAssertNotNull<Sum>(expression);
		dynamicCastAndAssertNotNull<Constant>(sum->getLhs());
		dynamicCastAndAssertNotNull<Variable>(sum->getRhs());
	}

	TEST(ParserTest, TestComplexExpression)
	{
		std::string expressionStr = "(1 + x) * 2 + 3 / x";
		auto expression = Parser::parse(expressionStr);
		
		auto topSum = dynamicCastAndAssertNotNull<Sum>(expression); // (1 + x) * 2 + 3 / x
		auto multiply = dynamicCastAndAssertNotNull<Multiply>(topSum->getLhs()); // (1 + x) * 2
		auto divide = dynamicCastAndAssertNotNull<Divide>(topSum->getRhs()); // 3 / x
		auto leftSum = dynamicCastAndAssertNotNull<Sum>(multiply->getLhs()); // 1 + x
		
		dynamicCastAndAssertNotNull<Constant>(multiply->getRhs()); // 2
		dynamicCastAndAssertNotNull<Constant>(leftSum->getLhs()); // 1
		dynamicCastAndAssertNotNull<Variable>(leftSum->getRhs()); // x
		dynamicCastAndAssertNotNull<Constant>(divide->getLhs()); // 3
		dynamicCastAndAssertNotNull<Variable>(divide->getRhs()); // x
	}

	TEST(ParserTest, TestBalancedParentheses)
	{
		std::string expressionStr = "((((((((42))))))))";
		auto expression = Parser::parse(expressionStr);
		dynamicCastAndAssertNotNull<Constant>(expression);
	}

	TEST_P(ParserTest, TestInvalidExpression)
	{
		EXPECT_THROW(Parser::parse(GetParam()), ParseException);
	}

	INSTANTIATE_TEST_CASE_P(InvalidExpressionsTest,
		ParserTest,
		testing::Values(
			"foo", 
			"bar",
			"42 + bar",
			"42 + (bar - 12)",
			"42 + - 1337",
			"((((42)))",
			"(((42))))",
			"42 + (((42 - 69))",
			"42 * 3 -"
		));
}
