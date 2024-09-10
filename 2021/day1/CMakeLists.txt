cmake_minimum_required(VERSION 3.26)
project(day1)

set(CMAKE_CXX_STANDARD 23)

set(BOOST_ROOT "../../cpp-libs/boost_1_86_0")
set(BOOSTROOT "../../cpp-libs/boost_1_86_0")
find_package(Boost 1.86.0)
set(Boost_INCLUDE_DIR "../../cpp-libs/boost_1_86_0")
#set(Boost_LIBRARY_DIR C:/boost_1_70_0/stage/lib)
include_directories(${Boost_INCLUDE_DIR})
#link_directories(${Boost_LIBRARY_DIR})

FILE(COPY test-input.txt DESTINATION "${CMAKE_BINARY_DIR}")
#FILE(COPY full-input.txt DESTINATION "${CMAKE_BINARY_DIR}")

#add_executable(day1 day1_p1.cpp)
add_executable(day1 day1_p2.cpp)