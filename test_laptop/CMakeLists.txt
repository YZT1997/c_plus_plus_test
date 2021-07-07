cmake_minimum_required(VERSION 3.17)
project(test_laptop)

set(CMAKE_CXX_STANDARD 14)

include_directories(. ./include)

add_executable(test_laptop include/QuickSort.h include/MergeSort.h include/HeapSort.h 7_7_2.cpp)
