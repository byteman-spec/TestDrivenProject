cmake_minimum_required(VERSION "3.20.21")

set(This TestDrivenProject)
project(${This} C CXX)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory("tincl/googletest")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#include header files to executable
file(GLOB_RECURSE DBCLIENT_HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/dbclient/*.hpp" )
file(GLOB_RECURSE LEXER_HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/lexer/*.hpp" )
file(GLOB_RECURSE PARSER_HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/*.hpp" )
file(GLOB_RECURSE PRINTER_HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/printer/*.hpp" )
file(GLOB_RECURSE SYNTAXNODE_HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/syntaxnode/*.hpp" )
file(GLOB_RECURSE UTILS_HEADER_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.hpp" )


#include src files to executable
file(GLOB_RECURSE DBCLIENT_SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/dbclient/*.cpp" )
file(GLOB_RECURSE LEXER_SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/lexer/*.cpp" )
file(GLOB_RECURSE PARSER_SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/parser/*.cpp" )
file(GLOB_RECURSE PRINTER_SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/printer/*.cpp" )
file(GLOB_RECURSE SYNTAXNODE_SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/syntaxnode/*.cpp" )
file(GLOB_RECURSE UTILS_SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.cpp" )


list(APPEND HEADER_FILES ${DBCLIENT_HEADER_FILES}
					   	 ${LEXER_HEADER_FILES} 
						 ${PARSER_HEADER_FILES} 
						 ${PRINTER_HEADER_FILES} 
						 ${SYNTAXNODE_HEADER_FILES}
						 ${UTILS_HEADER_FILES})

list(APPEND SRC_FILES ${DBCLIENT_SRC_FILES}
					   	 ${LEXER_SRC_FILES} 
						 ${PARSER_SRC_FILES} 
						 ${PRINTER_SRC_FILES} 
						 ${SYNTAXNODE_SRC_FILES}
						 ${UTILS_SRC_FILES})


# Defining macros
add_definitions(-DRESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH ="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
#add_executable(${This} "${HEADER_FILES}" "${SRC_FILES}")
#including additional subdirectories
#target_include_directories(GoogleTestClone PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
add_library(${This} STATIC ${SRC_FILES} ${HEADER_FILES})

enable_testing()

add_subdirectory(test)
add_subdirectory(ind/sanitizer)
#including third party libraries
