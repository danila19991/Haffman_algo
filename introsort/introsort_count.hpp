//
// Created by gusef on 22.01.2019.
//

#ifndef HAFFMAN_INTROSORT_COUNT_HPP
#define HAFFMAN_INTROSORT_COUNT_HPP

#include <array>

template<typename T, size_t n>
size_t introsort(std::array<T, n>& A, int k = -1);

#include "introsort_count.inl"

#endif //HAFFMAN_INTROSORT_COUNT_HPP
