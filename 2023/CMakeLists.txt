cmake_minimum_required(VERSION 3.26)
project(advent_of_code_2023)

set(CMAKE_CXX_STANDARD 23)

find_package(Boost 1.83.0)
if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        add_executable(advent_of_code_2023 day3/day3.cpp
                utils/utils.h
                day3/Part.cpp
                day3/Part.h
                utils/cords.h
        )

        target_include_directories(advent_of_code_2023 PUBLIC utils)
endif()


