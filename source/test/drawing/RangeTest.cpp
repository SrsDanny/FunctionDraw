#include <gtest/gtest.h>
#include <drawing/Range.hpp>
#include <gmock/gmock.h>

using namespace funcdraw::drawing;
using std::get;
using ::testing::AllOf;
using ::testing::Ge;
using ::testing::Le;
using ::testing::Each;
using ::testing::Values;
using std::make_tuple;

namespace test
{
	class RangeLengthTest : public ::testing::TestWithParam<int>{};

	TEST_P(RangeLengthTest, TestRangeLength)
	{
		Range r(0, 100, GetParam());
		EXPECT_EQ(GetParam(), std::distance(r.begin(), r.end()));
	}

	INSTANTIATE_TEST_CASE_P(RangeLengthTest,
		RangeLengthTest,
		Values(1, 2, 12, 23, 56, 99, 1024, 1337, 8008));

	class RangeBoundsTest : public ::testing::TestWithParam<std::tuple<double, double, int>>{};

	TEST_P(RangeBoundsTest, TestBoundsEqual)
	{
		auto& t = GetParam();
		auto first = get<0>(t);
		auto last = get<1>(t);
		auto num = get<2>(t);

		Range range(first, last, num);
		EXPECT_THAT(range, Each(AllOf(Ge(first), Le(last))));
		EXPECT_DOUBLE_EQ(first, *range.begin());
		EXPECT_DOUBLE_EQ(last, *--range.end());
	}

	INSTANTIATE_TEST_CASE_P(RangeBoundsTest,
		RangeBoundsTest,
		Values(make_tuple(1.,2.,3.),
			make_tuple(-3.5, 8.12, 54),
			make_tuple(43.5, 65.12, 76),
			make_tuple(54., 76., 3)));

	TEST(RangeTest, TestInvalidRange)
	{
		EXPECT_THROW(Range(31, 1, 100), std::invalid_argument);
		EXPECT_THROW(Range(22, 22, 100), std::invalid_argument);
		EXPECT_THROW(Range(-99, -65, 0), std::invalid_argument);
		EXPECT_THROW(Range(-42, -69, -58), std::invalid_argument);
	}
}