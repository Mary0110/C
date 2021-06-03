
#include "books.h"
#include <stdlib.h>
#include <string.h>

int addBook (bookList_t* readerList, book_t* book)
{     
        bookNode_t* node = (bookNode_t*)malloc(sizeof(bookNode_t));
    if(node == NULL)
        exit(1);

    node->next = readerList->head;
    node->prev = NULL;
    if(readerList->head)
    {
        readerList->head->prev = node;
    }
    readerList->head = node; 
    node->book = book;
    return 0;
}
int deleteBook(bookList_t* list, bookNode_t* del) 
{
    if(list == NULL || del == NULL)
        return 0;

    if((list)->head == del)
        (list)->head = del->next;

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

bookNode_t* searchBook(bookList_t* List, char* name)
{
    bookNode_t* temp = List->head;
    while(temp)
    {
        if(strcmp(temp->book->bookName, name) == 0)
            return temp;
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
        fgets(book->author, 20, file);
        fgets(book->price  , 20, file);
        fgets(st, 20, file);
            printf("sttring%s", st);
        strcpy(buffer, "inStock\n\0");
        if (strcmp(st, buffer) == 0)
            book->status = 1;
        else
            book->status = 0;
        fgets(book->remarks, 20, file);
        fgets(book->returnDate.day, 20, file);
        fgets (book->returnDate.month, 20, file);
        fgets(book->returnDate.year, 20, file); 
       addBook(temp, book);
    }
    puts("list is read");
    fclose(file);
    return temp;
}
