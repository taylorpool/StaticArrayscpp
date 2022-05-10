#pragma once

#include "vector.hpp"
#include "matrix.hpp"
#include "triangular.hpp"
#include "transpose.hpp"

namespace Static
{

template <int N>
struct Cholesky
{
    UpperTriangular<double,N> U;
};

template <int N>
Cholesky<N> cholesky(const Matrixd<N,N>& A)
{
    UpperTriangular<double,N> U;
    for(int row = 0; row < N; ++row)
    {
        for(int col = 0; col < N; ++col)
        {
            double sum = 0.0;
            for(int k = 0; k < row; ++k)
            {
                sum += U(k,row)*U(k,col);
            }
            if(row == col)
            {
                U(row,col) = sqrt(A(row,col) - sum);
            }
            else
            {
                U(row,col) = (A(row,col) - sum)/U(row,row);
            }
        }
    }

    return Cholesky<N> {U};
}

template <typename T, int N>
Vector<T,N> solve(const UpperTriangular<T,N>& U, const Vector<T,N>& b)
{
    Vector<T,N> result;
    for(int row = N-1; row >= 0; --row)
    {
        result(row) = b(row);
        for(int col = row+1; col < N; ++col)
        {
            result(row) -= U(row,col)*result(col);
        }
        result(row) /= U(row,row);
    }
    return result;
}

template <int N>
Vectord<N> solve(const Transpose<UpperTriangular<double,N>>& U, const Vectord<N>& b)
{
    Vectord<N> result;
    for(int row = 0; row < N; ++row)
    {
        result(row) = b(row);
        for(int col = 0; col < row; ++col)
        {
            result(row) -= U(row,col)*result(col);
        }
        result(row) /= U(row,row);
    }
    return result;
}

template <int N>
Vectord<N> solve(const Cholesky<N>& cho, const Vectord<N>& b)
{
    Vectord<N> temp = solve(transpose(cho.U), b);
    Vectord<N> result = solve(cho.U, temp);
    return result;
}

}