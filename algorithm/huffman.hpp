//
// Created by gusef on 18.12.2018.
//

#ifndef HAFFMAN_HUFFMAN_HPP
#define HAFFMAN_HUFFMAN_HPP

#include <array>

#include "tree_vertex.hpp"

template <int n>
class huffman_tree{
    std::array<std::pair<size_t, vertex>, 2*n -1> _vertexes;

    void clean();

    size_t generate_impl(const std::array<size_t, n>& weights);

public:

    huffman_tree() = default;

    explicit huffman_tree(const std::array<size_t, n>& weights);

    size_t generate(const std::array<size_t, n>& weights);

    vertex get_root();

    vertex get_vertex(int id);

    void print();
};

#include "huffman.inl"

#endif //HAFFMAN_HUFFMAN_HPP
