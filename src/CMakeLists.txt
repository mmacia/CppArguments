cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(arguments CXX)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -std=c++0x -g")
set(CMAKE_CXX_FLAGS "-std=c++0x")

file(GLOB SOURCES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/ideup/*.cpp")
file(GLOB INCLUDES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/ideup/*.hpp")

add_library(arguments SHARED ${SOURCES_CPP} ${INCLUDES_CPP})
add_library(arguments-static STATIC ${SOURCES_CPP} ${INCLUDES_CPP})
