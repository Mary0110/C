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
    char day[20];
    char month[20];
    char year[20];
}date_t;

typedef struct book
{
    char author[20];
    char bookName[20];
    char price[20];
    status_t status;
    char remarks[20];
    date_t returnDate;
}book_t;

typedef struct bookNode
{
    book_t* book;
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
/*char* itoa(int n, char s[]);*/
int addBook (bookList_t* lib, book_t* book);
int deleteBook(bookList_t* lib, bookNode_t* del);
int count(bookList_t* list);
float overallPrice(bookList_t* list);
int countBorrowed(bookList_t* list);
int print_list(bookList_t* list, FILE* file);
book_t* searchBook(bookList_t* List,  char name[20]);


