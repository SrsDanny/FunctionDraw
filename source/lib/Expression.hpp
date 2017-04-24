#pragma once

namespace funcdraw
{
	class Expression
	{
	public:
		using ptr = std::shared_ptr<Expression>;
		
		virtual ~Expression() {}

		virtual double evaluate(double x) = 0;
	};

	class Constant final : public Expression
	{
		double number;

	public:
		explicit Constant(double number)
			: number(number)
		{}

		double evaluate(double x) override
		{
			return number;
		}
	};

	class Variable final : public Expression
	{
	public:
		double evaluate(double x) override 
		{
			return x;
		}
	};

	class TwoOperand : public Expression
	{
		virtual double doOperation(double lhs, double rhs) = 0;

	protected:
		ptr lhs;
		ptr rhs;

	public:
		TwoOperand(ptr expression, ptr expression1)
			: lhs(expression),
			  rhs(expression1)
		{}

		double evaluate(double x) override
		{
			return doOperation(lhs->evaluate(x), rhs->evaluate(x));
		}
	};

	class Sum final : public TwoOperand
	{
		using TwoOperand::TwoOperand;

		double doOperation(double lhs, double rhs) override
		{
			return lhs + rhs;
		}
	};

	class Subtract final : public TwoOperand
	{
		using TwoOperand::TwoOperand;

		double doOperation(double lhs, double rhs) override
		{
			return lhs - rhs;
		}
	};

	class Multiply final : public TwoOperand
	{
		using TwoOperand::TwoOperand;

		double doOperation(double lhs, double rhs) override
		{
			return lhs * rhs;
		}
	};

	class Divide final : public TwoOperand
	{
		using TwoOperand::TwoOperand;

		double doOperation(double lhs, double rhs) override
		{
			return lhs / rhs;
		}
	};
}
