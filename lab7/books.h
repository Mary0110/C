#include <stdlib.h>
#include <stdio.h>

static char* enumStringsst[] = {"borrowed", "in stock"};
typedef enum status
{
    borrowed,
    inStock
}status_t;

typedef struct date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
}date_t;

typedef struct book
{
    char author[20];
    char bookName[20];
    float price;
    status_t status;
    char remarks[20];
    date_t returnDate;
}book_t;

typedef struct bookNode
{
    book_t book;
    struct bookNode* next;
    struct bookNode* prev;
}bookNode_t;

typedef struct bookList
{
    struct bookNode* head;
    struct bookNode* tail;
    size_t size;
}bookList_t;
bookList_t* readBookList(const char* filename);

void reverse(char* s);
char* itoa(int n, char s[]);
int addBook (bookList_t* lib, bookNode_t* book);
int deleteBook(bookList_t** lib, bookNode_t* del);
int count(bookList_t* list);
float overallPrice(bookList_t* list);
int countBorrowed(bookList_t* list);
int searchBookInput(bookNode_t* current, bookList_t* lib);
int print_list(bookList_t* list, FILE* file);
bookNode_t* searchBook(bookList_t* List, const char *name);


