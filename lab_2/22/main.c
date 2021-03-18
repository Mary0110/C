#include <stdio.h>
#include <math.h>
#include "main.h"

int main(void)
{
	double e, angle, res;
	int n = 1;char c, d;
 
    printf("enter angle in radians\t");
    
    while(!(scanf("%lf", &angle) && scanf("%c", &c) && c == '\n'))
    {
        printf("Invalid input. Please try again: \t");   
        fflush(stdin);
    }

    printf("enter possible error\t");
    while(!(scanf("%lf", &e) && scanf("%c", &d) && d == '\n'&& e < 0.1))
    {
        printf("try again\t");
        scanf("%lf", &e);
        fflush(stdin);
    }

	printf("real sine:%lf\n", sin(angle));

	n = sinFirst(angle, e, n);
	printf("\nfirst n: %d", n);

	n = 1;

	n = sinSecond(angle, e, n);
	printf("\nsecond n: %d", n);	
}

unsigned int fact(int num) 
{
	return (num < 2) ? 1 : num * fact(num - 1);
}

int sinFirst(double angle, double e, int n) 
{
	double res = 0;

	while (fabs(sin(angle) - res) > e) 
    {
		res += (pow(-1, n - 1.0) * subFunct(angle, (n * 2) - 1));
		n++;		
	}
	return n;
}

int sinSecond(double angle, double e, int n) 
{
	double res = 0;

	while (fabs(sin(angle) - res) > e)
    {
        int k = (n * 2) - 1;
		res += (pow(-1, n - 1.0) * pow(angle, k) / fact(k));
		n++;
	}

	return n;
}

double subFunct(double angle, int n) 
{
	double res = 1;
	int n0 = 1;

	while (n0 <= n) 
    {
		res *= (angle / n0);
		n0++;
	}
	return res;
}
