#pragma once

#include "matrix.hpp"

namespace Static
{

template <typename T>
class Transpose;

template <typename T, size_t N>
class Transpose<Vector<T,N>>
{
    private:
        const Vector<T,N>* vector_;

    public:
        Transpose(const Vector<T,N>& vector)
        : vector_(&vector) {}
};

template <typename T, size_t M, size_t N>
class Transpose<Matrix<T,N,M>>
{
    private:
        const Matrix<T,N,M>* matrix_;

    public:
        Transpose(const Matrix<T,N,M>& matrix)
        : matrix_(&matrix) {}

        T operator()(size_t row, size_t col) const
        {
            return matrix_->operator()(col,row);
        }
};

template <typename T, size_t N>
Transpose<Vector<T,N>> transpose(const Vector<T,N>& vector)
{
    return Transpose<Vector<T,N>>(vector);
}

template <typename T, size_t M, size_t N>
Transpose<Matrix<T,M,N>> transpose(const Matrix<T,N,M>& matrix)
{
    return Transpose<Matrix<T,M,N>>(matrix);
}

}