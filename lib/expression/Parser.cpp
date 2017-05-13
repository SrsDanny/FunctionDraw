#include "Parser.h"
#include <boost/spirit/include/qi.hpp>
#include <string>
#include "ExpressionGrammar.h"
#include "ParseException.h"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

namespace funcdraw { namespace expression{
	Expression::ptr Parser::parse(const std::string& expressionStr)
	{
		Expression::ptr returnExpression;
		auto iter = expressionStr.begin();
		auto end = expressionStr.end();

		ExpressionGrammar<std::string::const_iterator> grammar;

		bool result = true;
		try
		{
			result = phrase_parse(iter, end, grammar, ascii::space, returnExpression);
		}
		catch (qi::expectation_failure<std::string::const_iterator>& e)
		{
			throw ParseException(e.first, e.last, e.first - expressionStr.begin());
		}

		if(!result || iter != end)
		{
			throw ParseException(iter, end, iter - expressionStr.begin());
		}

		return returnExpression;
	}
}}
