#include "expression/Parser.h"
#include <iostream>
#include <string>
#include "expression/ParseException.h"

using namespace std;
using namespace funcdraw::expression;

int main(int argc, char* argv[])
{
	string input, expressionStr;
	double x;
	Expression::ptr expr;

	for(;;)
	{
		cout << "Enter an expression (or 'exit'): \n";
		getline(cin, expressionStr);
		if (expressionStr == "exit") break;
		try
		{
			expr = Parser::parse(expressionStr);
		}
		catch (ParseException& e)
		{
			cerr << "Incorrect expression!\n";
			cerr << "Error at position: " << e.getIndex();
			cerr << "\n\"" << e.getContext() << "\"" << endl;
			continue;
		}

		for(;;)
		try
		{
			cout << "x = ";
			getline(cin, input);
			x = stod(input);
			break;
		}
		catch (invalid_argument&)
		{
			cerr << "Invalid argument!" << endl;
		}
		catch (out_of_range&)
		{
			cerr << "The given number is too big!" << endl;
		}

		cout << expressionStr << " = " << expr->evaluate(x) << endl;
	}
}
