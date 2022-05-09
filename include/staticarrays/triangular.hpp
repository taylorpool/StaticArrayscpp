#pragma once

#include "matrix.hpp"

#include <iostream>

namespace Static
{

template <typename T, size_t N>
class UpperTriangular
{
    private:
        T zero_element{static_cast<T>(0)};
        T data_[N*(1+N)/2];

    public:
        T& operator()(size_t row, size_t col)
        {
            if(row > col)
            {
                return zero_element;
            }
            else
            {
                size_t index = row*(N-1)-(row-1)*row/2+col;
                return data_[index];
            }
        }
};

template <typename T, size_t N>
UpperTriangular<T,N> triu(const Matrix<T,N,N>& matrix)
{
    UpperTriangular<T,N> U;
    for(size_t row = 0; row < N; ++row)
    {
        for(size_t col = row; col < N; ++col)
        {
            U(row,col) = matrix(row,col);
        } 
    }
    return U;
}

}