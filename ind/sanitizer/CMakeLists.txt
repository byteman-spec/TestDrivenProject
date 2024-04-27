cmake_minimum_required(VERSION "3.20.21")

set(This SanitizerTests)
project(${This} C CXX)
set(CMAKE_CXX_STANDARD 17)

#include header and source files to executable
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )
file(GLOB_RECURSE TEST_SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp" )
file(GLOB_RECURSE MAIN_SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/main/*.cpp" )
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp" )
file(GLOB_RECURSE TEST_HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test/*.hpp" )
file(GLOB_RECURSE MAIN_HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/main/*.hpp" )

add_executable(${This} "${HEADER_FILES}" "${SRC_FILES}"
					   "${TEST_HEADER_FILES}" "${TEST_SRC_FILES}"
					   "${MAIN_HEADER_FILES}" "${MAIN_SRC_FILES}")

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
