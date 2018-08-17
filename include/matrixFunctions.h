#pragma once
#include "matrixRow.h"

namespace matrix
{
	template<typename T, T DEFAULT_VALUE>
	void PrintMatrixElements(Matrix<T, DEFAULT_VALUE>& m)
	{
		for (const auto& c : m)
		{
			size_t x;
			size_t y;
			int v;
			std::tie(x, y, v) = c;
			std::cout << x << y << v << '\n';
		}
	}

	template<typename T, T DEFAULT_VALUE>
	void DrawMatrixPart(Matrix<T, DEFAULT_VALUE>& m, size_t x1, size_t y1, size_t x2, size_t y2)
	{
		for (size_t i = x1; i <= x2; ++i)
		{
			for (size_t j = y1; j <= y2; ++j)
			{
				std::cout << m[i][j] << ' ';
			}

			std::cout << '\n';
		}
	}
}