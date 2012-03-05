cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(arguments CXX)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -std=c++0x -g")
set(CMAKE_CXX_FLAGS "-std=c++0x")

file(GLOB SOURCES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/src/ideup/*.cpp")
file(GLOB INCLUDES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/src/ideup/*.hpp")

add_library(arguments STATIC ${SOURCES_CPP} ${SOURCES_CPP})
