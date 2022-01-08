cmake_minimum_required(VERSION 3.20)
project(task1_dynamic_memory_allocation_dina_khalid)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(task1_dynamic_memory_allocation_dina_khalid
        nbproject/private/c_standard_headers_indexer.c
        nbproject/private/cpp_standard_headers_indexer.cpp
        catch.hpp
        main.cpp
        MyArray.h
        test.cpp)
