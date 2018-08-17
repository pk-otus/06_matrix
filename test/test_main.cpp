#include <gtest/gtest.h>

#include <matrixFunctions.h>

TEST(MatrixTest, MatrixTest)
{
	matrix::Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1
	ASSERT_EQ(matrix.size(), 0); // все ячейки свободны
	auto a = matrix[0][0];
	ASSERT_TRUE(a == -1);
	ASSERT_EQ(matrix.size(), 0);
	matrix[100][100] = 314;
	ASSERT_TRUE(matrix[100][100] == 314);
	ASSERT_EQ(matrix.size(), 1);


	testing::internal::CaptureStdout();
		PrintMatrixElements(matrix);		
		// выведется одна строка
		// 100100314
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ("100100314\n", output);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
