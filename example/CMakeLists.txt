cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(example CXX)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -std=c++0x -g")
set(CMAKE_CXX_FLAGS "-std=c++0x")

file(GLOB SOURCES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(example ${SOURCES_CPP})
target_link_libraries(example arguments-static)
