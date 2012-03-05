cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(arguments CXX)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB SOURCES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/src/ideup/*.cpp")
file(GLOB INCLUDES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/src/ideup/*.hpp")

add_library(arguments STATIC ${SOURCES_CPP} ${SOURCES_CPP})

#option(BUILD_EXAMPLES_OPTION "Build example projects" ON)
#  if (BUILD_EXAMPLE_OPTIONS)
#endif
