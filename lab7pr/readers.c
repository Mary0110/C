#include "readers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

readerList_t* readReaderList(const char* filename)
{
    char buffer[20]; char c;
    FILE* file;readerList_t *temp;
    temp = (readerList_t*) malloc(sizeof(readerList_t));
    if (temp != NULL) 
    {
        temp->size = 0;
        temp->head = temp->tail = NULL;
    }

    file=fopen(filename, "r");
    if (file == NULL)
        exit(1);

        while (!feof(file))
        {
            reader_t* newReader = (reader_t*)malloc(sizeof(reader_t));
            if (!newReader)
                exit(1);
            newReader->borrowedList.head = newReader->borrowedList.tail = NULL;
            newReader->borrowedList.size = 0;
            fgets(newReader->name, 20, file);
            fgets(newReader->surname, 20, file);
            fgets(newReader->groupNumber, 20, file); 
            fgets(newReader->phoneNumber, 20, file);
            fgets(newReader->email, 20, file);
            fgets(newReader->remarks, 20, file);
            addReader(temp, newReader);
        }
        puts("readers are read");
    fclose(file);
    return temp;
}

int addReader(readerList_t* readerList, reader_t* r)
{
    readerNode_t* node  = (readerNode_t*)malloc(sizeof(readerNode_t));
    if(node == NULL)
        exit(1);
   
    node->next = readerList->head;
    node->prev = NULL;
    if(readerList->head)
    {
        readerList->head->prev = node;
    }
    readerList->head = node; 
    node->reader = r;
    return 0;
}

int deleteReader(readerList_t* list, readerNode_t* del) 
{
    if(list == NULL || del == NULL)
        return 0;

    if((list)->head == del)
        (list)->head = del->next;

    if (del->next != NULL)
       del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del->reader);
    free(del);
    return 0;
}

readerNode_t* searchReader(readerList_t* readerList, char phNum[20])
{
    readerNode_t* temp = readerList->head;
    while(temp)
    {
        if(strcmp(temp->reader->surname, phNum) == 0)
            return temp;
        temp = temp->next;
    }
    puts("the reader is not found");
    return temp;
}

int giveOutBook(reader_t* reader, book_t* node, char day[20], char month[20], char year[20])
{
    node->status = 0;
    
     strcpy(node->returnDate.day ,day);
     strcpy(node->returnDate.month ,month);
     strcpy(node->returnDate.year , year);
    addBook(&reader->borrowedList, node); 
    return 0;
}

int returnBook(reader_t* reader, bookNode_t* node)
{
    bookList_t* l ;
    node->book->status = 1;
  strcpy( node-> book->returnDate.day , "0");
              strcpy(node->book->returnDate.month, "0");
               strcpy( node-> book->returnDate.year, "0");
           
    l = &reader->borrowedList;
    deleteBook(l, node);
    return 0;
}

int fineReader(reader_t* reader, penaltyCard_t card)
{
    reader->card = card;
    return 0;
}

int countReaders(readerList_t* list)
{
    int count = 0;
    readerNode_t* temp = list->head;
    while(temp)
    {        
        count++;
        temp = temp->next;
    }
    return count;
}