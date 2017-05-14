#pragma once
#include "expression/Expression.h"
#include "expression/Parser.h"
#include "ICanvas.h"
#include "Color.h"

namespace funcdraw { namespace drawing
{
	class Range;

	class Figure
	{
		const std::vector<Color> defaultColors;

		struct FunctionAndColor
		{
			std::function<double(double)> function;
			Color color;
		};

		std::list<FunctionAndColor> functions;
		std::vector<Color>::const_iterator currentColor = defaultColors.begin();

		Color nextColor()
		{
			++currentColor;
			if (currentColor == defaultColors.end())
				currentColor = defaultColors.begin();
			return *currentColor;
		}

	public:
		Figure(): defaultColors(Color::getDefaultColors())
		{
		}

		template<typename T>
		void addFunction(T val)
		{
			addFunction(val, nextColor());
		}

		template<typename Callable>
		void addFunction(const Callable& function, Color color)
		{
			functions.push_back(FunctionAndColor{
				function,
				color
			});
		}

		void addFunction(std::string expression, Color color)
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
