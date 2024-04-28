cmake_minimum_required(VERSION "3.20.21")

set(This CompilerTests)
project(${This} C CXX)
set(CMAKE_CXX_STANDARD 20)

#include header and source files to executable
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp" )

add_executable(${This} "${HEADER_FILES}" "${SRC_FILES}")

#including third party libraries
target_link_libraries(${This} PUBLIC
	GTest::gtest_main
	GTest::gmock_main
	TestDrivenProject
)
enable_testing()

add_test(
	NAME ${This}
	COMMAND ${This}
)
