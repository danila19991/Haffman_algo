//
// Created by gusef on 18.12.2018.
//

#include "huffman.hpp"

template<int n>
huffman_tree<n>::huffman_tree(const std::array<size_t, n>& weights)
{
    generate_impl(weights);
}

template<int n>
void huffman_tree<n>::generate(const std::array<size_t, n>& weights)
{
    clean();
    generate_impl(weights);
}

template<int n>
vertex huffman_tree<n>::get_root()
{
    return _vertexes.bsck();
}

template<int n>
vertex huffman_tree<n>::get_vertex(int id)
{
    return _vertexes.at(id);
}

template<int n>
void huffman_tree<n>::clean()
{
    _vertexes.fill(std::make_pair(0,vertex()));
}

template<int n>
void huffman_tree<n>::generate_impl(const std::array<size_t, n>& weights)
{
    throw std::exception();
}
