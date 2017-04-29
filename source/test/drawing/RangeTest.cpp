#include <gtest/gtest.h>
#include <drawing/Range.hpp>

using namespace funcdraw::drawing;

namespace test
{
	class RangeTest : public ::testing::TestWithParam<int>{};

	TEST_P(RangeTest, TestRangeLength)
	{
		Range r(0, 100, GetParam());
		EXPECT_EQ(GetParam(), std::distance(r.begin(), r.end()));
	}

	TEST(RangeTest, TestInvalidRange)
	{
		EXPECT_THROW(Range(31, 1, 100), std::invalid_argument);
		EXPECT_THROW(Range(22, 22, 100), std::invalid_argument);
		EXPECT_THROW(Range(-99, -65, 0), std::invalid_argument);
		EXPECT_THROW(Range(-42, -69, -58), std::invalid_argument);
	}

	INSTANTIATE_TEST_CASE_P(RangeLengthTest,
		RangeTest,
		testing::Values(1, 2, 12, 23, 56, 99, 1024, 1337, 8008));
}