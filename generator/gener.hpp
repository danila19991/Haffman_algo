#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <array>
#include <random>
#include <chrono>


/**
 * \brief     Generator of huffman input params.
 * \tparam n  Size of alphabet which emulates by this generator.
 */
template<size_t n>
class alphabet_weight_generator{

    /**
     * \brief Random generator.
     */
    std::mt19937 generator;

    /**
     * \brief distribution for getting specific data.
     */
    std::uniform_int_distribution<int> distribution;

    /**
     * \brief   Function for generating next random value.
     * \return  Random integer number.
     */
    int next_rand();

public:
    /**
     * \brief Constructor of generator.
     */
    alphabet_weight_generator();

    /**
     * \brief       Function for generating input array of huffman algorithm.
     * @param[in] m Size of emulated text.
     * @return      Array of symbol frequencies.
     */
    std::array<size_t, n> generate_weights(long long m);
};

#include "gener.inl"

#endif // GENERATOR_HPP