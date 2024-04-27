cmake_minimum_required(VERSION "3.20.21")

set(This SanitizerTests)
project(${This} C CXX)
set(CMAKE_CXX_STANDARD 17)

set (HISTORY_SANITIZER_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set (HISTORY_SANITIZER_SAMPLE_DIFF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/test/historysanitizerunittest/SampleDiff.txt")

set(CONFIG_TEMPLATE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/config")
set(CONFIG_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/config")
configure_file("${CONFIG_TEMPLATE_DIR}/config.h.in" "${CONFIG_OUTPUT_DIR}/config.h" @ONLY)



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
