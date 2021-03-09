#include <stdio.h>
#include "main.h"

int main(void)
{
    char number[100];
    
    printf("enter real number\n");
    scanf("%99s", number);
    printf("MAX sum: %d", Sum(number));
}

int Sum(char *str)
{
    int sum1 = 0, sum2 = 0, sum = 0, i = 0;

    while (str[i] != '.')
    {
        sum1 += str[i] - '0';
        i++;
    }
    i++;
    while (str[i])
    {
        sum2 += str[i] - '0';
        i++;
    }

    sum = (sum1 <= sum2) ? sum2 : sum1;
    return sum;
}
