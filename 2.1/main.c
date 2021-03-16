#include <stdio.h>
#include <math.h>
#include "main.h"

int main(void)
{
    float radius = 0, angle = 0;
    int opt = 0;
    int endApp = 0;

    
    printf("Circle calculator program\n");
    printf("----------------------------\n");

    printf("Enter circle radius:\t");

    while(! scanf(" %f", &radius))
    {
        printf("Invalid input. Please try again: \t");
    }

    printf("Circle radius excepted\n");
    while(!endApp)
    {   

        printf("Choose option:\n");
        printf("\t 1 - circle area \n");
        printf("\t 2 - sector area  \n");
        printf("\t 3 - length of circumference  \n");
        printf("\t 4 - inscribed square side \n");
        printf("\t 5 - cone volume \n ");
        printf("\t 6 - author and version \n");
        printf("\t 7 - exit \n");

        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
                printf("Area = %.2f \n", area(radius));
                break;
            case 2:
                printf("Enter angle in radians:\t");
                scanf("%f", &angle);
                printf("Sector area: %.2f \n", sector(radius, angle));
                break;
            case 3:
                printf("Circumference length: %.2f \n", circumf(radius));
                break;
            case 4:
                printf("Square side: %.2f \n", square(radius));
                break;
            case 5:
                printf("cone volume: %.2f \n", cone(radius));
                break;
            case 6:
                printf("Version: 1.1. Author: M.R.\n");
                break;
            case 7:
                endApp = 1;
                break;
        }
    }
    printf("-----------------------\n");
}

float area(float rad)
{
    const float pi = 3.14;
    float ar = pi * pow(rad, 2);
    return ar;
}

float sector(float rad, float a)
{
    float ar = 0;
    ar = a / 2 * pow(rad, 2);
    return ar;
}

float circumf(float rad)
{
    const float pi = 3.14;
    float length = 2 * pi * rad;
    return length;
}
float square(float rad)
{
    float side = 2 * rad / sqrt(2);
    return side;
} 
float cone(float rad)
{
    const float pi = 3.14;
    float volume = pi * pow(rad, 3) / 3;
    return volume;    
}