cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test-travis)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")
add_definitions(-std=c++11)

ADD_EXECUTABLE( main
	example.cpp
)

ADD_LIBRARY( lib SHARED
	example.cpp
)

################################
# Testing
################################
if (test)
	# This adds another subdirectory, which has 'project(gtest)'.
	add_subdirectory(lib/googletest/googletest/)

	enable_testing()

	# Include the gtest library. gtest_SOURCE_DIR is available due to
	# 'project(gtest)' above.
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

	##############
	# Unit Tests
	##############
	add_executable(runUnitTests tests.cpp)

	# Standard linking to gtest stuff.
	target_link_libraries(runUnitTests gtest gtest_main lib)

	# You can also omit NAME and COMMAND. The second argument could be some other
	# test executable.
	add_test(that-other-test-I-made runUnitTests)
endif()
