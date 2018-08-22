cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
   project(matrix VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
   project(matrix VERSION 0.0.1)
endif()

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB HEADER_FILES	${INCLUDE_DIR}/*.h)
file(GLOB SRC_FILES		${SRC_DIR}/*.cpp)

add_executable(matrix ${HEADER_FILES} ${SRC_FILES})

	set_target_properties(matrix PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		INCLUDE_DIRECTORIES ${INCLUDE_DIR}
	)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set_target_properties(matrix PROPERTIES
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
	)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties(matrix PROPERTIES
		COMPILE_OPTIONS -W3 
	)
endif()

install(TARGETS matrix RUNTIME DESTINATION bin)

enable_testing()
add_subdirectory(test)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT a@a.a)

include (CPack)

