//
// Created by gusef on 14.12.2018.
//

#include <iostream>
#include <iterator>
#include <algorithm>

#include "generator/gener.hpp"
#include "algorithm/huffman.hpp"

#include <chrono>

constexpr int iterations = 100;
constexpr int n = 100000;
constexpr int m = 5000000;

huffman_tree<n> tree;

int main(){
    alphabet_weight_generator<n> generator;
    std::cout.precision(9);
    std::cout<<std::fixed;

    double sum = 0;

    for(int i=0;i<iterations;++i){
        const auto input = generator.generate_weights(m);
        auto start = std::chrono::high_resolution_clock::now();
        tree.generate(input);
        auto end = std::chrono::high_resolution_clock::now();
        double k = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count())*(1.e-9);
        sum+=k;
    }
    std::cout << "middle:\n" << sum/iterations << '\n';
}