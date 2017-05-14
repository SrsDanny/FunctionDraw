#include <string>
#include <iostream>
#include "drawing/Figure.h"
#include "SVGCanvas.h"
#include "drawing/Range.h"
#include "expression/ParseException.h"
#include <boost/format.hpp>
using funcdraw::drawing::Figure;
using funcdraw::drawing::Range;

int readNumber(const std::string& message, int defaultNumber)
{
	std::string input;
	std::cout << boost::format("%1% (default is %2%): ") % message % defaultNumber;

	for(;;)
	{
		try
		{
			getline(std::cin, input);
			if (input.empty())
				return defaultNumber;
			return stoi(input);
		}
		catch(std::invalid_argument&)
		{
			std::cout << "Invalid argument. Try again!" << std::endl;
		}
	}
}

int main(int argc, char* argv[])
{
	std::string input;
	Figure figure;

	std::cout << "Enter expression (eg. (x+2)*x), or empty line to stop" << std::endl;

	getline(std::cin, input);
	while(!input.empty())
	{
		try 
		{
			figure.addFunction(input);
		}
		catch(funcdraw::expression::ParseException& e)
		{
			std::cerr << boost::format("Invalid expression. Error at position (%1%): %2%") % e.getIndex() % e.getContext() << std::endl;
		}
		getline(std::cin, input);
	}

	auto x_min = readNumber("Enter range start (x_min)", -10);
	auto x_max = readNumber("Enter range start (x_min)", 10);
	auto width = readNumber("Enter picture width", 320);
	auto heigth = readNumber("Enter picture width", 200);
	
	std::cout << "Enter filename: ";
	std::cin >> input;

	SVGCanvas canvas(width, heigth);
	figure.draw(canvas, Range(x_min, x_max));
	canvas.writeToFile(input);
	return 0;
}
