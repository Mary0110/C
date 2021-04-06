#include <stdio.h>

void addToOutput(char* output, char* input, int size, int len)
{
    int j;
    for(j = 0 ; j < size; j++)
    {
        output[j + len] = input[j];   
    } 
    output[j + len] = ' ';  
}

int checkWord(char* input, int size)
{
    int i;
    
    for (i = 1; i < size; i++)
    {
        if (input[i] < input[i - 1] )
            break;
    }
    if (i == size)
        return 1;
    else
        return 0;
}

int isLetter(char c)
{
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

void printResult(char* output)
{
    int i;
    printf("Result: ");
    for(i = 0; output[i]; i++)
    {
        printf("%c", output[i]);
    }
}

int main(void)
{
    char input[20];
     int size = 0, len = 0;
     int c;
     char output[20];
     printf("Enter text \n");
     
     while ((c = getchar()) != EOF) 
     {
         if (c == ' ' || c == '\n')
         {
            input[size] = c;
            if (checkWord(input, size))
            {
                addToOutput(output, input, size, len);
                len += size + 1;
            }
            size = 0;
         }
         else if (isLetter(c)) 
         {
             input[size] = c;
             size++;
         }
    }
    if(checkWord(input, size + 1) && input[size] != ' ')
    {
        addToOutput(output, input, size, len);
    }
    printResult(output);
}



