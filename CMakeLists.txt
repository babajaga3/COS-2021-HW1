cmake_minimum_required(VERSION 4.1)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw1
        base_structures/linked_list.hpp
        base_structures/node.hpp
        base_structures/queue.hpp
        structures/crate.cpp
        structures/shelf.cpp
        structures/warehouse.cpp
        config.hpp
        main.cpp)
