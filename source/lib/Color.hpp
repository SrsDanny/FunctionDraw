#pragma once

namespace funcdraw
{
	struct Color
	{
		unsigned char r, g, b;

		Color(unsigned char r, unsigned char g, unsigned char b)
			: r(r), g(g), b(b) {}

		static const Color BLACK;
		static const Color BLUE;
		static const Color RED;
		static const Color GREEN;
		static const Color YELLOW;
		static const Color PURPLE;
		static const Color CYAN;
	};
}
