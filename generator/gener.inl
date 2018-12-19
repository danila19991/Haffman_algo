template<size_t n>
alphabet_weight_generator<n>::alphabet_weight_generator():
    generator(std::chrono::system_clock::now().time_since_epoch().count()),
    distribution(0,n-1)
{
}

template<size_t n>
int alphabet_weight_generator<n>::next_rand(){
    return distribution(generator);
}

template<size_t n>
std::array<size_t, n>
alphabet_weight_generator<n>::generate_weights(long long m)
{
    std::array<size_t, n> result;
    result.fill(0);
    for(size_t i=0;i<m;++i){
        result.at(next_rand()) += 1;
    }
    return result;
}
