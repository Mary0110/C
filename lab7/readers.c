#include "readers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

readerList_t* readReaderList(const char* filename)
{
    
    char buffer[20];
    FILE* file;readerList_t *temp;
    temp = (readerList_t*) malloc(sizeof(readerList_t));
    if (temp != NULL) 
    {
        printf("aloc");
        temp->size = 0;
        temp->head = temp->tail = NULL;
    }

     file=fopen(filename, "r");
    if (file == NULL)
        exit(1);

        while (!feof(file))
        {
            readerNode_t* newReader = (readerNode_t*)malloc(sizeof(readerNode_t));
            if (!newReader)
                exit(1);
            newReader->reader.borrowedList.head = newReader->reader.borrowedList.tail = NULL;
            newReader->reader.borrowedList.size = 0;
            fgets(newReader->reader.name, 19, file);
            fgets(newReader->reader.surname, 19, file);
            
            fgets(buffer, 6, file);newReader->reader.groupNumber = atoi(buffer);
            fgets(buffer, 19, file);newReader->reader.phoneNumber = atoi(buffer);
            fgets(newReader->reader.email, 19, file);
            while (getc(file) != '\n' && !feof(file)) 
            {
                bookNode_t* book = (bookNode_t*)malloc(sizeof(bookNode_t*));
                if (!book)
                    exit(1);
                fgets(book->book.bookName, 19, file);
                fgets(book->book.author, 19, file);

                fgets(buffer, 19, file);
                book->book.price = atof(buffer);
                fgets(buffer, 19, file);
                if (strcmp(buffer, "inStock"))
                    book->book.status = 0;
                else
                    book->book.status = 1;
                fgets(book->book.remarks, 19, file);
                fgets(buffer, 2, file);book->book.returnDate.day = atoi(buffer);
                fgets(buffer, 2, file);book->book.returnDate.month = atoi(buffer);
                fgets(buffer, 2, file);book->book.returnDate.year = atoi(buffer);
                addBook(&newReader->reader.borrowedList, book);
            }
            addReader(temp, newReader);
        }
    fclose(file);
    return temp;
}

int deleteReaderList(readerList_t **list) 
{
    readerNode_t *temp = (*list)->head;
    readerNode_t *next = NULL;
    while (temp)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(*list);
    (*list) = NULL;
    return 0;
}

int addReader(readerList_t* readerList, readerNode_t* reader)
{
    reader->next = readerList->head;
    reader->prev = NULL;
    if(readerList->head)
    {
        readerList->head->prev = reader;
    }
    readerList->head = reader;
    return 0;
}

int deleteReader(readerList_t** list, readerNode_t* del) 
{
    if(*list == NULL || del == NULL)
        return 0;

    if((*list)->head == del)
        (*list)->head = del->next;

    if (del->next != NULL)
       del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return 0;
}

readerNode_t* searchReader(readerList_t* readerList, unsigned int phNum)
{
    readerNode_t* temp = readerList->head;
    while(temp)
    {
        if(temp->reader.phoneNumber == phNum)
            return temp;
        temp = temp->next;
    }
    printf("the reader is not found");
    return temp;
}

int giveOutBook(reader_t reader, bookNode_t* node, unsigned short day, unsigned short month, unsigned short year)
{
    node->book.status = borrowed;
    node->book.returnDate.day = day;
    node->book.returnDate.month = month;
    node->book.returnDate.year = year;
    addBook(&reader.borrowedList, node); 
    return 0;
}

int returnBook(reader_t* reader, bookNode_t* node)
{
    bookList_t* l ;
    node->book.status = inStock;
    node->book.returnDate.day = 0;
    node->book.returnDate.month = 0;
    node->book.returnDate.year = 0;
    l = &reader->borrowedList;
    deleteBook(&l, node);
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

int print_readers(readerList_t* list, FILE* file) 
{
    char buffer[20];
    bookList_t* templist; reader_t* book ;
    readerNode_t* node = list->head;
    size_t count;
    for (count = 0; count < list->size; ++count)
    {
         book = &node->reader;
        fputs(book->name, file);
        fputs(book->surname, file);
        fputs(itoa(book->groupNumber, buffer), file);
        fputs(itoa(book->phoneNumber, buffer), file);
        fputs(book->email, file);
        fputs(enumStr[book->card], file);

        templist = &book->borrowedList;
        print_list(templist, file);
        if (count < list->size - 1)
        {
            fputs("\n\n", file);
        }
        node = node->next;
    }
    return 0;
}
