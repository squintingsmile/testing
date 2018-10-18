cmake_minimum_required(VERSION 3.8)
project(testing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES quick_sort.cpp)

add_executable(testing ${SOURCE_FILES})