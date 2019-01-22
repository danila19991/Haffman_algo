//
// Created by gusef on 14.12.2018.
//

#include <iostream>
#include <iterator>
#include <algorithm>

#include "generator/gener.hpp"
#include "algorithm/huffman.hpp"
#include "introsort/introsort_count.hpp"

#include <chrono>
#include <iomanip>
#include <fstream>

constexpr int iterations = 430'000;
constexpr int n = 2'500;
constexpr int m = 50'000;


int main(){
    huffman_tree<n> tree;
    alphabet_weight_generator<n> generator;

    std::ofstream out("data25.txt");

    double sum = 0;

    for(int i=0;i<iterations;++i){
        const auto input = generator.generate_weights(m);
        auto time = tree.generate(input);
        out<<time<<'\n';
        sum+=static_cast<double>(time);
    }
    std::cout << "middle:\n" << sum/iterations << '\n';
}