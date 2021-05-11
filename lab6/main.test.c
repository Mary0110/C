#include <assert.h>
#include <stdio.h>
#include "main.h"

void bypassTest(tnode* node, int* arr2, int* i)

{
    if (node != NULL)
    {
        bypassTest(node->left, arr2, i);
        assert(node->data == arr2[(*i)++]);
        bypassTest(node->right, arr2, i);
    }
}

void test_case1(void)
{
    int i;
    int p = 0;
    int arr[] = { 1, 2, 3, 4 };
    int arr2[] = { 1,2, 3, 4 };
    tnode* root = NULL;

    for (i = 0; i < 4; i++)
    {
        AddSearchNode(arr[i], &root);
    }
    bypassTest(root, arr2, &p);
}

void test_case2(void)
{
    int i;
    int p = 0;
    int arr[] = { 5, 2, 4, 1, 7 };
    int arr2[] = { 1, 2, 4, 5, 7 };
    tnode* root = NULL;

    for (i = 0; i < 5; i++)
    {
        AddSearchNode(arr[i], &root);
    }
    bypassTest(root, arr2, &p);
}

void test_case3(void)
{
    int i;
    int p = 0;
    int arr[] = { -3, 5, -9, -1 };
    int arr2[] = { -9, -3, -1, 5 };
    tnode* root = NULL;

    for (i = 0; i < 4; i++)
    {
        AddSearchNode(arr[i], &root);
    }
    bypassTest(root, arr2, &p);
}

void test_case4(void)
{
    int i;
    int p = 0;
    int arr[] = { 55, -2, 34, 18, 7 };
    int arr2[] = { -2, 7, 18, 34, 55 };
    tnode* root = NULL;

    for (i = 0; i < 5; i++)
    {
        AddSearchNode(arr[i], &root);
    }
    bypassTest(root, arr2, &p);
}

void test_case5(void)
{
    int i;
    int p = 0;
    int arr[] = { 78, 222, 4, 71, 7 };
    int arr2[] = { 4, 7, 71, 78, 222 };
    tnode* root = NULL;

    for (i = 0; i < 5; i++)
    {
        AddSearchNode(arr[i], &root);
    }
    bypassTest(root, arr2, &p);
}

void test_case6(void)
{
    int i;
    int p = 0;
    int arr[] = { 0, 2, 5, 1, 7 };
    int arr2[] = { 0, 1, 2, 5, 7 };
    tnode* root = NULL;

    for (i = 0; i < 5; i++)
    {
        AddSearchNode(arr[i], &root);
    }
    bypassTest(root, arr2, &p);
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
    printf("tested successfully");
}