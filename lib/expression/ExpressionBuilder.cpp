#include "ExpressionBuilder.h"
#include <stdexcept>

funcdraw::expression::Expression::ptr funcdraw::expression::expressionBuilder::makeTwoOperand(Expression::ptr lhs, char op, Expression::ptr rhs)
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
		throw std::invalid_argument("Invalid operator");
	}
}

funcdraw::expression::Expression::ptr funcdraw::expression::expressionBuilder::makeConstant(double x)
{
	return std::make_shared<Constant>(x);
}

funcdraw::expression::Expression::ptr funcdraw::expression::expressionBuilder::makeVariable(bool negative)
{
	if (negative)
		return makeTwoOperand(makeConstant(-1.), '*', std::make_shared<Variable>());

	return std::make_shared<Variable>();
}
