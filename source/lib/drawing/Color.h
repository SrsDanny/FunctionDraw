#pragma once

namespace funcdraw { namespace drawing
{
	struct Color
	{
		unsigned char r = 0, 
					  g = 0, 
					  b = 0;
		
		Color() = default;

		Color(unsigned char r, unsigned char g, unsigned char b)
			: r(r), g(g), b(b) {}

		static const Color BLACK;
		static const Color BLUE;
		static const Color RED;
		static const Color GREEN;
		static const Color YELLOW;
		static const Color PURPLE;
		static const Color CYAN;


		bool operator==(const Color& rhs) const
		{
			return r == rhs.r
				&& g == rhs.g
				&& b == rhs.b;
		}

		bool operator!=(const Color& rhs) const { return !(*this == rhs); }
	};
}}
