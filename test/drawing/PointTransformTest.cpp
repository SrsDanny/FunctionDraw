#include <gtest/gtest.h>
#include "drawing/NormalizingTransformBuilder.h"
#include "drawing/GeometricTypes.h"
#include "HelperFunctions.h"

using namespace funcdraw::drawing;

namespace test
{
	TEST(PointTransformTest, NormalizeTest)
	{
		//        -3      2
		//     7  ---------
		//        |       |
		//        |       |
		//        |       |
		//     4  ---------

		auto transform = buildNormalizingTransform(-3, 2, 4, 7);
		Point p;

		// Corners
		boost::geometry::transform(Point(-3, 4), p, transform);
		expectPointNear(Point(0, 0), p);
		boost::geometry::transform(Point(2, 4), p, transform);
		expectPointNear(Point(1, 0), p);
		boost::geometry::transform(Point(2, 7), p, transform);
		expectPointNear(Point(1, 1), p);
		boost::geometry::transform(Point(-3, 7), p, transform);
		expectPointNear(Point(0, 1), p);

		// Center
		boost::geometry::transform(Point(-0.5, 5.5), p, transform);
		expectPointNear(Point(0.5, 0.5), p);

		// Random points
		boost::geometry::transform(Point(-2.95, 5.56), p, transform);
		expectPointNear(Point(0.01, 0.52), p);
		boost::geometry::transform(Point(1.12, 4.9), p, transform);
		expectPointNear(Point(0.824, 0.3), p);
		boost::geometry::transform(Point(0, 4.25), p, transform);
		expectPointNear(Point(0.6, 0.083333333333), p);
		boost::geometry::transform(Point(-1.94, 6.66), p, transform);
		expectPointNear(Point(0.212, 0.886666666666), p);
	}
}
