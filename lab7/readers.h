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
    unsigned int groupNumber;
    unsigned int phoneNumber;
    char email[20];
    penaltyCard_t card;
    char remarks[20];
    bookList_t borrowedList;
}reader_t;

typedef struct readerNode
{
    reader_t reader;
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
int addReader(readerList_t* readerList, readerNode_t* reader);
int deleteReader(readerList_t** list, readerNode_t* del) ;
readerNode_t* searchReader(readerList_t* readerList, unsigned int phNum);
int print_readers(readerList_t* list, FILE* file);
int searchReaderInput(readerNode_t* current, readerList_t* readers);
int giveOutBook(reader_t reader, bookNode_t* node, unsigned short day, unsigned short month, unsigned short year);
int returnBook(reader_t* reader, bookNode_t* node);
int fineReader(reader_t* reader, penaltyCard_t card);
int countReaders(readerList_t* list);


