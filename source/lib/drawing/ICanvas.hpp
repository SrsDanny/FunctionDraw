#pragma once

namespace funcdraw { namespace drawing
{
	class PointTransform;
	class Line;

	class ICanvas
	{
	public:
		virtual ~ICanvas() = default;
		virtual void drawLine(const Line& line, const PointTransform& figureTransform) = 0;
	};
}}
