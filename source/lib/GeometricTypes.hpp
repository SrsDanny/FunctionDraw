#pragma once
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace funcdraw
{
	using Point = boost::geometry::model::d2::point_xy<double>;
	using Translation = boost::geometry::strategy::transform::translate_transformer<double, 2, 2>;
	using Scaling = boost::geometry::strategy::transform::scale_transformer<double, 2, 2>;
	using Transformation = boost::geometry::strategy::transform::ublas_transformer<double, 2, 2>;
}
