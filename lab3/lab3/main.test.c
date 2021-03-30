#include <assert.h>
#include <time.h>
#include<stdlib.h>
#include <malloc.h>
#include "main.h"

void test_case1(int** field)
{
    srand(time(NULL));
    fill(field);
    place(field);
    int r = checkShips(field);
    assert(r == 50);
}

void test_case2(int** field)
{
    srand(time(NULL));
    fill(field);
    place(field);
    int r = checkShips(field);
    assert(r == 50);
}

#undef main

int main(void)
{
    int n = 10, m = 10, i;
    int** field = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        field[i] = (int*)malloc(m * sizeof(int));
    }
    test_case1(field);
    test_case2(field);
    for (i = 0; i < n; i++) 
    {
        free(field[i]);
    }
    free(field);
}
