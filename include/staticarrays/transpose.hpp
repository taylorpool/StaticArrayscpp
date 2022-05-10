#pragma once

#include "vector.hpp"
#include "matrix.hpp"
#include "triangular.hpp"

namespace Static
{

template <typename T>
class Transpose;

template <typename T, int N>
class Transpose<Vector<T,N>>
{
    private:
        const Vector<T,N>* vector_;

    public:
        Transpose(const Vector<T,N>& vector)
        : vector_(&vector) {}
};

template <typename T, int M, int N>
class Transpose<Matrix<T,N,M>>
{
    private:
        const Matrix<T,N,M>* matrix_;

    public:
        Transpose(const Matrix<T,N,M>& matrix)
        : matrix_(&matrix) {}

        T operator()(int row, int col) const
        {
            return matrix_->operator()(col,row);
        }
};

template <typename T, int N>
class Transpose<UpperTriangular<T,N>>
{
    private:
        const UpperTriangular<T,N>* U_;

    public:
        Transpose(const UpperTriangular<T,N>& U)
        : U_(&U) {}

        T operator()(int row, int col) const
        {
            return U_->operator()(col,row);
        }
};

template <typename T, int N>
Transpose<Vector<T,N>> transpose(const Vector<T,N>& vector)
{
    return Transpose<Vector<T,N>>(vector);
}

template <typename T, int M, int N>
Transpose<Matrix<T,M,N>> transpose(const Matrix<T,N,M>& matrix)
{
    return Transpose<Matrix<T,M,N>>(matrix);
}

template <typename T, int N>
Transpose<UpperTriangular<T,N>> transpose(const UpperTriangular<T,N>& U)
{
    return Transpose<UpperTriangular<T,N>>(U);
}

}