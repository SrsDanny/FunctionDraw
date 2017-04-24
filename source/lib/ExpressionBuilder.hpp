#pragma once
#include "Expression.hpp"
#include <boost/spirit/include/phoenix.hpp>

namespace funcdraw
{
	namespace ExpressionBuilder
	{
		struct MakeTwoOperand
		{
			Expression::ptr operator()(Expression::ptr lhs, char op, Expression::ptr rhs) const
			{
				switch (op)
				{
				case '+':
					return std::make_shared<Sum>(lhs, rhs);
				case '-':
					return std::make_shared<Subtract>(lhs, rhs);
				case '/':
					return std::make_shared<Divide>(lhs, rhs);
				case '*':
					return std::make_shared<Multiply>(lhs, rhs);
				default:
					throw 1;
				}
			}
		};

		struct MakeConstant
		{
			Expression::ptr operator()(double x) const
			{
				return std::make_shared<Constant>(x);
			}
		};

		struct MakeVariable
		{
			Expression::ptr operator()() const
			{
				return std::make_shared<Variable>();
			}
		};
	}
}
