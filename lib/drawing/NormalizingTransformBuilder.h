#pragma once
#include "GeometricTypes.h"

namespace funcdraw { namespace drawing
{
	inline Transformation buildNormalizingTransform(double minX, double maxX, double minY, double maxY)
	{
		auto xLen = maxX - minX;
		auto yLen = maxY - minY;

		return Transformation(prod(
			Scaling(1 / xLen, 1 / yLen).matrix(),
			Translation(-minX, -minY).matrix()
		));
	}
}}
