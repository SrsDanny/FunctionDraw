#include <Drawer.hpp>
#include <iostream>
#include "ExpressionGrammar.hpp"
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

using namespace std;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

int main(int argc, char* argv[])
{
	string s;
	double x;
	funcdraw::ExpressionGrammar<string::iterator> grammar;

	funcdraw::Expression::ptr expr;

	while (true) 
	{
		getline(cin, s);
		cin >> x;
		cin.ignore();
		phrase_parse(s.begin(), s.end(), grammar, ascii::space, expr);

		cout << "= " << expr->evaluate(x) << endl;
	}
}
