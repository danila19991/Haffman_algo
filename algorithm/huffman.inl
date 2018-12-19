//
// Created by gusef on 18.12.2018.
//

#include <algorithm>
#include <limits>
#include <iostream>

template<int n>
huffman_tree<n>::huffman_tree(const std::array<size_t, n>& weights):
    _vertexes{std::make_pair(std::numeric_limits<size_t>::max(),vertex())}
{
    generate(weights);
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
    _vertexes.fill(std::make_pair(std::numeric_limits<size_t>::max(),vertex()));
}

template<int n>
void huffman_tree<n>::generate_impl(const std::array<size_t, n>& weights)
{
    for(size_t i=0;i<n; ++i){
        _vertexes.at(i).first = weights.at(i);
        _vertexes.at(i).second._symbol = i;
    }
    std::sort(std::begin(_vertexes), std::end(_vertexes));
    size_t t1=0, t2= static_cast<size_t>(n), t3= static_cast<size_t>(n);

    for(int i=1;i<n;++i){
        std::array<int, 2> min_index = {-1, -1};
        size_t w_sum = 0;

        for(size_t j=0;j<2;++j){
            if(_vertexes.at(t1).first < _vertexes.at(t2).first && t1 < n){
                min_index.at(j) = t1;
                w_sum += _vertexes.at(t1).first;
                ++t1;
            }
            else{
                min_index.at(j) = t2;
                w_sum += _vertexes.at(t2).first;
                ++t2;
            }
        }

        _vertexes.at(t3) = std::make_pair(w_sum, vertex(min_index));
        ++t3;
    }
}

template<int n>
void huffman_tree<n>::print()
{
    for(size_t i=0;i<_vertexes.size();++i){
        std::cout << i << ' ' << _vertexes.at(i).second.get_symbol() << ' '
                 << _vertexes.at(i).second.get_next(0) << ' '
            << _vertexes.at(i).second.get_next(1) << ' '
                 << _vertexes.at(i).first << '\n';
    }

    std::cout<<'\n';
}
