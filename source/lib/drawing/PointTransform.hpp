#pragma once
#include "GeometricTypes.hpp"

namespace funcdraw { namespace drawing
{
	class PointTransform
	{
		Transformation transformation;

		explicit PointTransform(boost::numeric::ublas::matrix<double> matrix)
			: transformation(matrix) {}

		explicit PointTransform(Transformation transformation)
			: transformation(transformation) {}

	public:
		PointTransform() : transformation(boost::numeric::ublas::identity_matrix<double>(3)) {}

		PointTransform(double minX, double maxX, double minY, double maxY)
		{
			auto xLen = maxX - minX;
			auto yLen = maxY - minY;

			transformation = Transformation(prod(
				Scaling(1 / xLen, 1 / yLen).matrix(),
				Translation(-minX, -minY).matrix()
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

		const Transformation& getTransformation() const
		{
			return transformation;
		}
	};
}}
