#include "staticarrays/staticarrays.hpp"

#include <cmath>
#include <gtest/gtest.h>

using namespace Static;

TEST(Vector, IntSetValue)
{
    Vectori<3> v;
    int value = 0;
    size_t index = 0;
    v(index) = value;
    ASSERT_EQ(v(index), value);
}

TEST(Vector, Subtraction)
{
    Vectori<1> v1;
    Vectori<1> v2;
    int a = 10;
    int b = 9;
    v1(0) = a;
    v2(0) = b;
    Vectori<1> v3 = v1-v2;
    ASSERT_EQ(v3(0), a-b);
}

TEST(Vector, Addition)
{
    Vectori<1> v1;
    Vectori<1> v2;
    int a = 10;
    int b = 9;
    v1(0) = a;
    v2(0) = b;
    Vectori<1> v3 = v1+v2;
    ASSERT_EQ(v3(0), a+b);
}

TEST(Matrix, IntSetValue)
{
    Matrixi<2,2> A;
    int a = 0;
    A(0,0) = a;
    ASSERT_EQ(A(0,0), a);
}

TEST(Matrix, Addition)
{
    Matrixi<1,1> A;
    int a = 10;
    A(0,0) = a;
    Matrixi<1,1> B;
    int b = 9;
    B(0,0) = b;
    Matrixi<1,1> C = A+B;
    ASSERT_EQ(C(0,0), a+b);
}

TEST(Matrix, Subtraction)
{
    Matrixi<1,1> A;
    int a = 10;
    A(0,0) = a;
    Matrixi<1,1> B;
    int b = 9;
    B(0,0) = b;
    Matrixi<1,1> C = A-B;
    ASSERT_EQ(C(0,0), a-b);
}

TEST(Matrix, Transpose)
{
    Matrixi<2,2> A;
    A(0,0) = 0;
    A(0,1) = 1;
    A(1,0) = 2;
    A(1,1) = 3;
    Transpose<Matrixi<2,2>> At = transpose(A);
    ASSERT_EQ(At(0,0), A(0,0));
    ASSERT_EQ(At(0,1), A(1,0));
    ASSERT_EQ(At(1,0), A(0,1));
    ASSERT_EQ(At(1,1), A(1,1));
}

TEST(Vector, Transpose)
{
    Vectori<3> v;
    v(0) = 0;
    v(1) = 1;
    v(2) = 2;
    Transpose<Vectori<3>> vt = transpose(v);
}

TEST(MatrixVector, Muliplication)
{
    Matrixi<2,2> A;
    A(0,0) = 0;
    A(0,1) = 1;
    A(1,0) = 1;
    A(1,1) = 0;
    Vectori<2> v;
    v(0) = 1;
    v(1) = 2;
    Vectori<2> y = A*v;
    ASSERT_EQ(y(0), v(1));
    ASSERT_EQ(y(1), v(0));
}

TEST(MatrixMatrix, Multiplication)
{
    Matrixi<2,2> A;
    A(0,0) = 0;
    A(0,1) = 1;
    A(1,0) = 1;
    A(1,1) = 0;
    Matrixi<2,2> B;
    B(0,0) = -1;
    B(0,1) = 0;
    B(1,0) = 0;
    B(1,1) = -1;
    Matrixi<2,2> C = A*B;
    ASSERT_EQ(C(0,0), 0);
    ASSERT_EQ(C(0,1), -1);
    ASSERT_EQ(C(1,0), -1);
    ASSERT_EQ(C(1,1), 0);
}

TEST(VectorNorm, Double)
{
    Vectord<2> v;
    v(0) = 3.0;
    v(1) = 4.0;
    ASSERT_DOUBLE_EQ(norm(v), 5.0);
}

TEST(UpperTriangular, Matrix)
{
    Matrixi<3,3> A;
    A(0,0) = 0;
    A(0,1) = 1;
    A(0,2) = 2;
    A(1,0) = 3;
    A(1,1) = 4;
    A(1,2) = 5;
    A(2,0) = 6;
    A(2,1) = 7;
    A(2,2) = 8;

    UpperTriangular<int,3> U = triu(A);

    ASSERT_EQ(U(0,0), A(0,0));
    ASSERT_EQ(U(0,1), A(0,1));
    ASSERT_EQ(U(0,2), A(0,2));
    ASSERT_EQ(U(1,0), 0);
    ASSERT_EQ(U(1,1), A(1,1));
    ASSERT_EQ(U(1,2), A(1,2));
    ASSERT_EQ(U(2,0), 0);
    ASSERT_EQ(U(2,1), 0);
    ASSERT_EQ(U(2,2), A(2,2));
}

TEST(Cholesky, CholeskyDecomposition)
{
    Matrixd<2,2> A;
    A(0,0) = 4.0;
    A(0,1) = 0.0;
    A(1,0) = 0.0;
    A(1,1) = 4.0;

    Cholesky<2> ch = cholesky(A);
    ASSERT_DOUBLE_EQ(ch.U(0,0), 2.0);
    ASSERT_DOUBLE_EQ(ch.U(0,1), 0.0);
    ASSERT_DOUBLE_EQ(ch.U(1,0), 0.0);
    ASSERT_DOUBLE_EQ(ch.U(1,1), 2.0);
}

TEST(Vector, Exponent)
{
    Vectord<3> v;
    v(0) = 1.0;
    v(1) = 2.0;
    v(2) = 3.0;
    double exponent = 2.0;
    Vectord<3> v2 = v^exponent;
    ASSERT_DOUBLE_EQ(std::pow(v(0),exponent), v2(0));
    ASSERT_DOUBLE_EQ(std::pow(v(1),exponent), v2(1));
    ASSERT_DOUBLE_EQ(std::pow(v(2),exponent), v2(2));
}

TEST(Vector, SumInts)
{
    Vectori<3> v;
    v(0) = 0;
    v(1) = 1;
    v(2) = 2;
    int summation = sum(v);
    ASSERT_EQ(summation, v(0)+v(1)+v(2));
}

TEST(Vector, SumDoubles)
{
    Vectord<3> v;
    v(0) = 0.0;
    v(1) = 1.0;
    v(2) = 2.0;
    double summation = sum(v);
    ASSERT_DOUBLE_EQ(summation, v(0)+v(1)+v(2));
}

TEST(MatrixVector, DoubleMultiplication)
{
    Matrixd<3,3> A;
    Vectord<3> x;
    A(0,0) = 1.0;
    A(0,1) = 2.0;
    A(0,2) = 3.0;
    A(1,0) = 4.0;
    A(1,1) = 5.0;
    A(1,2) = 6.0;
    A(2,0) = 7.0;
    A(2,1) = 8.0;
    A(2,2) = 9.0;
    x(0) = 1.0;
    x(1) = 2.0;
    x(2) = 3.0;

    Vectord<3> b = A*x;
    ASSERT_DOUBLE_EQ(b(0), A(0,0)*x(0)+A(0,1)*x(1)+A(0,2)*x(2));
    ASSERT_DOUBLE_EQ(b(1), A(1,0)*x(0)+A(1,1)*x(1)+A(1,2)*x(2));
    ASSERT_DOUBLE_EQ(b(2), A(2,0)*x(0)+A(2,1)*x(1)+A(2,2)*x(2));
}

TEST(Vector, PlusEquals)
{
    Vectord<3> x;
    x(0) = 0.0;
    x(1) = 1.0;
    x(2) = 2.0;
    Vectord<3> y;
    y(0) = -x(0);
    y(1) = -x(1);
    y(2) = -x(2);
    x += y;
    ASSERT_DOUBLE_EQ(x(0), 0.0);
    ASSERT_DOUBLE_EQ(x(1), 0.0);
    ASSERT_DOUBLE_EQ(x(2), 0.0);
}

TEST(Vector, CrossProduct)
{
    Vectord<3> e1;
    e1(0) = 1.0;
    e1(1) = 0.0;
    e1(2) = 0.0;

    Vectord<3> e2;
    e2(0) = 0.0;
    e2(1) = 1.0;
    e2(2) = 0.0;

    Vectord<3> e3 = cross(e1,e2);
    ASSERT_DOUBLE_EQ(e3(0), 0.0);
    ASSERT_DOUBLE_EQ(e3(1), 0.0);
    ASSERT_DOUBLE_EQ(e3(2), 1.0);
}

TEST(Vector, NegativeVector)
{
    Vectord<3> vector;
    vector(0) = 10.0;
    vector(1) = 5.0;
    vector(2) = 6.3;
    Vectord<3> neg_vector = -vector;
    ASSERT_DOUBLE_EQ(neg_vector(0), -(vector(0)));
    ASSERT_DOUBLE_EQ(neg_vector(1), -(vector(1)));
    ASSERT_DOUBLE_EQ(neg_vector(2), -(vector(2)));
}

TEST(Vector, DivideByScalar)
{
    Vectord<3> vector;
    vector(0) = 2.0;
    vector(1) = 4.0;
    vector(2) = 6.0;
    double factor = 2.0;
    Vectord<3> divided = vector/factor;
    ASSERT_DOUBLE_EQ(divided(0), vector(0)/factor);
    ASSERT_DOUBLE_EQ(divided(1), vector(1)/factor);
    ASSERT_DOUBLE_EQ(divided(2), vector(2)/factor);
}

TEST(Vector, MultiplyByScalar)
{
    Vectord<3> vector;
    vector(0) = 1.0;
    vector(1) = 2.0;
    vector(2) = 3.0;
    double factor = 2.0;
    Vectord<3> result = factor*vector;
    ASSERT_DOUBLE_EQ(result(0), factor*(vector(0)));
    ASSERT_DOUBLE_EQ(result(1), factor*(vector(1)));
    ASSERT_DOUBLE_EQ(result(2), factor*(vector(2)));
}