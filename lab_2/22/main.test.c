#include <assert.h>
#include "main.h"

void test_1(void)
{
    long a = fact(6);
    assert(a == 720);
}

void test_2(void)
{
    int b = sinFirst(4, 1, 0.1);
    assert(b - 6 < 0.000001);
}

void test_3(void)
{
    int c = sinSecond(45.65, 1, 0.1111);
    assert(c - 2 < 0.000001);
}

void test_4(void)
{
    double c = subFunct(2, 1);
    assert(c - 2 < 0.000001);
}

#undef main

int main(void)
{
    test_1();
    test_2();
    test_3();
    test_4();
    return 0;
}