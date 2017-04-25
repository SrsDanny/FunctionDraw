#include "Parser.hpp"
#include <boost/spirit/include/qi.hpp>
#include <string>
#include "ExpressionGrammar.hpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

funcdraw::Expression::ptr funcdraw::Parser::parse(std::string expressionStr)
{
	Expression::ptr returnExpression;
	auto iter = expressionStr.begin();
	auto end = expressionStr.end();

	ExpressionGrammar<std::string::iterator> grammar;
	auto r = phrase_parse(iter, end, grammar, ascii::space, returnExpression);

	if(!r || iter != end)
	{
		throw 1;
	}

	return returnExpression;
}
