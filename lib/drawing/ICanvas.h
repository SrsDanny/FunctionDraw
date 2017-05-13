#pragma once
#include "Color.h"

namespace funcdraw { namespace drawing
{
	class PointTransform;
	using MultiLine = boost::geometry::model::multi_linestring<boost::geometry::model::linestring<boost::geometry::model::d2::point_xy<double>>>;

	class ICanvas
	{
	public:
		virtual ~ICanvas() = default;
		virtual void drawLines(const MultiLine& lines, std::vector<Color>, const PointTransform& figureTransform) = 0;
	};
}}
