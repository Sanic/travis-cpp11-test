cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test-travis)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")
add_definitions(-std=c++11)

ADD_EXECUTABLE( main
	test.cpp
)
