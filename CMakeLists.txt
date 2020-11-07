cmake_minimum_required(VERSION 2.8)

project(some-matrix-creator)

set(SOURCE main.cpp)
set(HEADER)

set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

add_executable(some-matrix-creator ${SOURCE})