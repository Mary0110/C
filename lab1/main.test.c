#include <assert.h>
#include "main.h"

void test_case1(void)
{
    int r = Sum("4505.0554");
    assert(r == 14);
}

void test_case2(void)
{
    int r = Sum("45.cs7");
    assert(r == -1);
}

#undef main

int main(void)
{
    test_case1();
    test_case2();
}
