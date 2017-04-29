#pragma once
#include "Line.hpp"
#include "GeometricTypes.hpp"

namespace funcdraw
{
	class PointTransform
	{
		Transformation transformation;

		explicit PointTransform(boost::numeric::ublas::matrix<double> matrix)
			: transformation(matrix) {}

		explicit PointTransform(Transformation transformation)
			: transformation(transformation) {}

	public:
		PointTransform() : transformation(boost::numeric::ublas::identity_matrix<double>(2)) {}

		PointTransform(double minX, double maxX, double minY, double maxY)
		{
			auto xLen = maxX - minX;
			auto yLen = maxY - minY;
			auto xMid = minX + xLen / 2;
			auto yMid = minY + yLen / 2;

			transformation = Transformation(prod(
				Scaling(xLen / 2, yLen / 2).matrix(),
				Translation(-xMid, -yMid).matrix()
			));
		}

		void appendScaling(double scaleX, double scaleY)
		{
			transformation = Transformation(
				prod(Scaling(scaleX, scaleY).matrix(), 
					transformation.matrix()
				));
		}

		void appendTranslation(double translateX, double translateY)
		{
			transformation = Transformation(
				prod(Translation(translateX, translateY).matrix(),
					transformation.matrix()
				));
		}

		Point operator()(Point point) const
		{
			Point temp;
			boost::geometry::transform(point, temp, transformation);
			return temp;
		}
	};
}
