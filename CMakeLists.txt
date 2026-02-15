cmake_minimum_required(VERSION 4.1)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw1
        base_structures/linked_list.cpp
        base_structures/node.cpp
        base_structures/queue.cpp
        structures/crate.cpp
        structures/shelf.cpp
        structures/warehouse.cpp
        consts.hpp
        main.cpp)
