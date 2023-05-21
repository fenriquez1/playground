cmake_minimum_required(VERSION 3.16)

project(playground)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")

add_subdirectory(twoSum)
add_subdirectory(reverseInteger)
add_subdirectory(addTwoNums)
add_subdirectory(longestSubstr)
add_subdirectory(divideTwoIntegers)
add_subdirectory(buildingBoxes)
add_subdirectory(shortestPathGraph)
add_subdirectory(reverseLinkedList)
