cmake_minimum_required(VERSION 3.7)
project(dijkstra)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MatrixUDG.h)
add_executable(dijkstra ${SOURCE_FILES})