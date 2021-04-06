#include <assert.h>
#include <stdio.h>
#include "main.h"

void test_case1(void)
{
    int r = isLetter('a');
    assert(r == 1);
}

void test_case2(void)
{
    int r = isLetter(',');
    assert(r == 0);
}

void test_case3(void)
{
    int r = checkWord("klmn ", 4);
    assert(r == 1);
}

void test_case4(void)
{
    int r = checkWord("kln\n", 3);
    assert(r == 1);
}

void test_case5(void)
{
    int r = checkWord("klga ", 4);
    assert(r == 0);
}

#undef main

int main(void)
{
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    printf("tested successfully");
}
