#pragma once
#include "PointTransform.hpp"
#include "Line.hpp"
#include <expression/Expression.hpp>
#include <expression/Parser.hpp>
#include "expression/ParseException.hpp"
#include "ICanvas.hpp"

namespace funcdraw { namespace drawing
{
	class Figure
	{
		struct Function
		{
			std::function<double(double)> function;
			Color c;
		};

		std::list<Function> functions;

	public:
		template<typename Callable>
		void addFunction(const Callable& function, Color color = Color::BLUE)
		{
			functions.push_back(Function{
				function,
				color
			});
		}
		
		void addFunction(std::string expression, Color color = Color::BLUE)
		{
			auto expr = expression::Parser::parse(expression);
			functions.push_back(Function{
				[expr](double x) { return (*expr)(x); },
				color
			});
		}

		void draw(ICanvas& canvas, Range range) const;
	};
}}
