#include "Axes.h"
#include "Color.h"
#include "../../exp2svg/SVGCanvas.h"

void funcdraw::drawing::drawAxes(const Point& origo, ICanvas& canvas)
{
	auto x = origo.x();
	auto y = origo.y();

	if (0 <= x && x <= 1)
	{
		Line line;
		line.push_back(Point(x, 0));
		line.push_back(Point(x, 1));
		canvas.drawLine(line, Color::BLACK);
		line.clear();

		for (auto i = 0; i < 10; ++i)
		{
			line.push_back(Point(x - 0.02, i * .1));
			line.push_back(Point(x + 0.02, i * .1));
			canvas.drawLine(line, Color::BLACK);
			line.clear();
		}
	}

	if(0 <= y && y <= 1)
	{
		Line line;
		line.push_back(Point(0, y));
		line.push_back(Point(1, y));
		canvas.drawLine(line, Color::BLACK);
		line.clear();

		for(auto i = 0; i < 10; ++i)
		{
			line.push_back(Point(i * .1, y - 0.02));
			line.push_back(Point(i * .1, y + 0.02));
			canvas.drawLine(line, Color::BLACK);
			line.clear();
		}
	}
}
