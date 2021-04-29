#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    int i, size;
    int arr1[] = {1,2,3,3,5,7,8,10};
    int arr2[] = {2,2,2,3,11,12,15};

    stack_t* st1 = create_node(5);
    stack_t* st2 = create_node(5);
    stack_t* st3 = create_node(5);

    fill(arr1, 8, st1);
    fill(arr2, 7, st2);

    fillThird(st1, st2, st3);

    size = st3->top;

    for (i = 0; i <= size; i++)
    {
        printf("%d ", pop(st3));
    }
    deleteStack(&st1);
    deleteStack(&st2);
    deleteStack(&st3);
}

stack_t* create_node(const int size)
{
    stack_t* st = (stack_t*)malloc(sizeof(stack_t));
    if (st == NULL)
        exit(1);
    st->size = size;
    st->top = -1;
    st->element = (int*)malloc(sizeof(int) * size);
    if (st->element == NULL)
    {
        deleteStack(&st);
        exit(1);
    }
    return st;
}

void deleteStack(stack_t** st)
{
    free((*st)->element);
    free(*st);
    *st = NULL;
}

void resize(stack_t* st)
{
    int* tmp;
    st->size += 10;
    tmp = (int*)realloc(st->element, st->size * sizeof(int));
    if (tmp == NULL)
    {
        deleteStack(&st);
        exit(1);
    }
    st->element = tmp;
}

void push(stack_t* st, const int elem)
{
    if (st->top + 1 >= st->size)
    {
        resize(st);
    }
    st->top++;
    st->element[st->top] = elem;
}

int peek(stack_t* st)
{
    if (st->size < 1)
    {
        deleteStack(&st);
        exit(1);
    }
    return st->element[st->top];
}

int pop(stack_t* st)
{
    if (st->size <= 0)
    {
        deleteStack(&st);
        exit(1);
    }
    return st->element[st->top--];
}

void fill(int* arr, const int size, stack_t* st)
{
    int i;
    for (i = 0; i < size; i++)
    {
        push(st, arr[i]); 
    }
}

void fillThird(stack_t* st1, stack_t* st2, stack_t* st3)
{
    int a;
    while (st1->top > -1 || st2->top > -1)
    {
        if (st1->top > -1 && st2->top > -1)
        {
            if (peek(st1) >= peek(st2))
            {
                a = pop(st1);
                if (st3->top == -1 || peek(st3) != a)
                {
                    push(st3, a);
                }
            }
            else 
            {
                a = pop(st2);
                if (st3->top == -1 || peek(st3) != a)
                {
                    push(st3, a);
                }
            }
        }
        else if (st1->top > -1)
        {
            a = pop(st1);
            if (st3->top == -1 || peek(st3) != a)
            {
                push(st3, a);
            }
        }
        else if (st2->top > -1)
        {
            a = pop(st2);
            if (st3->top == -1 || peek(st3) != a)
            {
                push(st3, a);
            }
        }
    }
}

