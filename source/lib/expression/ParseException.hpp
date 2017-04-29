#pragma once
#include <exception>
#include <string>

namespace funcdraw { namespace expression
{
	class ParseException : std::exception
	{
		static std::string name;
		static size_t CONTEXT_LENGTH;

		const std::string context;
		const size_t index;

		template<typename Iterator>
		static std::string constructContext(Iterator begin, Iterator end)
		{
			if (end - begin < CONTEXT_LENGTH)
				return std::string(begin, end);
			return std::string(begin, begin + CONTEXT_LENGTH);
		}

	public:
		template<typename Iterator>
		ParseException(Iterator begin, Iterator end, size_t index)
			: context(constructContext(begin, end)),
			  index(index) {}

		char const* what() const override { return name.c_str(); }

		std::string getContext() const { return context; }
		size_t getIndex() const { return index; }
	};
}}
