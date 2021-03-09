#include <assert.h>
#include "main.h"

void test_case1(void)
{
    int r = Sum("4505.0554");
    assert(r == 14);
}

#undef main

int main(void)
{
    test_case1();
}
