#include <stdio.h>
#include <stdlib.h>
#include "readers.h"
#include<string.h>

int searchReaderInput(readerNode_t* current, readerList_t* readers);
int searchBookInput(bookNode_t* current, bookList_t* lib);
char* receiveInput(char* s);

int main(void)
{
    int endApp = 0;
    int opt; float num; int f = 0, o = 0; unsigned int ush, day, month, year;
    char str[20];
    
    FILE* outputFile = NULL, *outputFile2 = NULL;
    bookList_t* library;
    readerList_t* readers; 
    printf("x;jnj");
    library = readBookList("lib.txt");
     readers = readReaderList("readers.txt");
    while (!endApp)
    {
        printf("LIBRARY");
        printf("Choose option:\n");
        printf("\t 1 - buy new book \n");
        printf("\t 2 - buy a copy of a book \n");
        printf("\t 3 - add new reader\n");
        printf("\t 4 - edit information \n");
        printf("\t 5 - delete \n ");
        printf("\t 6 - give out book\n");
        printf("\t 7 - return book\n");
        printf("\t 8 - fine reader\n");
        printf("\t 9 - report\n");
        printf("\t 10 - exit\n");

        do
        {
            o = scanf("%d", &opt);
            getchar();
        } while (!(o > 0 && o <= 10));

        switch (opt)
        {
        case 1:
        {
            bookNode_t* newBook = (bookNode_t*)malloc(sizeof(bookNode_t));
            if (newBook != NULL)
            {
                int f = 0; char str[20];
                float num;
                printf("Enter name of new book: \n");
               
                strcpy(newBook->book.bookName,  receiveInput(str));
                printf("Enter author of new book: \n");
                strcpy(newBook->book.author, receiveInput(str));
                while (!f)
                {
                    char c[20];
                    printf("Enter price of new book: \n");
                    fgets(c, 19, stdin);
                    num = atof(c);
                    if (num > 0)
                    {
                        newBook->book.price = num;
                        f = 1;
                    }
                    else
                    {
                        printf("Invalid input");
                    }
                }
                printf("Add remarks to new book: \n");
                strcpy(newBook->book.remarks, receiveInput(str));
                newBook->book.status = inStock;
                newBook->book.returnDate.day = 0;
                newBook->book.returnDate.month = 0;
                newBook->book.returnDate.year = 0;
                addBook(library, newBook);
            }
        }
        break;
        case 2:
        {
            bookNode_t* newBook, *b;
            char str[20];
            printf("Enter name of book to copy:\t");
            newBook = (bookNode_t*)malloc(sizeof(bookNode_t));
            b = searchBook(library, receiveInput(str));
            if (newBook && b)
            {
                strcpy(newBook->book.bookName,  b->book.bookName);
                 strcpy(newBook->book.author , b->book.author);
                newBook->book.price = b->book.price;
                newBook->book.status = inStock;
                newBook->book.returnDate.day = 0;
                newBook->book.returnDate.month = 0;
                newBook->book.returnDate.year = 0;
                addBook(library, newBook);
            }
            else
                printf("lib is empty");
        }
        break;
        case 3:
        {
            bookList_t* library;
            readerNode_t* newReader = (readerNode_t*)malloc(sizeof(readerNode_t));
            int f = 0; char str[20];
            float num;
            printf("Enter name of new reader: \n");
            strcpy(newReader->reader.name, receiveInput(str)); 
            printf("Enter surname: \n");
            strcpy(newReader->reader.surname, receiveInput(str));
           
            do
            {
                printf("Enter group number: \n");
            } while (!scanf("%u", &newReader->reader.groupNumber));
            do
            {
                printf("Enter phone number: \n");
            } while (!scanf("%u", &newReader->reader.phoneNumber));
            
            printf("Enter email of new reader: \n");
            strcpy(newReader->reader.email, receiveInput(str));
          
            newReader->reader.card =0;
          
            printf("Add remarks: \n");
            strcpy(newReader->reader.remarks, receiveInput(str));
            
             library = (bookList_t*)malloc(sizeof(bookList_t));
            newReader->reader.borrowedList = *library;
            addReader(readers, newReader);
        }
        break;
        case 4:
        {
            printf("Choose 1 for editing book info, 2 for editing reader info");
            while (!(scanf("%d", &opt) && (opt == 1 || opt == 2)))
            {
                printf("Invalid input");
            }
            switch (opt)
            {
            case(1):
            {
                int f = 0; char str[20];
                float num;
                bookNode_t* newBook = NULL;
                searchBookInput(newBook, library);
                
                if (newBook == NULL)
                    exit(1);

                
                printf("Enter name of new book: \n");
                strcpy(newBook->book.bookName, receiveInput(str));
               
                printf("Enter author of new book: \n");
                strcpy(newBook->book.author, receiveInput(str));
               
                while (!f)
                {
                    char c[20];
                    printf("Enter price of new book: \n");
                    fgets(c, 19, stdin);
                    num = atof(c);
                    if (num > 0)
                    {
                        newBook->book.price = num;
                        f = 1;
                    }
                    else
                    {
                        printf("Invalid input");
                    }
                }
                printf("Add remarks to new book: \n");
                strcpy(newBook->book.remarks, receiveInput(str));
                newBook->book.status = inStock;
                newBook->book.returnDate.day = 0;
                newBook->book.returnDate.month = 0;
                newBook->book.returnDate.year = 0;

            }
            break;
            case(2):
            {
                int f = 0; char str[20];
                float num;
                readerNode_t* newReader = NULL;bookList_t* library;
                searchReaderInput(newReader, readers);
                
                
                printf("Enter name of new reader: \n");
                strcpy(newReader->reader.name, receiveInput(str));
                
                printf("Enter surname: \n");
                strcpy(newReader->reader.surname, receiveInput(str));
            
                do
                {
                    printf("Enter group number: \n");
                } while (!scanf("%u", &newReader->reader.groupNumber));
                do
                {
                    printf("Enter phone number: \n");
                } while (!scanf("%u", &newReader->reader.phoneNumber));

                printf("Enter email of new reader: \n");
                strcpy(newReader->reader.email, receiveInput(str));
         
                newReader->reader.card = 0;

                printf("Add remarks: \n");
                strcpy(newReader->reader.remarks, receiveInput(str));
             
                library = (bookList_t*)malloc(sizeof(bookList_t));
                newReader->reader.borrowedList = *library;
            }
            break;
            }
        }
        break;
        case 5:
        {
            printf("Choose 1 for removing book, 2 for removing reader");
            while (!(scanf("%d", &opt) && (opt == 1 || opt == 2)))
            {
                printf("Invalid input");
            }
            switch (opt)
            {
            case(1):
            {
                bookNode_t* current = NULL;
                searchBookInput(current, library);
                deleteBook(&library, current);
            }
            break;
            case(2):
            {
                readerNode_t* current = NULL;
                searchReaderInput(current, readers);
                deleteReader(&readers, current);
            }
            break;
            }
        }
        break;
        case 6:
        {
            readerNode_t* current = NULL; bookNode_t* b = NULL;
            searchReaderInput(current, readers);
            
            searchBookInput(b, library);
            do
            {
                printf("enter day:");

            } while (!(scanf("%u", &day) && day <= 31));
            do
            {
                printf("enter month:");

            } while (!(scanf("%u", &month) && month <= 12));
            do
            {
                printf("enter year:");

            } while (!(scanf("%u", &year) && year >= 2021));
            giveOutBook(current->reader, b, day, month, year);
        }
        break;
        case 7:
        {
            readerNode_t* current = NULL;bookNode_t* b = NULL;
            searchReaderInput(current, readers);
            
            searchBookInput(b, library);
            returnBook(&current->reader, b);
            printf("book is in stock");
        }
        break;
        case 8:
        {
            readerNode_t* current = NULL;
            searchReaderInput(current, readers);
            printf("choose card: 1 - yellow, 2 - red");
            do
            {
                scanf("%u", &opt);
            } while (!(opt == 1 || opt == 2));

            fineReader(&current->reader, opt);
        }
        break;
        case 9:
        {
            /*The number of books in library:*/
            printf(" %d\n", count(library));
            /*The number of borrowed books in library*/
            printf("The number of borrowed books in library: %d\n", countBorrowed(library));
            /*"Overall price*/
            printf("Overall price: %f\n", overallPrice(library));
            /*The number of readers in library*/
            printf(": %d\n", countReaders(readers));
        }
        break;
        case 10:
        default:
            endApp = 1;
            break;
        }
    }
        outputFile=fopen("output.txt", "w");
        if (outputFile == NULL)
            exit(1);
        print_readers(readers, outputFile);
         outputFile2=fopen("output2.txt", "w");
        if (outputFile2 == NULL)
            exit(1);
        print_list(library, outputFile2);

        printf("-----------------------\n");
        return 0;
}
int searchReaderInput(readerNode_t* current, readerList_t* readers)
{
    unsigned int ush;
    printf("enter the phone number of a reader");
    while (!scanf("%u", &ush))
    {
        printf("invalit input. Try again");
    }
    current = searchReader(readers, ush);
    while (current == NULL)
    {
        printf("Invalid input. Enter phone number of a person: ");
        while (!scanf("%u", &ush))
        {
            printf("invalit input. Try again");
        }
        current = searchReader(readers, ush);
    }
    return 0;
}
int searchBookInput(bookNode_t* current, bookList_t* lib)
{
    char str[20]; char name[20];
    printf("Enter name of a book: ");
    current = searchBook(lib, receiveInput(str));
    while (current == NULL)
    {
        printf("Invalid input. Enter name of a book again: ");
        
        strcpy(name, receiveInput(str));
        current = searchBook(lib, name);
    }
    return 0;
}
char* receiveInput(char* s)
{
    fgets(s, 19,stdin);
    return s;
}
