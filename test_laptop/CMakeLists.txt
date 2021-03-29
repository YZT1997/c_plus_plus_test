cmake_minimum_required(VERSION 3.17)
project(test_laptop)

set(CMAKE_CXX_STANDARD 14)

include_directories(. ./include)

add_executable(test_laptop include/BinaryTree.h include/HfTree.h 3_2.cpp)
