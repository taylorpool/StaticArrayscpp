#pragma once

#include <cmath>

namespace Static
{

template <typename T, size_t N>
class Vector
{
    private:
        T data_[N];

    public:
        Vector() {}

        T operator()(size_t index) const
        {
            return data_[index];
        }

        T& operator()(size_t index)
        {
            return data_[index];
        }
};

template <size_t N>
using Vectori = Vector<int,N>;

template <size_t N>
using Vectorf = Vector<float,N>;

template <size_t N>
using Vectord = Vector<double,N>;

template <typename T, size_t N>
Vector<T,N> operator+(const Vector<T,N>& v1, const Vector<T,N>& v2)
{
    Vector<T,N> result;
    for(size_t index = 0; index < N; ++index)
    {
        result(index) = v1(index) + v2(index);
    }
    return result;
}

template <size_t N>
Vectord<N>& operator+=(Vectord<N>& v1, const Vectord<N>& v2)
{
    for(size_t index = 0; index < N; ++index)
    {
        v1(index) += v2(index);
    }
    return v1;
}

template <typename T, size_t N>
Vector<T,N> operator-(const Vector<T,N>& v1, const Vector<T,N>& v2)
{
    Vector<T,N> result;
    for(size_t index = 0; index < N; ++index)
    {
        result(index) = v1(index) - v2(index);
    }
    return result;
}

template <typename T, size_t N>
Vector<T,N> operator-(const Vector<T,N>& vector)
{
    Vector<T,N> result;
    for(size_t index = 0; index < N; ++index)
    {
        result(index) = -(vector(index));
    }
    return result;
}

template <size_t N>
Vectord<N> operator^(const Vectord<N>& vector, double exponent)
{
    Vectord<N> result;
    for(size_t index = 0; index < N; ++index)
    {
        result(index) = std::pow(vector(index), exponent);
    }
    return result;
}

template <typename T, size_t N>
T sum(const Vector<T,N>& vector)
{
    T result = vector(0);
    for(size_t index = 1; index < N; ++index)
    {
        result += vector(index);
    }
    return result;
}


}