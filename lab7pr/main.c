#include <stdio.h>
#include <stdlib.h>
#include "readers.h"
#include<string.h>

int searchReaderInput(readerNode_t** current, readerList_t* readers);
int searchBookInput(bookNode_t** current, bookList_t* lib);

int main(void)
{
    int endApp = 0;
    char opt; float num; int f = 0, o = 0, o1 = 0; char ush[20], day[20], month[20], year[20];
    char str[20];
    
    FILE* outputFile = NULL, *outputFile2 = NULL;
    bookList_t* library;
    readerList_t* readers; 
    library = readBookList("lib.txt");
    readers = readReaderList("readers.txt");
    while (!endApp)
    {
        puts("LIBRARY");
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
        printf("\t * - exit\n");

        do {
            char c;
            opt = getchar();
            while ((c = getchar()) != '\n') {}
        } while (opt < '1' || opt > '9' || opt =='*');
        switch (opt)
        {
        case'1':
        {
            int f = 0; char str[20];
                float num;
            book_t* newBook = (book_t*)malloc(sizeof(book_t));
            if (newBook == NULL)
                exit(1);
                
            puts("Enter name of new book: \n");
            fgets(newBook->bookName,  20, stdin);
            puts("Enter author of new book: \n");
            fgets(newBook->author, 20, stdin);
            puts("price:");
            fgets(newBook->price, 20, stdin);
            puts("Add remarks to new book: \n");
            fgets(newBook->remarks, 20, stdin);
            newBook->status = 1;
            strcpy(  newBook->returnDate.day , "0");
              strcpy(newBook->returnDate.month, "0");
               strcpy(  newBook->returnDate.year, "0");
           
            addBook(library, newBook);
        
    }
    break;
    case '2':
    {
        book_t* newBook; bookNode_t* b;
        char str[20]; char name[20];
        puts("Enter name of book to copy:\n");
        newBook = (book_t*)malloc(sizeof(book_t));
        if(newBook == NULL)
            exit(1);
        
        fgets(name, 20, stdin);
        b = searchBook(library, name);
        while ( b == NULL)
        {
            puts("book is not found. try again:\n");
            fgets(name, 20, stdin);
            b = searchBook(library, name);
        }
            strcpy(newBook->bookName,  b->book->bookName);
            strcpy(newBook->author , b->book->author);
            strcpy( newBook->price , b->book->price);
            newBook->status = 0;
            strcpy(  newBook->returnDate.day , "0");
            strcpy(newBook->returnDate.month, "0");
            strcpy(  newBook->returnDate.year, "0");
            addBook(library, newBook);
            puts("book is copied and added to the library");
    }
        break;
    case '3':
        {
            int f = 0; char str[20];
            float num;
            bookList_t* library;
            reader_t* newReader = (reader_t*)malloc(sizeof(reader_t));
            if(newReader==NULL)
                exit(1);
            newReader->borrowedList.head = newReader->borrowedList.tail = NULL;
            newReader->borrowedList.size = 0;
            
            puts("Enter name of new reader: \n");
            fgets(newReader->name, 20, stdin); 
            puts("Enter surname: \n");
            fgets(newReader->surname, 20, stdin);
            puts("Enter group number: \n");
            fgets(newReader->groupNumber, 20, stdin);
            puts("Enter phone number: \n");
            fgets(newReader->groupNumber, 20, stdin); 
            puts("Enter email of new reader: \n");
            fgets(newReader->email, 20, stdin);
            newReader->card =0;
            puts("Add remarks: \n");
            fgets(newReader->remarks, 20, stdin);
            addReader(readers, newReader);
        }
        break;
        case '4':
        {
            puts("Choose 1 for editing book info, 2 for editing reader info\n");
            do {
            char c;
            opt = getchar();
            while ((c = getchar()) != '\n') {}
        } while (!(opt == '1' || opt == '2'));
            switch (opt)
            {
            case '1':
            {
                int f = 0; char name[20];
                float num;
                bookNode_t* newBook = NULL;
                
                puts("Enter name of a book: ");
                fgets(name, 20, stdin);
                newBook = searchBook(library, name);
                printf("equal");
                while (newBook->book == NULL)
                {
                    puts("Invalid input. Enter name of a book again:");
                    fgets(name, 20, stdin);
                    newBook = searchBook(library, name);
                }
                
                puts("Enter name of new book: ");
                fgets(newBook->book->bookName, 20,stdin);
                puts("Enter author of new book: ");
                fgets(newBook->book->author, 20, stdin);
                puts("price:");
                fgets(newBook->book->price, 20, stdin);
                puts("Add remarks to new book: \n");
                fgets(newBook->book->remarks, 20 , stdin);
                newBook->book->status = inStock;
                strcpy(  newBook->book->returnDate.day , "0");
                strcpy(newBook->book->returnDate.month, "0");
                strcpy(  newBook->book->returnDate.year, "0");
           
            }
            break;
            case '2':
            {
                int f = 0; char str[20];
                float num;
                readerNode_t* newReader = NULL;
                char ush[20];
                
                puts("enter the surname of a reader");
                fgets(ush, 19, stdin);
                newReader = searchReader(readers, ush);
                while (newReader == NULL)
                {
                    puts("Invalid input. Enter phone number of a person:");
                    fgets(ush, 8, stdin);

                    newReader = searchReader(readers, ush);
                }
                
                puts("Enter name of new reader:\n");
                fgets(newReader->reader->name, 19 , stdin);
                puts("Enter surname: ");
                fgets(newReader->reader->surname, 19, stdin);
                puts("Enter group number: ");
                fgets(newReader->reader->groupNumber, 7, stdin);
                puts("Enter phone number: ");
                fgets(newReader->reader->phoneNumber, 8, stdin);
                puts("Enter email of new reader: ");
                fgets(newReader->reader->email, 19, stdin);
                newReader->reader->card = 0;
                puts("Add remarks: ");
                fgets(newReader->reader->remarks, 19, stdin);
             }
            break;
            }
        }
        break;
        case '5':
        {
            puts("Choose 1 for removing book, 2 for removing reader");
            
        do {
            char c;
            opt = getchar();
            while ((c = getchar()) != '\n') {}
          } while (!(opt == '1' || opt == '2'));
            switch (opt)
            {
            case '1':
            {
                bookNode_t* current = NULL;
                searchBookInput(&current, library);
                deleteBook(library, current);
            }
            break;
            case '2':
            {
                readerNode_t* current = NULL;
                searchReaderInput(&current, readers);
                deleteReader(readers, current);
            }
            break;
            }
        }
        break;
        case '6':
        {
            readerNode_t* current = NULL; bookNode_t* b = NULL;
            searchReaderInput(&current, readers);
            searchBookInput(&b, library);
            puts("enter day:");
            fgets(day, 3, stdin);
            puts("enter month:");
            fgets(month, 3, stdin);
            puts("enter year:");
            fgets(year, 3, stdin);
            giveOutBook(current->reader, b->book, day, month, year);
        }
        break;
        case '7':
        {
            readerNode_t* current = NULL;bookNode_t* b = NULL;
            searchReaderInput(&current, readers);
            searchBookInput(&b, library);
            returnBook(current->reader, b);
            puts("book is in stock");
        }
        break;
        case '8':
        {
            readerNode_t* current = NULL;
            searchReaderInput(&current, readers);
            puts("choose card: 1 - yellow, 2 - red");
            do {
                char c;
                opt = getchar();
                while ((c = getchar()) != '\n') {}
            } while (!(opt == '1' || opt == '2'));

            fineReader(current->reader, (int)(opt - '0'));
        }
        break;
        case '9':
        {
            /*The number of books in library*/
            printf("number of books: %d\n", count(library));
            /*The number of borrowed books in library*/
            printf("The number of borrowed books in library: %d\n", countBorrowed(library));
            /*The number of readers in library*/
            printf("the number of readers: %d\n", countReaders(readers));
        }
        break;
        case '*':
        default:
            endApp = 1;
            break;
        }
    }
    printf("-----------------------\n");
    return 0;
}
int searchReaderInput(readerNode_t** current, readerList_t* readers)
{
    char ush[20];
    puts("enter surname of a reader");
    fgets(ush, 19, stdin);
    (*current) = searchReader(readers, ush);
    while ((*current)== NULL)
    {
        puts("Invalid input. Enter surname of a person: ");
        fgets(ush, 19, stdin);
        (*current) = searchReader(readers, ush);
    }
    return 0;
}
int searchBookInput(bookNode_t** current, bookList_t* lib)
{
    char str[20]; char name[20];
    puts("Enter name of a book: ");
    fgets(name, 19, stdin);
    (*current) = searchBook(lib, name);
    while ((*current)->book== NULL)
    {
        puts("Invalid input. Enter name of a book again: ");
        
        fgets(name, 19, stdin);
        (*current) = searchBook(lib, name);
    }
    return 0;
}
