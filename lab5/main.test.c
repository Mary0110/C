#include <assert.h>
#include <stdio.h>
#include "main.h"

void test_case1(void)
{
    int r;
    stack_t* st = create_node(1);
    resize(st);
    r = st->size;
    assert(r == 11);
}

void test_case2(void)
{
    int r;
    stack_t* st = create_node(0);
    resize(st);
    r = st->size;
    assert(r == 10);
}

void test_case3(void)
{
    int r, s;
    int arr[] = {34,35,36};
    stack_t* st = create_node(5);
    fill(arr, 3, st);
    push(st, 100);
    s = st->top;
    assert(s == 3);
    r = st->element[st->top];
    assert(r == 100);
}

void test_case4(void)
{
    int r, s;
    int arr[] = {-4,5};
    stack_t* st = create_node(5);
    fill(arr, 2, st);
    push(st, -5);
    s = st->top;
    assert(s == 2);
    r = st->element[st->top];
    assert(r == -5);
}

void test_case5(void)
{
    int r, s;
    int arr[] = {34,35,36};
    stack_t* st = create_node(5);
    fill(arr, 3, st);
    r = peek(st);
    s = st->top;
    assert(r == 36);
    assert(s == 2);
}

void test_case6(void)
{
    int r, i;
    int arr[] = {34,35,36, 36, -5};
    stack_t* st = create_node(5);
    fill(arr, 5, st);
    for(i = 4; i >= 0; i--)
    {
        r = pop(st);
        assert(r == arr[i]);
    }
}

void test_case7(void)
{
    int r, i;
    int arr1[] = {34,35,36, 36, 70};
    int arr2[] = {34,34,36, 36, 45, 45, 60, 71};
    int arr3[] = {34, 35, 36, 45, 60, 70, 71};
    stack_t* st1 = create_node(5);
    stack_t* st2 = create_node(5);
    stack_t* st3 = create_node(5);

    fill(arr1, 5, st1);
    fill(arr2, 8, st2);
    fillThird(st1, st2, st3);

    for(i = 0; i < 7; i++)
    {
        r = pop(st3);
        assert(r == arr3[i]);
    }
}

#undef main

int main(void)
{
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    test_case6();
    test_case7();
    printf("tested successfully");
}
