#pragma once

namespace Static
{

template <typename T, size_t M, size_t N>
class Matrix
{
    private:
        T data_[M][N];

    public:
        T& operator()(size_t row, size_t col)
        {
            return data_[row][col];
        }

        T operator()(size_t row, size_t col) const
        {
            return data_[row][col];
        }
};

template <size_t M, size_t N>
using Matrixi = Matrix<int,M,N>;

template <size_t M, size_t N>
using Matrixf = Matrix<float,M,N>;

template <size_t M, size_t N>
using Matrixd = Matrix<double,M,N>;

template <typename T, size_t M, size_t N>
Matrix<T,M,N> operator+(const Matrix<T,M,N>& A, const Matrix<T,M,N>& B)
{
    Matrix<T,M,N> result;
    for(size_t row = 0; row < M; ++row)
    {
        for(size_t col = 0; col < N; ++col)
        {
            result(row,col) = A(row,col) + B(row,col);
        }
    }
    return result;
}

template <typename T, size_t M, size_t N>
Matrix<T,M,N> operator-(const Matrix<T,M,N>& A, const Matrix<T,M,N>& B)
{
    Matrix<T,M,N> result;
    for(size_t row = 0; row < M; ++row)
    {
        for(size_t col = 0; col < N; ++col)
        {
            result(row,col) = A(row,col) - B(row,col);
        }
    }
    return result;
}

}