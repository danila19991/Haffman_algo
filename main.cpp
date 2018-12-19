//
// Created by gusef on 14.12.2018.
//

#include <iostream>
#include <iterator>
#include <algorithm>

#include "generator/gener.hpp"
#include "algorithm/huffman.hpp"

int main(){
    alphabet_weight_generator<5> generator;
    auto input = generator.generate_weights(10);
    std::copy(std::begin(input), std::end(input),
        std::ostream_iterator<size_t>(std::cout, " "));
    std::cout<<'\n';
    huffman_tree<5> tree(input);
    tree.print();
}