#include <stdio.h>
#include "main.h"

void change(char* str, int size, int strnum)
{
    char temp;
    int j, k;
    
    for(j = 0; j < strnum; j++)
    {
        temp = str[size];
        for(k = size; k >= 1; k--)
        {
            str[k] = str[k - 1];
        }
        str[0] = temp;
    }
}


int main(void)
{
    char str[20];
   
    int size = 0, strnum = 0; 

    FILE* fin;
    fin = fopen("data.txt", "r");
    if (!fin)
    { 
        printf("File does not exist.");
        return 1;
    }

    for (size = 0; (str[size] = fgetc(fin)) != EOF; size++) 
    {
        if (str[size] == '\n' || str[size] == EOF) 
        {
            size--;
            strnum++;
            change(str, size, strnum);
            printf("%s\n", str);
            size = -1;
        }
    }

    fclose(fin);

    return 0;
}
