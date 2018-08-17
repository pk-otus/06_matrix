#pragma once
#include <iostream>
#include "../include/matrix.h"

namespace matrix
{
	template <typename T, T DEFAULT_VALUE>
	class MatrixElement
	{
	public:
		using matrix_type = Matrix<T, DEFAULT_VALUE>;

		MatrixElement(matrix_type* m, size_t xx, size_t yy) :
			parent_matrix(m), x(xx), y(yy) { }
		
		MatrixElement& operator=(const T& val) //
		{
			parent_matrix->SetValue(x, y, val);
			return *this;
		}

		bool operator==(const T& val) {	return parent_matrix->GetValue(x, y) == val; }

		friend std::ostream& operator<<(std::ostream& os, const MatrixElement& obj)
		{
			std::cout << obj.parent_matrix->GetValue(obj.x, obj.y);
			return os;
		}
	private:
		matrix_type* const parent_matrix;
		const size_t x;
		const size_t y;
	};
}