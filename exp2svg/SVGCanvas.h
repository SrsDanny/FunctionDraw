#pragma once
#include "drawing/ICanvas.h"
#include <vector>
#include "drawing/GeometricTypes.h"
#include <boost/format.hpp>
#include <fstream>

class SVGCanvas final: public funcdraw::drawing::ICanvas
{
	int width, heigth;
	std::stringstream svgOutput;

public:

	SVGCanvas(int width, int heigth)
		: width(width),
		  heigth(heigth)
	{
		svgOutput << R"(<?xml version="1.0" standalone="no"?>)";
		svgOutput << boost::format(R"(<svg height="%1%" width="%2%" xmlns="http://www.w3.org/2000/svg" version="1.1">)") % heigth % width;
	}

	void writeToFile(std::string filename)
	{
		std::ofstream(filename) << svgOutput.str() << "</svg>";
		svgOutput.clear();
	}

	void drawLines(const funcdraw::drawing::MultiLine& lines, const std::vector<funcdraw::drawing::Color>& colors) override;
	void drawLines(const funcdraw::drawing::MultiLine& lines, const funcdraw::drawing::Color& color) override;
	void drawText(const funcdraw::drawing::Point& point, const std::string& text, const funcdraw::drawing::Color& color) override;
	void drawLine(const funcdraw::drawing::Line& line, const funcdraw::drawing::Color& color) override;
};
