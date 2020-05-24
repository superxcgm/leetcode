cmake_minimum_required(VERSION 3.16)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})

find_package(Threads REQUIRED)
find_package(gtest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})


add_executable(leetcode main.cpp)

target_link_libraries(leetcode ${GTest_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})