#include "Figure.hpp"
#include "Range.hpp"
#include <boost/geometry.hpp>
#include "LineBuilder.hpp"

using namespace std;
namespace bg = boost::geometry;

void funcdraw::drawing::Figure::draw(ICanvas& canvas, Range range) const
{
	MultiLine lines;
	vector<Color> colors;

	for(auto& fun : functions)
	{
		lines.push_back(lineBuilder::build(fun.function, range));
		colors.push_back(fun.color);
	}

	auto figureSize = bg::return_envelope<Box>(lines);
	PointTransform figureTransform(
		figureSize.min_corner().x(),
		figureSize.max_corner().x(),
		figureSize.min_corner().y(),
		figureSize.max_corner().y());

	canvas.drawLines(lines, colors, figureTransform);
}
