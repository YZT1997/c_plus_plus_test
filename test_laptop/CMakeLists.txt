cmake_minimum_required(VERSION 3.17)
project(test_laptop)

set(CMAKE_CXX_STANDARD 14)

include_directories(. ./include)

add_executable(test_laptop include/PrototypeWork.h include/TreeNode.h leetcode_424.cpp)
