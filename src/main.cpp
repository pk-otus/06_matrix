#include <iostream>

#include "matrixFunctions.h"

int main(int, char *[])
{
	using namespace matrix;

	try
	{
		{
			Matrix<int, 0> matrix;
			for (int i = 0; i <= 9; ++i)
			{
				matrix[i][i] = i;
				matrix[i][9 - i] = 9 - i;
			}
			DrawMatrixPart(matrix, 1, 1, 8, 8);

			std::cout << "\nMatrix size: " << matrix.size() << '\n';

			PrintMatrixElements(matrix);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
