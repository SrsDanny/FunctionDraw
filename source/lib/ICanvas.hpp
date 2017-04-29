#pragma once

namespace funcdraw
{
	class PointTransform;
	class Line;

	class ICanvas
	{
	public:
		virtual ~ICanvas() = default;
		virtual void drawLine(const Line& line, const PointTransform& figureTransform) = 0;
	};
}
