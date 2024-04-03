cmake_minimum_required(VERSION 3.27)
project(aizo)

set(CMAKE_CXX_STANDARD 17)

add_library(aizo STATIC array.cpp array.h)

add_executable(program main.cpp)
target_link_libraries(program PRIVATE aizo)
