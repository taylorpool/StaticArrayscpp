#pragma once

#include "vector.hpp"
#include "matrix.hpp"

namespace Static
{

template <typename T, int N>
class UpperTriangular
{
    private:
        T zero_element{static_cast<T>(0)};
        T data_[N*(1+N)/2];

    public:
        T& operator()(int row, int col)
        {
            if(row > col)
            {
                return zero_element;
            }
            else
            {
                int index = row*(N-1)-(row-1)*row/2+col;
                return data_[index];
            }
        }

        T operator()(int row, int col) const
        {
            if(row > col)
            {
                return zero_element;
            }
            else
            {
                int index = row*(N-1)-(row-1)*row/2+col;
                return data_[index];
            }
        }
};

template <typename T, int N>
UpperTriangular<T,N> triu(const Matrix<T,N,N>& matrix)
{
    UpperTriangular<T,N> U;
    for(int row = 0; row < N; ++row)
    {
        for(int col = row; col < N; ++col)
        {
            U(row,col) = matrix(row,col);
        } 
    }
    return U;
}


}