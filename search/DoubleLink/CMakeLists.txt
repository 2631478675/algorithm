cmake_minimum_required(VERSION 3.7)
project(DoubleLink)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DoubleLink.h)
add_executable(DoubleLink ${SOURCE_FILES})