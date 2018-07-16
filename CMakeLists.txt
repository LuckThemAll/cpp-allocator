cmake_minimum_required(VERSION 3.7)
project(cpp_allocator)

set(CMAKE_CXX_STANDARD 14)

add_executable(alloc_benchmark main.cpp allocator.cpp)