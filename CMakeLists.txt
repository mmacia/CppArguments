cmake_minimum_required(VERSION 2.6.4 FATAL_ERROR)
project(arguments CXX)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -std=c++0x -g")
set(CMAKE_CXX_FLAGS "-std=c++0x")

file(GLOB SOURCES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/src/ideup/*.cpp")
file(GLOB INCLUDES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/src/ideup/*.hpp")
LIST(APPEND SOURCES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/example/main.cpp")

add_executable(arguments ${SOURCES_CPP} ${SOURCES_CPP})
