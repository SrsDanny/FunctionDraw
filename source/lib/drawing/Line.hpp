#pragma once
#include <utility>
#include <vector>
#include "Color.hpp"
#include "GeometricTypes.hpp"
#include "Range.hpp"

namespace funcdraw { namespace drawing
{
	class Line
	{
		using ContainerType = std::vector<Point>;
		ContainerType points;
		Color c;

	public:
		template<typename Function, typename Iterable,
			typename = typename std::enable_if<
				std::is_convertible<decltype(std::declval<Function>()(std::declval<double>())), 
				double>::value>::type,
			typename = std::void_t<
				decltype(std::declval<Iterable>().begin()),
				decltype(std::declval<Iterable>().end())
			>>
		Line(const Function& function, const Iterable& range, Color c = Color::BLUE)
			: c(c)
		{
			for (auto x : range)
			{
				points.push_back({x, function(x)});
			}
		}

		Line(Line&& other) noexcept
			: points(std::move(other.points)),
			  c(other.c)
		{}

		ContainerType::const_iterator begin() const { return points.cbegin(); }
		ContainerType::const_iterator end() const { return points.cend(); }
	};
}}
