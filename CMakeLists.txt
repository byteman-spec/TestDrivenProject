cmake_minimum_required(VERSION "3.20.21")

set(This TestDrivenProject)
project(${This} C CXX)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory("tincl/googletest")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#include header and source files to executable
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp" )

# Defining macros
add_definitions(-DRESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH ="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
#add_executable(${This} "${HEADER_FILES}" "${SRC_FILES}")
#including additional subdirectories
#target_include_directories(GoogleTestClone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
add_library(${This} STATIC ${SRC_FILES} ${HEADER_FILES})

enable_testing()

add_subdirectory(test)
#including third party libraries
