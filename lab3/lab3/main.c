#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "main.h"

int main(void)
{
    int n = 10, m = 10, i, amount;
    int** field = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        field[i] = (int*)malloc(m * sizeof(int));
    }

    srand(time(NULL));

    printf("Autoplacement of ships\n");
    fill(field);
    place(field);
    /*clear(field);*/
    printf("final version:\n");
    printField(field);
    amount = checkShips(field);
    printf("am = %d", amount);

    for (i = 0; i < n; i++) 
    {
        free(field[i]);
    }
    free(field);
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
            if(field[i][j] == 8)
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

void place(int** field)
{
    int i, jm1, a, b, k, f;

    for (i = 4; i > 0; i--)
    {
        for (k = 4 - i + 1; k > 0; k--)
        {
            for (jm1 = 0; jm1 < i; jm1++)                  
            {
                if (jm1 == 0)
                {
                    do
                    {
                        a = rand() % (9 - (0) + 1) + (0);
                        b =  rand() % (9 - (0) + 1) + (0);
                    } while (field[a][b] != 0);
                }
                if (a + jm1 < 10 && field[a + jm1][b] == 0)
                {
                    field[a + jm1][b] = i;
                    f = 0;
                }
                else
                {
                    if (f == 0) {
                        for (jm1--; jm1 > 0; jm1--)   /*erasing*/
                        {
                            field[a + jm1][b] = 0;
                        }
                        jm1++;
                    }

                    if (field[a][b + jm1] == 0)
                    {
                        field[a][b + jm1] = i;
                        f = 1;
                    }
                    else
                    {
                        for (jm1 --; jm1 >= 0; jm1--)
                        {
                            field[a][b + jm1] = 0;
                        }
                    }
                }
            }
            surround(a, b, f, i , field);
        }
    }
}
void surround(int a, int b, int f, int size, int** field)
{   
    int  i, j;
    if (f == 1)
    {
        for (i = a - 1; i <= a + 1; i++)
        {
            if (i >= 0 && i < 10) {
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


