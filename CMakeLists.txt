cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(arguments CXX)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

option(BUILD_EXAMPLES_OPTION "Build example projects" ON)

if (BUILD_EXAMPLES_OPTION)
  add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/example")
endif(BUILD_EXAMPLES_OPTION)
