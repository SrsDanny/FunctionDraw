#include <gtest/gtest.h>
#include <drawing/PointTransform.hpp>
#include <drawing/GeometricTypes.hpp>
#include "../HelperFunctions.hpp"

using namespace funcdraw::drawing;

namespace test
{
	TEST(PointTransformTest, ScaleTest)
	{
		Point p(2, 3);
		PointTransform transform;
		expectPointNear(p, transform(p)); // Default transformation is identity

		transform.appendScaling(2, 3);
		expectPointNear(Point(4, 9), transform(p));

		transform.appendScaling(3, 1.5);
		expectPointNear(Point(12, 13.5), transform(p));
	}

	TEST(PointTransformTest, TranslateTest)
	{
		Point p(6, 12);
		PointTransform transform;
		expectPointNear(p, transform(p)); // Default transformation is identity

		transform.appendTranslation(3.4, 8.5);
		expectPointNear(Point(9.4, 20.5), transform(p));

		transform.appendTranslation(-4, 100);
		expectPointNear(Point(5.4, 120.5), transform(p));
	}

	TEST(PointTransformTest, ScaleAndTranslateTest)
	{
		Point p(4, 7);
		PointTransform transform;
		expectPointNear(p, transform(p)); // Default transformation is identity

		transform.appendTranslation(3, 2);
		expectPointNear(Point(7, 9), transform(p));

		transform.appendScaling(2, 1.5);
		expectPointNear(Point(14, 13.5), transform(p));

		transform.appendTranslation(-10, -2.5);
		expectPointNear(Point(4, 11), transform(p));
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

		// Corners
		expectPointNear(Point(0, 0), transform(Point(-3, 4)));
		expectPointNear(Point(1, 0), transform(Point(2, 4)));
		expectPointNear(Point(1, 1), transform(Point(2, 7)));
		expectPointNear(Point(0, 1), transform(Point(-3, 7)));

		// Center
		expectPointNear(Point(0.5, 0.5), transform(Point(-0.5, 5.5)));

		// Random points
		expectPointNear(Point(0.01, 0.52), transform(Point(-2.95, 5.56)));
		expectPointNear(Point(0.824, 0.3), transform(Point(1.12, 4.9)));
		expectPointNear(Point(0.6, 0.083333333333), transform(Point(0, 4.25)));
		expectPointNear(Point(0.212, 0.886666666666), transform(Point(-1.94, 6.66)));
	}
}