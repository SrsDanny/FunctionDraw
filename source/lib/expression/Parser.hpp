#pragma once
#include <string>
#include "Expression.hpp"

namespace funcdraw { namespace expression
{
	class Parser
	{
	public:
		static Expression::ptr parse(const std::string& expressionStr);
	};
}}
