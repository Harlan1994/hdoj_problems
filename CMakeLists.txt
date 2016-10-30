cmake_minimum_required(VERSION 3.6)
project(hdoj_problems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hdoj_2042/hdoj_2042.cpp)
add_executable(hdoj_problems ${SOURCE_FILES})