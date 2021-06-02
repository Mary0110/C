
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

/*char* itoa(int n, char s[])
{
     int i, sign;
 
     if ((sign = n) < 0)  /* записываем знак 
         n = -n;          /* делаем n положительным числом 
     i = 0;
     do {       /* генерируем цифры в обратном порядке 
         s[i++] = n % 10 + '0';   /* берем следующую цифру 
     } while ((n /= 10) > 0);     /* удаляем 
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
    return s;
}*/

int addBook (bookList_t* list, book_t* book)
{     
        bookNode_t* new_node = (bookNode_t*)malloc(sizeof(bookNode_t));
    if(new_node == NULL)
    exit(1);
    new_node->prev = list->tail;
    new_node->next = NULL;
    new_node->book = book;
    if (list->size == 0) 
    {
        list->head = list->tail = new_node;
    }
    else 
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    ++list->size;
    return 0;
}

int deleteBook(bookList_t* list, bookNode_t* del)
{
    bookNode_t* node = list->head;
    while (node != NULL) 
    {
        if (node->book == del->book) 
        {
            if (node == list->head) 
            {
                list->head = list->head->next;
                if (list->head != NULL) 
                {
                    list->head->prev = NULL;
                }     
            }
            else if (node == list->tail) 
            {
                list->tail = list->tail->prev;
                list->tail->next = NULL;
            }
            else {
                node->next->prev = node->prev;
                node->prev->next = node->next;
            }
            free(node);
            --list->size;
            return;
        }
        node = node->next;
    }
    return 0;
}

int count(bookList_t* list)
{
    return list->size;
}


int countBorrowed(bookList_t* list)
{
    int count = 0;
    bookNode_t* temp = list->head;
    while(temp)
    {  
        if(temp->book->status == 0)      
            count++;
        temp = temp->next;
    }
    return count;
}

book_t* searchBook(bookList_t* List, char name[20])
{
    bookNode_t* temp = List->head;
    while(temp)
    {
        puts(temp->book->bookName);
        if(strcmp(temp->book->bookName, name) == 0)
            return temp->book;
        temp = temp->next;
    }
    puts("book is not found");
    return NULL;
}

bookList_t* readBookList(const char* filename)
{
    FILE* file;
    char buffer[20]; char st[20];

    bookList_t *temp = (bookList_t*)malloc(sizeof(bookList_t));
    if (temp == NULL)
        exit(1);
    temp->size = 0;
    temp->head = temp->tail = NULL;

     file =fopen( filename, "r");
    if (!file)
        exit(1);
    while(!feof(file))
    {
        book_t* book = (book_t*)malloc(sizeof(book_t));
        if (!book)
            exit(1);
        fgets(book->bookName, 20, file);
        printf("%s", book->bookName);
        fgets(book->author, 20, file);
                printf("%s", book->author);

        fgets(book->price  , 20, file);
        
                printf("%s", book->price);

        fgets(st, 20, file);
        if (strcmp(st, "inStock") == 0)
            book->status = 0;
        else
            book->status = 1;
                    printf("%s", st);

        fgets(book->remarks, 20, file);
                printf("%s", book->remarks);

        fgets(book->returnDate.day, 3, file);
                printf("%s", book->returnDate.day);

        fgets (book->returnDate.month, 3, file);
                printf("%s", book->returnDate.month);

        fgets(book->returnDate.year, 3, file); 
                printf("%s", book->returnDate.year);

        addBook(temp, book);
    }
    puts("list is read");
    fclose(file);
    return temp;
}
/*
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
}*/






