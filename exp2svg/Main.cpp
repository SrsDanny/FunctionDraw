#include <string>
#include <iostream>
#include "drawing/Figure.h"
#include "SVGCanvas.h"
#include "drawing/Range.h"
using funcdraw::drawing::Figure;
using funcdraw::drawing::Range;

int main(int argc, char* argv[])
{
	std::string input;
	Figure figure;

	std::cout << "Enter expression (or empty line to stop)" << std::endl;

	getline(std::cin, input);
	while(!input.empty())
	{
		figure.addFunction(input);
		getline(std::cin, input);
	}
	
	std::cout << "Enter filename: ";
	std::cin >> input;

	SVGCanvas canvas(320, 200);
	figure.draw(canvas, Range(-10, 10));
	canvas.writeToFile(input);
	return 0;
}
