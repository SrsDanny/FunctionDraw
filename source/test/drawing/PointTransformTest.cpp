#include <gtest/gtest.h>
#include <drawing/PointTransform.hpp>
#include <drawing/GeometricTypes.hpp>

using namespace funcdraw::drawing;

namespace test
{
	void expectEqual(const Point& lhs, const Point& rhs) 
	{
		auto eps = 1e-10;
		EXPECT_NEAR(lhs.x(), rhs.x(), eps);
		EXPECT_NEAR(lhs.y(), rhs.y(), eps);
	}

	TEST(PointTransformTest, ScaleTest)
	{
		Point p(2, 3);
		PointTransform transform;
		expectEqual(p, transform(p)); // Default transformation is identity

		transform.appendScaling(2, 3);
		expectEqual(Point(4, 9), transform(p));

		transform.appendScaling(3, 1.5);
		expectEqual(Point(12, 13.5), transform(p));
	}

	TEST(PointTransformTest, TranslateTest)
	{
		Point p(6, 12);
		PointTransform transform;
		expectEqual(p, transform(p)); // Default transformation is identity

		transform.appendTranslation(3.4, 8.5);
		expectEqual(Point(9.4, 20.5), transform(p));

		transform.appendTranslation(-4, 100);
		expectEqual(Point(5.4, 120.5), transform(p));
	}

	TEST(PointTransformTest, ScaleAndTranslateTest)
	{
		Point p(4, 7);
		PointTransform transform;
		expectEqual(p, transform(p)); // Default transformation is identity

		transform.appendTranslation(3, 2);
		expectEqual(Point(7, 9), transform(p));

		transform.appendScaling(2, 1.5);
		expectEqual(Point(14, 13.5), transform(p));

		transform.appendTranslation(-10, -2.5);
		expectEqual(Point(4, 11), transform(p));
	}

	TEST(PointTransformTest, NormalizeTest)
	{
		//        -3      2
		//     7  ---------
		//        |       |
		//        |       |
		//        |       |
		//     4  ---------

		PointTransform transform(-3, 2, 4, 7);
		expectEqual(Point(-1, -1), transform(Point(-3, 4)));
		expectEqual(Point(1, -1), transform(Point(2, 4)));
		expectEqual(Point(1, 1), transform(Point(2, 7)));
		expectEqual(Point(-1, 1), transform(Point(-3, 7)));
	}
}