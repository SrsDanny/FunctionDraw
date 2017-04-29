#pragma once
#include <utility>
#include <vector>
#include "Color.hpp"
#include "GeometricTypes.hpp"
#include "Range.hpp"

namespace funcdraw
{
	class Line
	{
		std::vector<Point> points;
		Color c;

	public:
		template<typename Function, 
			typename = typename std::enable_if<
				std::is_convertible<decltype(std::declval<Function>()(std::declval<double>())), 
				double>::value>::type>
		explicit Line(const Function& function, Range range, Color c = Color::BLUE);
	};
}
