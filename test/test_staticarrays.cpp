#include "staticarrays/staticarrays.hpp"

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