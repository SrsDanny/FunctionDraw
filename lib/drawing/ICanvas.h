#pragma once
#include "Color.h"
#include "GeometricTypes.h"

namespace funcdraw { namespace drawing
{
	class PointTransform;

	class ICanvas
	{
	public:
		virtual ~ICanvas() = default;
		virtual void drawLines(const MultiLine& lines, const std::vector<Color>& colors) = 0;
		virtual void drawLines(const MultiLine& lines, const Color& colors) = 0;
		virtual void drawLine(const Line& line, const Color& color) = 0;
	};
}}
