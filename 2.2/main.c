#include <stdio.h>
#include <math.h>
#include "main.h"

long fact(long x) 
{
    if (x == 0) 
    { 
        return 1; 
    }
    return fact (x - 1) * x;
}

double sinExpansion(double angle, int n)
{
    int i;
    double sum = 0;
  
    for (i = 1; i <= n; i++) 
    {
        sum += (pow(-1, i - 1) * pow(angle, 2 * i - 1) / fact(2 * i - 1));
    }

    return sum;
}

int main(void) 
{
    double error, sinExp, degrees, realSin;
    int n = 1;
    
    printf("Enter angle in radians: ");
    
    while (!scanf(" %lf", &degrees)) 
    {
        printf("Invalid input. Please try again: ");
    }

    realSin = sin(degrees);

    printf("Enter measurement error: ");
    
    while (!scanf(" %lf", &error) && error >= 1 && error <= 0) 
    {
        printf("Invalid input. Please try again: ");
    }

    do
    {
        sinExp = sinExpansion(degrees, n);
		n++;
    } while (abs(sinExp - realSin) > error);
    
    printf("n: %d", n);
}
