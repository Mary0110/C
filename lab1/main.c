#include <stdio.h>
#include "main.h"

int main(void)
{
    char number[100];
    int res;
    printf("enter real number\n");
    
    do
    {
        scanf("%99s", number);
        res = Sum(number);
    } while (res < 0);
    
    printf("MAX sum: %d", res);
}

int Sum(char *str)
{
    int sum1 = 0, sum2 = 0, sum = 0, i = 0;

    while (str[i] != '\0' && str[i] != '.')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            printf("invalid input");
            return -1;
        }
        sum1 += str[i] - '0';
        i++;
    }

    i++;
    
    while (str[i])
    {
        if(str[i] < '0' || str[i] > '9')
        {
            printf("invalid input");
            return -1;
        }
        sum2 += str[i] - '0';
        i++;
    }

    sum = (sum1 <= sum2) ? sum2 : sum1;

    return sum;
}
