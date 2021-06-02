#include "books.h"
static char* enumStr[] = { "no", "yellow", "red" };
typedef enum penaltyCard
{
    no,
    yellow,
    red
}penaltyCard_t;

typedef struct reader
{
    char surname[20];
    char name[20];
    char groupNumber[20];
    char phoneNumber[20];
    char email[20];
    penaltyCard_t card;
    char remarks[20];
    bookList_t borrowedList;
}reader_t;

typedef struct readerNode
{
    reader_t* reader;
    struct readerNode* next;
    struct readerNode* prev;     
}readerNode_t;


typedef struct readerList
{
    readerNode_t* head;
    readerNode_t* tail;
    unsigned int size;
}readerList_t;

readerList_t* readReaderList(const char* filename);
int deleteReaderList(readerList_t **list) ;
int addReader(readerList_t* readerList, reader_t* reader);
int deleteReader(readerList_t* list, readerNode_t* del) ;
reader_t* searchReader(readerList_t* readerList, char* phNum);
int print_readers(readerList_t* list, FILE* file);

int giveOutBook(reader_t* reader, book_t* node, char day[20], char month[20], char year[20]);
int returnBook(reader_t* reader, bookNode_t* node);
int fineReader(reader_t* reader, penaltyCard_t card);
int countReaders(readerList_t* list);


