#include <gtest/gtest.h>
#include "ExpressionGrammar.hpp"

class ExpressionGrammarTest : public testing::Test
{
public:
	funcdraw::ExpressionGrammar<std::string::iterator> grammar;
};

TEST_F(ExpressionGrammarTest, SimpleSumTest)
{
	std::string exprStr = "1 + x";
}