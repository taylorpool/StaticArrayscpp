#pragma once

#include <cmath>

namespace Static
{

template <typename T, int N>
class Vector
{
    private:
        T data_[N];

    public:
        Vector() {}

        T operator()(int index) const
        {
            return data_[index];
        }

        T& operator()(int index)
        {
            return data_[index];
        }
};

template <int N>
using Vectori = Vector<int,N>;

template <int N>
using Vectorf = Vector<float,N>;

template <int N>
using Vectord = Vector<double,N>;

template <typename T, int N>
Vector<T,N> operator+(const Vector<T,N>& v1, const Vector<T,N>& v2)
{
    Vector<T,N> result;
    for(int index = 0; index < N; ++index)
    {
        result(index) = v1(index) + v2(index);
    }
    return result;
}

template <int N>
Vectord<N>& operator+=(Vectord<N>& v1, const Vectord<N>& v2)
{
    for(int index = 0; index < N; ++index)
    {
        v1(index) += v2(index);
    }
    return v1;
}

template <typename T, int N>
Vector<T,N> operator-(const Vector<T,N>& v1, const Vector<T,N>& v2)
{
    Vector<T,N> result;
    for(int index = 0; index < N; ++index)
    {
        result(index) = v1(index) - v2(index);
    }
    return result;
}

template <typename T, int N>
Vector<T,N> operator-(const Vector<T,N>& vector)
{
    Vector<T,N> result;
    for(int index = 0; index < N; ++index)
    {
        result(index) = -(vector(index));
    }
    return result;
}

template <typename T, int N>
Vector<T,N> operator*(const T& value, const Vector<T,N>& vector)
{
    Vector<T,N> result;
    for(int index = 0; index < N; ++index)
    {
        result(index) = value*(vector(index));
    }
    return result;
}

template <typename T, int N>
Vector<T,N> operator/(const Vector<T,N>& vector, const T& value)
{
    Vector<T,N> result;
    for(int index = 0; index < N; ++index)
    {
        result(index) = vector(index)/value;
    }
    return result;
}

template <int N>
Vectord<N> operator^(const Vectord<N>& vector, double exponent)
{
    Vectord<N> result;
    for(int index = 0; index < N; ++index)
    {
        result(index) = std::pow(vector(index), exponent);
    }
    return result;
}

template <typename T, int N>
T sum(const Vector<T,N>& vector)
{
    T result = vector(0);
    for(int index = 1; index < N; ++index)
    {
        result += vector(index);
    }
    return result;
}


}