cmake_minimum_required(VERSION 3.12.1)
project(binaryHeap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MAXHeap.h MINHeap.h)
add_executable(binaryHeap ${SOURCE_FILES})