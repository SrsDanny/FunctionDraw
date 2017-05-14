#pragma once
#include "Expression.h"
#include <exception>
#include <boost/optional.hpp>

namespace funcdraw { namespace expression
{
	namespace expressionBuilder
	{
		Expression::ptr makeTwoOperand(Expression::ptr lhs, char op, Expression::ptr rhs);

		Expression::ptr makeConstant(double x);

		Expression::ptr makeVariable(bool negative = false);
	}
}}
