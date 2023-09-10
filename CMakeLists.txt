cmake_minimum_required(VERSION 3.22)

project(playground)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(-DCMAKE_EXPORT_COMPILE_COMMANDS=1)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)


add_subdirectory(main)
add_subdirectory(twoSum)
add_subdirectory(reverseInteger)
add_subdirectory(addTwoNums)
add_subdirectory(longestSubstr)
add_subdirectory(divideTwoIntegers)
add_subdirectory(buildingBoxes)
add_subdirectory(shortestPathGraph)
add_subdirectory(reverseLinkedList)
add_subdirectory(linkedList)

add_subdirectory(tests)

