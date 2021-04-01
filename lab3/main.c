#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "main.h"

int main(void)
{
    int n = 10, m = 10, i, amount, done = 1;
    int** field = NULL;

    field = (int**)malloc(n * sizeof(int*));

    if(!field) 
    {
        printf("Error\n");
        free(field);
        /*This may be nesessary if programm continues working*/
        field = NULL;
        return 1;
    }

    for (i = 0; i < n; i++) 
    {
        field[i] = (int*)malloc(n * sizeof(int));

        if(!field[i]) 
        {
            printf("Error 2");
            done = 0;
            break;
        }
    }

    if (done == 0) 
    {
        for (; i >= 0; i--) 
        { 
            free(field[i]);
        }
        free(field);
        /*This may be nesessary if programm contiues working*/
        field = NULL;
        return 1;
    }

    srand(time(NULL));

    printf("Autoplacement of ships\n");
    fill(field);
    place(field);
    clear(field);
    printf("final version:\n");
    printField(field);
    amount = checkShips(field);
    printf("am = %d", amount);

    for (i = 0; i < n; i++)
    {
        free(field[i]);
    }
    free(field);

    return 0;
}
int surround(int a, int b, int hor, int size, int** field)
{
    int  i, j;
    if (hor == 1)
    {
        for (i = a - 1; i <= a + 1; i++)
        {
            if (i >= 0 && i < 10)
            {
                for (j = b - 1; j <= b + size; j++)
                {
                    if (j >= 0 && j < 10 && field[i][j] == 0)
                    {
                        field[i][j] = 8;
                    }
                }
            }
        }
    }
    else
    {
        for (i = a - 1; i <= a + size; i++)
        {
            if (i >= 0 && i < 10)
            {
                for (j = b - 1; j <= b + 1; j++)
                {
                    if (j >= 0 && j < 10 && field[i][j] == 0)
                        field[i][j] = 8;
                }
            }
        }
    }
    return 0;
}

void fill(int** field)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            field[i][j] = 0;
        }
    }
}

void clear(int** field)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (field[i][j] == 8)
                field[i][j] = 0;
        }
    }
}

void printField(int** field)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d  ", field[i][j]);
        }
        printf("\n");
    }
}

int horCheck(int** field, int b, int a, int size)
{
    int i = 0;
    if (a + size - 1 > 9)
        return 0;

    for (i = 0; i < size; ++i)
    {
        if (field[b][a + i] != 0)
            return 0;
    }
    return 1;
}

int horFill(int** field, int b, int a, int size)
{
    int i = 0;

    for (i = 0; i < size; ++i)
    {
        field[b][a + i] = size;
    }
    return 1;
}

int verFill(int** field, int b, int a, int size)
{
    int i = 0;

    for (i = 0; i < size; ++i)
    {
        field[b + i][a] = size;
    }
    return 1;
}

int verCheck(int** field, int b, int a, int size)
{
    int i = 0;

    if (b + size - 1 > 9)
        return 0;

    for (i = 0; i < size; ++i)
    {
        if (field[b + i][a] != 0)
            return 0;
    }
    return 1;
}

void place(int** field)
{
    int size = 4, filled = 0, b, a, amount = 1, hor;

    for (size = 4; size > 0; --size)
    {
        amount = 4 - size + 1;
        for (amount = 4 - size + 1; amount > 0; --amount)
        {
            filled = 0;
            while (filled == 0)
            {
                do
                {
                    b = rand() % 10;
                    a = rand() % 10;
                } while (field[b][a] != 0);

                if (horCheck(field, b, a, size) == 1)
                {
                    filled = horFill(field, b, a, size);
                    hor = 1;
                }
                else
                {
                    if (verCheck(field, b, a, size) == 1)
                    {
                        filled = verFill(field, b, a, size);
                        hor = 0;
                    }
                }
            }
            surround(b, a, hor, size, field);
        }
    }
}

int checkShips(int** field)
{
    int i, j, countSh = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (field[i][j] > 0 && field[i][j] < 5)
            {
                countSh += field[i][j];
            }
        }
    }
    return countSh;
}