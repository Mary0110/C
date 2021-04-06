#include <assert.h>
#include <stdio.h>
#include "main.h"

void test_case1(void)
{
    char str[5] = "12345";
    change(str, 5, 1);
    assert(str[0] == '5');
    assert(str[1] == '1');
    assert(str[2] == '2');
    assert(str[3] == '3');
    assert(str[4] == '4');
}


#undef main

int main(void)
{
    test_case1();
    printf("tested successfully");
}
