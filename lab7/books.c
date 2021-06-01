
#include "books.h"
#include <stdlib.h>
#include <string.h>

 void reverse(char* s)
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) 
     {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

char* itoa(int n, char s[])
{
     int i, sign;
 
     if ((sign = n) < 0)  /* записываем знак */
         n = -n;          /* делаем n положительным числом */
     i = 0;
     do {       /* генерируем цифры в обратном порядке */
         s[i++] = n % 10 + '0';   /* берем следующую цифру */
     } while ((n /= 10) > 0);     /* удаляем */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
    return s;
}

int addBook (bookList_t* lib, bookNode_t* book)
{        
    book->next = lib->head;
    book->prev = NULL;
    if(lib->head)
    {
        lib->head->prev = book;
    }
    lib->head = book;
    return 0;
}

int deleteBook(bookList_t** lib, bookNode_t* del)
{
    if(*lib == NULL || del == NULL)
        return 0;

    if((*lib)->head == del)
        (*lib)->head = del->next;

    if (del->next != NULL)
       del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return 0;
}

int count(bookList_t* list)
{
    int count = 0;
    bookNode_t* temp = list->head;
    while(temp)
    {        
        count++;
        temp = temp->next;
    }
    return count;
}

float overallPrice(bookList_t* list)
{
    float count = 0;
    bookNode_t* temp = list->head;
    while(temp)
    {
        count += temp->book.price;
        temp = temp->next;
    }
    return count;
}


int countBorrowed(bookList_t* list)
{
    int count = 0;
    bookNode_t* temp = list->head;
    while(temp)
    {  
        if(temp->book.status == 0)      
            count++;
        temp = temp->next;
    }
    return count;
}

bookNode_t* searchBook(bookList_t* List, const char *name)
{
    bookNode_t* temp = List->head;
    while(temp)
    {
        if(strcmp(temp->book.bookName, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

bookList_t* readBookList(const char* filename)
{
    FILE* file;
    char price[20]; char st[20];
    bookList_t *temp = (bookList_t*) malloc(sizeof(bookList_t));
    if (temp == NULL)
        exit(1);
    temp->size = 0;
    temp->head = temp->tail = NULL;
     file =fopen( filename, "r");
    if (!file)
        exit(1);
    while(!feof(file))
    {
        bookNode_t* book = (bookNode_t*)malloc(sizeof(bookNode_t*));
        if (!book)
            exit(1);
        fgets(book->book.bookName, 19, file);
        fgets(book->book.author, 19, file);
        
        fgets( price, 19, file);
        book->book.price = atof(price);
        fgets(st, 19, file);
        if (strcmp(st, "inStock"))
            book->book.status = 0;
        else
            book->book.status = 1;
        fgets(book->book.remarks, 19, file);
        fgets(price, 2, file);book->book.returnDate.day = atoi(price);
        fgets(price, 2, file);book->book.returnDate.month = atoi(price);
        fgets(price, 2, file);book->book.returnDate.year = atoi(price);
        addBook(temp, book);
    }
    printf("read");
    fclose(file);
    return temp;
}

int print_list(bookList_t* list, FILE* file) 
{
    char price[20] ;
    bookNode_t* node = list->head;
    size_t count;
    for (count = 0; count < list->size; ++count) 
    {
        book_t book = node->book;
        fputs(book.bookName, file);
        fputs(book.author, file);
        sprintf(price, "%f", book.price);
        fputs(price, file); 
        fputs(enumStringsst[book.status], file);
        itoa(book.returnDate.day, price);
        fputs(price, file); 
        itoa(book.returnDate.month, price); 
        fputs(price, file);
        itoa(book.returnDate.year, price);
        fputs(price, file);
       
        fputs(book.remarks, file);

        if (count < list->size - 1) 
        {
            fputs("\t", file);
        }
        node = node->next;
    }
    return 0;
}






