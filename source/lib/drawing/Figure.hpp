#pragma once
#include "PointTransform.hpp"
#include "expression/Expression.hpp"
#include "expression/Parser.hpp"
#include "expression/ParseException.hpp"
#include "ICanvas.hpp"
#include "Color.hpp"

namespace funcdraw { namespace drawing
{
	class Range;

	class Figure
	{
		struct FunctionAndColor
		{
			std::function<double(double)> function;
			Color color;
		};

		std::list<FunctionAndColor> functions;

	public:
		template<typename Callable>
		void addFunction(const Callable& function, Color color = Color::BLUE)
		{
			functions.push_back(FunctionAndColor{
				function,
				color
			});
		}
		
		void addFunction(std::string expression, Color color = Color::BLUE)
		{
			auto expr = expression::Parser::parse(expression);
			functions.push_back(FunctionAndColor{
				[expr](double x) { return (*expr)(x); },
				color
			});
		}

		void draw(ICanvas& canvas, Range range) const;
	};
}}
