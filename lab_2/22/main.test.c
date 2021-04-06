#include <assert.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void test_1(void)
{
    long a = fact(6);
    assert(a == 720);
}

void test_2(void)
{
    int b = sinFirst(5, 0.1, 1);
    assert(b == 8);
}

void test_3(void)
{
    int c = sinSecond(45.65, 0.1111, 1);
    assert(c == 20);
}

void test_4(void)
{
    double c = subFunct(2, 1);
    assert(abs(c - 2) < 0.000001);
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