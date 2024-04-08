cmake_minimum_required(VERSION "3.20.21")

set(This TestLib)
project(${This} C CXX)
set(CMAKE_CXX_STANDARD 17)

#include header and source files to executable
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp" )

add_executable(${This} "${HEADER_FILES}" "${SRC_FILES}")

#including third party libraries
target_link_libraries(${This} PUBLIC
	GTest::gtest_main
	TestDrivenProject
)

add_test(
	NAME ${This}
	COMMAND ${This}
)
