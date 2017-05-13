#pragma once
#include <vector>

namespace funcdraw { namespace drawing
{
	class Range
	{
	public:
		class Iterator
		{
		public:
			using difference_type = int;
			using iterator_category = std::input_iterator_tag;
			using value_type = double;
			using reference = double&;
			using pointer = double*;

		private:
			const Range& range;
			int pos;

		public:
			Iterator(const Range& range, int pos)
				: range(range), pos(pos) {}

			double operator*() const
			{
				if (pos >= range.num)
					throw std::out_of_range("Iterator is outside the range of the Range object.");
				return pos * range.step + range.from;
			}

			Iterator& operator++()
			{
				++pos;
				return *this;
			}

			Iterator& operator--()
			{
				--pos;
				return *this;
			}

			bool operator==(const Iterator& other) const
			{
				return &range == &other.range && pos == other.pos;
			}

			bool operator!=(const Iterator& other) const
			{
				return &range != &other.range || pos != other.pos;
			}
		};

	private:
		double from, to;
		int num;
		double step;

	public:
		using value_type = double;
		using const_iterator = Iterator;

		Range(double from, double to, int num = 100)
			: from(from), to(to),
				num(num), step((to - from) / (num - 1))
		{
			if (from >= to)
				throw std::invalid_argument("'from' must be less than 'to'");
			if (num <= 0)
				throw std::invalid_argument("'num' can not be 0");
		}

		Iterator begin() const
		{
			return Iterator(*this, 0);
		}

		Iterator end() const
		{
			return Iterator(*this, num);
		}
	};
}}
