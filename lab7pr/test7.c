#include <assert.h>
#include <stdio.h>
#include "readers.h"
#include <math.h>
#include <string.h>


#undef main
int main(void)
{ 
	char buf[20];
	book_t* book = (book_t*)malloc(sizeof(book_t));
	reader_t* reader = (reader_t*)malloc(sizeof(reader_t));
	assert(book != NULL);
	assert(reader!=NULL);
    assert( readBookList("lib.txt") !=NULL);
    assert(readReaderList("readers.txt") != NULL);

	readerList_t* list =readReaderList("readers.txt");
	bookList_t* blist =  readBookList("lib.txt");

	reader->borrowedList.head = reader->borrowedList.tail = NULL;
	reader->borrowedList.size = 0;
	strcpy(reader->name, "alena");
	strcpy(reader->surname, "poznyakevich");
	strcpy(reader->groupNumber, "053502");
	strcpy(reader->phoneNumber, "5011500");
	reader->card = 0;
	strcpy(reader->remarks, "-");
	reader->card = 0;
	strcpy(reader->email, "sklan@mail,ru");

	strcpy(book->bookName, "sfv");
	strcpy(book->author, "jkdjdn");
	strcpy(book->price, "jkn54");
	strcpy(book->remarks, "-");
	book->status = 0;
	strcpy(book->returnDate.day, "dd");
	strcpy(book->returnDate.month, "mm");
	strcpy(book->returnDate.year, "yy");	
	assert(addReader(list, reader) == 0);
	assert(searchReader(list, "Ivanov")!= NULL);
	assert(deleteReader(list, searchReader(list, "poznyakevich")) == 0); 

	assert(addBook(blist, book) == 0);	
	assert(deleteBook(blist, searchBook(blist, "svf\n")) == 0);
    
	assert(searchBook(blist, "We\n") != NULL);
	assert(giveOutBook(list->head->reader, blist->head->book, "first", "march", "year:2022") == 0);
	assert(returnBook(list->head->reader, blist->head) == 0);
	assert(fineReader(list->head->reader, 1) == 0);
	assert(countReaders(list) == 3);
	assert(count(blist) == 6);
	assert(countBorrowed(blist) == 5);
	printf("tested successfully");
}
