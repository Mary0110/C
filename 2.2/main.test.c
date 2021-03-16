#include <assert.h>
#include "main.h"

void test_1(void)
{
    long a = fact(6);
    assert(a == 720);
}
void test_2(void)
{
    double b = sinExpansion(4, 1);
    assert(b == 4);
}

#undef main

int main(void)
{
    test_1();
    test_2();
}