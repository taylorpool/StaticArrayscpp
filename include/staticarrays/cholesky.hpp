#pragma once

#include "matrix.hpp"
#include "triangular.hpp"

namespace Static
{

template <size_t N>
struct Cholesky
{
    UpperTriangular<double,N> U;
};

template <size_t N>
Cholesky<N> cholesky(const Matrixd<N,N>& A)
{
    UpperTriangular<double,N> U;
    for(size_t row = 0; row < N; ++row)
    {
        for(size_t col = 0; col < N; ++col)
        {
            double sum = 0.0;
            for(size_t k = 0; k < row; ++k)
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

}