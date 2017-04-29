#include "Line.hpp"
#include "Range.hpp"

namespace funcdraw
{
	template <typename Function, typename>
	Line::Line(const Function& function, Range range, Color c) : c(c)
	{
		for(auto x : range)
		{
			points.push_back({ x, function(x) });
		}
	}
}
