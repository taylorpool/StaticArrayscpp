#pragma once

#include "vector.hpp"
#include "matrix.hpp"

namespace Static
{

template <int N>
double norm(const Vectord<N>& vector)
{
    double result = 0.0;
    for(int index = 0; index < N; ++index)
    {
        result += vector(index)*vector(index);
    }
    return std::sqrt(result); 
}

template <typename T, int M, int N>
Vector<T,M> operator*(const Matrix<T,M,N>& A, const Vector<T,N>& x)
{
    Vector<T,M> result;
    for(int row = 0; row < M; ++row)
    {
        result(row) = A(row,0)*x(0);
        for(int col = 1; col < N; ++col)
        {
            result(row) += A(row,col)*x(col);
        }
    }
    return result;
}

template <int M, int N, int S>
Matrixi<M,S> operator*(const Matrixi<M,N>& A, const Matrixi<N,S>& B)
{
    Matrixi<M,S> result;
    for(int row = 0; row < M; ++row)
    {
        for(int col = 0; col < S; ++col)
        {
            result(row,col) = 0;
            for(int k = 0; k < N; ++k)
            {
                result(row,col) += A(row,k)*B(k,col);
            }
        }
    }
    return result;
}

template <typename T>
Vector<T,3> cross(const Vector<T,3>& left, const Vector<T,3>& right)
{
    Vector<T,3> result;
    result(0) = left(1)*right(2) - left(2)*right(1);
    result(1) = left(2)*right(0) - left(0)*right(2);
    result(2) = left(0)*right(1) - left(1)*right(0);
    return result;
}

}