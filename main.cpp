//
// Created by gusef on 14.12.2018.
//

#include <iostream>
#include <iterator>
#include <algorithm>

#include "generator/gener.hpp"

int main(){
    alphabet_weight_generator<5> generator;
    auto input = generator.generate_weights(100);
    std::copy(std::begin(input), std::end(input),
        std::ostream_iterator<size_t>(std::cout, " "));
}