#pragma once
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include "Expression.h"
#include "ExpressionBuilder.h"

namespace funcdraw { namespace expression
{
	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;

	template <typename Iterator>
	struct ExpressionGrammar : qi::grammar<Iterator, Expression::ptr(), ascii::space_type>
	{
		qi::rule<Iterator, Expression::ptr(), ascii::space_type> expression,
		                                                         factor,
		                                                         product,
		                                                         parenthesized,
		                                                         number,
		                                                         variable;
		qi::rule<Iterator, char(), ascii::space_type> operatorSum,
		                                              operatorProd;

		boost::phoenix::function<ExpressionBuilder::MakeTwoOperand> makeTwoOperand;
		boost::phoenix::function<ExpressionBuilder::MakeConstant> makeConstant;
		boost::phoenix::function<ExpressionBuilder::MakeVariable> makeVariable;

		ExpressionGrammar() : ExpressionGrammar::base_type(expression)
		{
			using qi::_val;
			using qi::_1;
			using qi::_2;
			using ascii::char_;

			expression = product[_val = _1]
				>> *((operatorSum > product)[_val = makeTwoOperand(_val, _1, _2)]);

			operatorSum %= char_('+') | char_('-');

			product = factor[_val = _1]
				>> *((operatorProd > factor)[_val = makeTwoOperand(_val, _1, _2)]);

			operatorProd %= char_('*') | char_('/');

			factor %= number | variable | parenthesized;
			parenthesized %= '(' > expression > ')';
			number = qi::double_[_val = makeConstant(_1)];
			variable = char_('x')[_val = makeVariable()];
		}
	};
}}
