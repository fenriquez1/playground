cmake_minimum_required(VERSION 3.16)

project(playground)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-Wall -pedantic")
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(twoSum)
add_subdirectory(reverseInteger)
add_subdirectory(addTwoNums)
add_subdirectory(longestSubstr)