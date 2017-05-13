#pragma once
#include "GeometricTypes.hpp"

namespace funcdraw { namespace drawing
{
	namespace lineBuilder
	{
		template<typename Function, typename Iterable,
			typename = typename std::enable_if<
				std::is_convertible<decltype(std::declval<Function>()(std::declval<double>())), 
				double>::value>::type,
			typename = decltype(std::declval<Iterable>().begin()),
			typename = decltype(std::declval<Iterable>().end())
			>
		Line build(const Function& function, const Iterable& range)
		{
			Line line;
			for (auto x : range)
			{
				line.push_back({x, function(x)});
			}
			return line;
		}
	};
}}
