#include "SVGCanvas.h"
#include <boost/format.hpp>
using funcdraw::drawing::Point;

void SVGCanvas::drawLines(const funcdraw::drawing::MultiLine& lines, const std::vector<funcdraw::drawing::Color>& colors)
{
	for(auto i = 0; i < lines.size(); ++i)
	{
		drawLine(lines[i], colors[i]);
	}
}

void SVGCanvas::drawLines(const funcdraw::drawing::MultiLine& lines, const funcdraw::drawing::Color& color)
{
	for (auto i = 0; i < lines.size(); ++i)
	{
		drawLine(lines[i], color);
	}
}

void SVGCanvas::drawLine(const funcdraw::drawing::Line& line, const funcdraw::drawing::Color& color)
{
	Point current(line[0].x() * width, (1 - line[0].y()) * heigth);
	for (auto j = 1; j < line.size(); ++j)
	{
		auto previous = current;
		current = Point(line[j].x() * width, (1 - line[j].y()) * heigth);

		svgOutput << boost::format(R"(<line x1="%1%" x2="%2%" y1="%3%" y2="%4%" stroke="%5%" stroke-width="2"/>)")
			% previous.x() % current.x()
			% previous.y() % current.y()
			% color;
	}
}
