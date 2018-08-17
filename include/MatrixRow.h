#pragma once
#include "matrixElement.h"

namespace matrix
{
	template <typename T, T DEFAULT_VALUE>
	class MatrixRow
	{
	public:
		using matrix_type = Matrix<T, DEFAULT_VALUE>;
		using element_type = MatrixElement<T, DEFAULT_VALUE>;

		MatrixRow(matrix_type* m, size_t xx) :	parent_matrix(m), x(xx) {	}

		element_type operator[](std::size_t y)
		{
			return element_type(parent_matrix, x, y);
		}
	private:
		matrix_type* const parent_matrix;
		const size_t x;
	};
}