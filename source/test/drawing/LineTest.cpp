#include <gtest/gtest.h>
#include "drawing/LineBuilder.h"
#include <list>
#include <vector>
#include "expression/Parser.h"
#include "HelperFunctions.h"
#include "drawing/Range.h"

using namespace funcdraw::drawing;
using namespace funcdraw::expression;

namespace test
{
	template<typename Iterable, typename Function>
	void equals(const Iterable& iterable, const Line& line, const Function& func)
	{
		auto it = iterable.begin();
		auto end = iterable.end();
		auto itL = line.begin();
		auto endL = line.end();

		while (it != end && itL != endL)
		{
			EXPECT_EQ(*it, itL->x());
			EXPECT_EQ(func(*it), itL->y());
			++it;
			++itL;
		}
		EXPECT_EQ(endL, itL);
		EXPECT_EQ(end, it);
	}

	TEST(LineTest, FromSinAndVector)
	{
		std::vector<double> v{ 1, 2, 3, 4, 5 };
		auto mySin = static_cast<double(*)(double)>(sin);
		auto line = lineBuilder::build(mySin, v);
		equals(v, line, mySin);
	}

	TEST(LineTest, FromLambdaAndList)
	{
		std::list<double> l{ 1, 2, 3, 4, 5 };
		auto myLambda = [](double x) {return x * 2 + 1; };
		auto line = lineBuilder::build(myLambda, l);
		equals(l, line, myLambda);
	}

	TEST(LineTest, FromExpressionAndRange)
	{
		Range range(1, 10, 67);
		auto expr = Parser::parse("(12 + x) * 5");
		auto line = lineBuilder::build(*expr, range);
		equals(range, line, *expr);
	}
}
