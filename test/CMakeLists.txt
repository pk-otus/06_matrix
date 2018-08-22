cmake_minimum_required(VERSION 3.2)

project(test_matrix)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(matrix_test test_main.cpp ${HEADER_FILES})

set_target_properties(matrix_test PROPERTIES
INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIRS};${INCLUDE_DIR}"
)

target_link_libraries(matrix_test ${GTEST_LIBRARIES} )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_link_libraries(matrix_test pthread)
endif()

add_test(MatrixTest matrix_test)
