#include "Figure.h"
#include "Range.h"
#include <boost/geometry.hpp>
#include "LineBuilder.h"
#include "NormalizingTransformBuilder.h"
#include "Axes.h"

using namespace std;
namespace bg = boost::geometry;

void funcdraw::drawing::Figure::draw(ICanvas& canvas, Range range) const
{
	MultiLine lines, normalizedLines;
	vector<Color> colors;

	for(auto& fun : functions)
	{
		lines.push_back(lineBuilder::build(fun.function, range));
		colors.push_back(fun.color);
	}

	auto figureSize = bg::return_envelope<Box>(lines);
	auto figureTransform = buildNormalizingTransform(
		figureSize.min_corner().x(),
		figureSize.max_corner().x(),
		figureSize.min_corner().y(),
		figureSize.max_corner().y());

	Point tfOrigo;
	bg::transform(Point(), tfOrigo, figureTransform);
	drawAxes(tfOrigo, canvas);

	bg::transform(lines, normalizedLines, figureTransform);
	canvas.drawLines(normalizedLines, colors);
}
