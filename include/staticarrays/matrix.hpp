#pragma once

namespace Static
{

template <typename T, int M, int N>
class Matrix
{
    private:
        T data_[M][N];

    public:
        T& operator()(int row, int col)
        {
            return data_[row][col];
        }

        T operator()(int row, int col) const
        {
            return data_[row][col];
        }
};

template <int M, int N>
using Matrixi = Matrix<int,M,N>;

template <int M, int N>
using Matrixf = Matrix<float,M,N>;

template <int M, int N>
using Matrixd = Matrix<double,M,N>;

template <typename T, int M, int N>
Matrix<T,M,N> operator+(const Matrix<T,M,N>& A, const Matrix<T,M,N>& B)
{
    Matrix<T,M,N> result;
    for(int row = 0; row < M; ++row)
    {
        for(int col = 0; col < N; ++col)
        {
            result(row,col) = A(row,col) + B(row,col);
        }
    }
    return result;
}

template <typename T, int M, int N>
Matrix<T,M,N> operator-(const Matrix<T,M,N>& A, const Matrix<T,M,N>& B)
{
    Matrix<T,M,N> result;
    for(int row = 0; row < M; ++row)
    {
        for(int col = 0; col < N; ++col)
        {
            result(row,col) = A(row,col) - B(row,col);
        }
    }
    return result;
}

}