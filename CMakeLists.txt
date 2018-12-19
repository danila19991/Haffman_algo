cmake_minimum_required (VERSION 3.11)

project("Haffman")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    main.cpp
    generator/gener.inl
    generator/gener.hpp
    algorithm/huffman.inl
    algorithm/huffman.hpp
    algorithm/tree_vertex.hpp
    algorithm/tree_vertex.cpp)