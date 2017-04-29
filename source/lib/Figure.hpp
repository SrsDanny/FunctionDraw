#pragma once
#include "PointTransform.hpp"

namespace funcdraw
{
	class Figure
	{
		PointTransform transform;
		std::list<Line> lines;

	public:
		void addFunction(std::string expression)
		{
			
		}
	};
}
