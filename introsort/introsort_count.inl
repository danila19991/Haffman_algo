//
// Created by gusef on 22.01.2019.
//

template<typename T, size_t n>
std::pair<size_t, size_t> partition_count_iterations(std::array<T, n>& A, size_t l,
                                          size_t r);

template<typename T, size_t n>
size_t introsort_impl(std::array<T, n>& A, size_t l, size_t r, size_t depth);

template<typename T, size_t n>
size_t heapsort(std::array<T, n>& A, size_t l, size_t r);

template<typename T, size_t n>
size_t heap_shift_down_root(std::array<T, n>& A, size_t l, size_t r);

template<typename T, size_t n>
size_t heap_shift_up_last(std::array<T, n>& A, size_t l, size_t r);


template<typename T, size_t n>
size_t introsort(std::array<T, n>& A, int k)
{
    size_t len = 0, m=n;
    while(m > 0){
        ++len;
        m/=2;
    }
    if(k > 0)
    {
        return introsort_impl(A, 0, static_cast<size_t>(k), len * 2) + 3*len + 1;
    }
    else
    {
        return introsort_impl(A, 0, n, len * 2) + 3*len + 1;
    }
}

template<typename T, size_t n>
size_t introsort_impl(std::array<T, n>& A, size_t l, size_t r, size_t depth)
{
    if(l + 1 >= r)
    {
        return 2;
    }

    if(l + 2 >= r)
    {
        if(A.at(l) > A.at(r - 1))
        {
            std::swap(A.at(l), A.at(r - 1));
            return 6;
        }
        return 5;
    }

    const auto pos = partition_count_iterations(A, l, r);

    if(depth > 0)
    {
        return pos.second + introsort_impl(A, l, pos.first, depth - 1) +
               introsort_impl(A, pos.first + 1, r, depth - 1) + 6;
    }
    else
    {
        return pos.second + heapsort(A, l, pos.first) +
               heapsort(A, pos.first + 1, r) + 6;
    }
}

template<typename T, size_t n>
std::pair<size_t, size_t> partition_count_iterations(std::array<T, n>& A, size_t l,
    size_t r)
{
    size_t iterations = 4;
    if(A.at(l) > A.at((l+r)/2))
    {
        if(A.at(l) > A.at(r-1))
        {
            if(A.at(r-1) > A.at((l+r)/2))
            {
                std::swap(A.at(l), A.at(r-1));
            }
            else
            {
                std::swap(A.at(l), A.at((l+r)/2));
            }
            iterations = 6;
        }
    }
    else
    {
        if(A.at(r-1) > A.at(l))
        {
            if(A.at((l+r)/2) > A.at(r-1))
            {
                std::swap(A.at(l), A.at(r-1));
            }
            else
            {
                std::swap(A.at(l), A.at((l+r)/2));
            }
            iterations = 6;
        }
    }

    size_t pos = l+1;
    ++iterations;
    for(size_t i = l+1; i< r; ++i)
    {
        if(A.at(i) < A.at(l))
        {
            std::swap(A.at(i), A.at(pos));
            ++pos;
            iterations += 2;
        }
        iterations += 3;
    }

    --pos;
    std::swap(A.at(l), A.at(pos));
    iterations += 2;

    return std::make_pair(pos, iterations+1);
}

template<typename T, size_t n>
size_t heapsort(std::array<T, n>& A, size_t l, size_t r)
{
    if(l + 1 >= r)
    {
        return 2;
    }

    size_t sz = r-l;
    size_t iterations = 3;

    for(size_t i = l+2; i<=r;++i)
    {
        iterations += heap_shift_up_last(A, l, i) + 2;
    }

    for(int i = r-1; i > l; --i)
    {
        std::swap(A.at(l), A.at(i));
        iterations += heap_shift_down_root(A, l ,static_cast<size_t>(i)) + 3;
    }

    return iterations+1;
}

template<typename T, size_t n>
size_t heap_shift_down_root(std::array<T, n>& A, size_t l, size_t r)
{
    size_t pos = 1;
    size_t iterations = 0;
    while(l + pos*2 -1< r)
    {
        iterations += 8;
        bool flag = false;
        if(l + pos*2 < r)
        {
            flag = true;
            iterations += 1;
        }
        if(flag && A.at(l + pos * 2) > A.at(l + pos * 2 - 1))
        {
            if(A.at(l + pos * 2) <= A.at(l + pos - 1))
            {
                break;
            }
            std::swap(A.at(l + pos * 2), A.at(l + pos - 1));
            pos = pos * 2 + 1;
        }
        else
        {
            if(A.at(l + pos * 2 - 1) <= A.at(l + pos - 1))
            {
                break;
            }
            std::swap(A.at(l + pos * 2 - 1), A.at(l + pos - 1));
            pos = pos * 2;
        }
        iterations += 1;
    }
    return iterations + 1;
}

template<typename T, size_t n>
size_t heap_shift_up_last(std::array<T, n>& A, size_t l, size_t r)
{
    size_t pos = r-l;
    size_t iterations =1;

    while(pos >1)
    {
        iterations += 7;
        if(A.at(pos + l - 1) <= A.at(pos/2 + l -1))
        {
            break;
        }

        std::swap(A.at(pos + l - 1), A.at(pos/2 + l -1));
        pos /= 2;

        iterations += 2;
    }
    return iterations + 1;
}
