#pragma once
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>

namespace matrix
{	
	template <typename T, T DEFAULT_VALUE> class MatrixRow;

	template <typename T, T DEFAULT_VALUE> class Matrix
	{
	public:
		using size_type		= size_t;		
		using row_type		= MatrixRow<T, DEFAULT_VALUE>;
		
		using iterated_type	= std::tuple<size_t, size_t, T>;
		using iterator		= typename std::vector<iterated_type>::iterator;
		
		size_type size() const noexcept { return elements.size(); }
		iterator begin() noexcept { return elements.begin(); }
		iterator end() noexcept { return elements.end(); }

		row_type operator[](std::size_t row_num) noexcept
		{
			return row_type(this, row_num);
		}

		T GetValue(size_t x, size_t y) 
		{
			auto iter = FindElement(x, y);

			return (elements.end() == iter) 
				? DEFAULT_VALUE 
				: std::get<2>(*iter);
		}

		void SetValue(size_t x, size_t y, T val)
		{
			auto elem = FindElement(x, y);

			if (elements.end() == elem)
			{
				if (DEFAULT_VALUE != val)
				{
					elements.emplace_back(x, y, val);
				}
			}
			else
			{
				if (DEFAULT_VALUE == val)
				{
					elements.erase(elem);
				}
				else
				{
					std::get<2>(*elem) = val;
				}
			}
		}
	private:
		iterator FindElement(size_t x, size_t y) noexcept
		{
			return find_if(
				elements.begin(), elements.end(),
				[x, y](iterated_type& e)
			{
				return (x == std::get<0>(e)) && (y == std::get<1>(e));
			});
		}

		std::vector<iterated_type> elements;
	};
}
